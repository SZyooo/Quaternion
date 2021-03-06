#pragma once
#include <math.h>

struct Vector3
{
	double x, y, z;
	Vector3(double x=0, double y=0, double z=0) :x(x), y(y), z(z) {}
	/// <summary>
	/// return v1??v2
	/// </summary>
	/// <param name="v1"></param>
	/// <param name="v2"></param>
	/// <returns></returns>
	static double Dot(Vector3 v1, Vector3 v2);
	/// <summary>
	/// return v1 ?? v2. Be careful of the order.
	/// </summary>
	/// <param name="v1"></param>
	/// <param name="v2"></param>
	/// <returns></returns>
	static Vector3 Cross(Vector3 v1, Vector3 v2);
	/// <summary>
	/// return v1 + v2
	/// </summary>
	/// <param name="v1"></param>
	/// <param name="v2"></param>
	/// <returns></returns>
	static Vector3 Add(Vector3 v1, Vector3 v2);
	/// <summary>
	/// return v1-v2
	/// </summary>
	/// <param name="v1"></param>
	/// <param name="v2"></param>
	/// <returns></returns>
	static Vector3 Sub(Vector3 v1, Vector3 v2);
	/// <summary>
	/// return factor*this. be careful of that this Quaternion won't be changed
	/// </summary>
	/// <param name="factor"></param>
	/// <returns></returns>
	Vector3 MultiplyReal(double factor);
	/// <summary>
	/// return originVec3 rotate arc_angle in anti-clockwise around axis
	/// </summary>
	/// <param name="originVec3"></param>
	/// <param name="axis"></param>
	/// <param name="arc_angle"></param>
	/// <returns></returns>
	static Vector3 Rotation(Vector3 originVec3, Vector3 axis, double arc_angle);
};

struct Quaternion {
	double real_part;
	Vector3 imaginary_part;
	Quaternion(double r = 0, Vector3 i = Vector3()) :real_part(r), imaginary_part(i) {};
	double Length();
	Quaternion MultiplyReal(double factor);
	Quaternion GetANorm();
	void Normalize();
	Quaternion ConjugateQuaternion();
	Quaternion InverseQuaternion();
	static Quaternion Multiply(Quaternion q1, Quaternion q2);
	static Quaternion AddReal(Quaternion q, double r);
};