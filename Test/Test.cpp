
#include <iostream>
#include "Quaternion.h"
#pragma comment(lib,"QuaternionLib.lib")

#define PI 3.1415926
void printQuaternion(Quaternion q)
{
    std::cout << "(" << q.real_part << "," << q.imaginary_part.x << "," << q.imaginary_part.y << "," << q.imaginary_part.z << ")";
    std::cout << std::endl;
}
void printVector3(Vector3 v)
{
    std::cout << "(" << v.x << "," << v.y << "," << v.z << ")";
    std::cout << std::endl;
}


int main()
{
    std::cout << sin(PI / 6) << std::endl;
    Vector3 v1 = { 1,0,0 };
    Vector3 v2 = { 0,0,1 };
    printVector3(Vector3::Add(v1, v2));
    std::cout << Vector3::Dot(v1, v2) << std::endl;
    printVector3(Vector3::Cross(v1, v2));
    Quaternion q1(0, v1);
    Quaternion q2(0, v2);
    Quaternion res = Quaternion::Multiply(q1, q2);
    printQuaternion(res);
    printQuaternion(Quaternion(0,Vector3(0,3,4)).ConjugateQuaternion());
    printQuaternion(Quaternion(0, Vector3(0, 3, 4)).GetANorm());
    printQuaternion(Quaternion::AddReal(Quaternion(0, Vector3(0, 3, 4)),3));
    printVector3(Vector3::Rotation(Vector3(1,0,0),Vector3(1,1,0),-PI));
}

