#include "Quaternion.h"
#include "pch.h"

double Vector3::Dot(Vector3 v1, Vector3 v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
Vector3 Vector3::Cross(Vector3 v1, Vector3 v2)
{
	double _x = v1.y * v2.z - v1.z * v2.y;
	double _y = -(v1.x * v2.z - v1.z * v2.x);
	double _z = v1.x * v2.y - v1.y * v2.x;
	return Vector3(_x, _y, _z);
}
Vector3 Vector3::Add(Vector3 v1, Vector3 v2)
{
	return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
Vector3 Vector3::Sub(Vector3 v1, Vector3 v2)
{
	return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
Vector3 Vector3::MultiplyReal(double factor)
{
	double _x = x * factor;
	double _y = y * factor;
	double _z = z * factor;
	return Vector3(_x, _y, _z);
}
Vector3 Vector3::Rotation(Vector3 originVec3, Vector3 axis, double arc_angle)
{
	Quaternion v(0, originVec3);
	Quaternion qAxisNorm = Quaternion(0, axis).GetANorm();
	double sinTheta = sin(arc_angle / 2);
	double cosTheta = cos(arc_angle / 2);
	qAxisNorm = qAxisNorm.MultiplyReal(sinTheta);
	Quaternion p = Quaternion::AddReal(qAxisNorm, cosTheta);
	Quaternion p_conj = p.ConjugateQuaternion();
	Quaternion res_q = Quaternion::Multiply(Quaternion::Multiply(p, v), p_conj);
	return res_q.imaginary_part;
}
double Quaternion::Length() { return sqrt(pow(real_part, 2) + pow(imaginary_part.x, 2) + pow(imaginary_part.y, 2) + pow(imaginary_part.z, 2)); }
Quaternion Quaternion::MultiplyReal(double factor)
{
	return Quaternion(real_part*factor, imaginary_part.MultiplyReal(factor));
}
Quaternion Quaternion::GetANorm()
{
	double len = Length();
	Quaternion q(real_part, imaginary_part);
	q.MultiplyReal(1 / len);
	return q;
}
void Quaternion::Normalize()
{
	double len = Length();
	MultiplyReal(1 / len);
}
Quaternion Quaternion::ConjugateQuaternion()
{
	return Quaternion(real_part, imaginary_part.MultiplyReal(-1));
}
Quaternion Quaternion::InverseQuaternion()
{
	Quaternion res = Quaternion(real_part, imaginary_part).ConjugateQuaternion();
	res.MultiplyReal(1 / pow(Length(), 2));
	return res;
}
Quaternion Quaternion::Multiply(Quaternion q1, Quaternion q2)
{
	Quaternion result = Quaternion();
	result.real_part = q1.real_part * q2.real_part - Vector3::Dot(q1.imaginary_part, q2.imaginary_part);
	Vector3 _v1 = q2.imaginary_part.MultiplyReal(q1.real_part);
	Vector3 _v2 = q1.imaginary_part.MultiplyReal(q2.real_part);
	Vector3 _v3 = Vector3::Cross(q1.imaginary_part, q2.imaginary_part);
	result.imaginary_part = Vector3::Add(result.imaginary_part, _v1);
	result.imaginary_part = Vector3::Add(result.imaginary_part, _v2);
	result.imaginary_part = Vector3::Add(result.imaginary_part, _v3);
	return result;
}
Quaternion Quaternion::AddReal(Quaternion q, double r)
{
	return Quaternion(q.real_part + r, q.imaginary_part);
}