/****************************************************************************
 *  File name: Vector3D.cpp
 *  Description:
 *      - An implementation for a simple Vector3D class that contains three values
  
*****************************************************************************/
#include "OEngine.h"
#include "Vector3D.h"
#include "Utils.h"

#include <iostream>

/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

/* Private functions declarations */

/* Public functions definitions   */

Vector3D::Vector3D()
  :Vector2D(0, 0)
  ,z(0)
{

}

Vector3D::Vector3D(float xCoor, float yCoor, float zCoor)
  :Vector2D(xCoor, yCoor)
  ,z(zCoor)
{
  
}

Vector3D& Vector3D::Set(float xCoor, float yCoor, float zCoor)
{
  x = xCoor;
  y = yCoor;
  z = zCoor;
  return *this;
}

Vector3D Vector3D::GetNormal() const
{
  Vector3D temp = *this;
  Utils::Swap(temp.x, temp.y);
  temp.y = -y;
  temp.z = 0;
  return temp;
}

Vector3D& Vector3D::Normalize()
{
  float length = GetLength();
  x = x / length;
  y = y / length;
  z = z / length;
  return *this;
}

Vector3D& Vector3D::operator-()
{
  return Invert();
}

Vector3D Vector3D::operator-(const Vector3D& other) const
{
  Vector3D temp;
  temp.x = this->x - other.x;
  temp.y = this->y - other.y;
  temp.z = this->z - other.z;
  return temp;
}

Vector3D& Vector3D::operator-=(const Vector3D& other)
{
  (*this) = (*this) - other;
  return *this;
}

Vector3D Vector3D::operator+(const Vector3D& other) const
{
  Vector3D temp = (*this);
  temp += other;
  return temp;
}

Vector3D& Vector3D::operator+=(const Vector3D& other)
{
  this->x += other.x;
  this->y += other.y;
  this->z += other.z;
  return *this;
}

Vector3D& Vector3D::operator*()
{
  return Normalize();
}

float Vector3D::operator*(const Vector3D& other) const
{
  return x * other.x + y * other.y + z * other.z;
}

Vector3D Vector3D::operator*(const float& scale) const
{
  Vector3D temp = (*this);
  temp.x *= scale;
  temp.y *= scale;
  temp.z *= scale;
  return temp;
}

Vector3D& Vector3D::operator*=(const float& scale)
{
  (*this) = (*this) * scale;
  return *this;
}

float Vector3D::GetLength() const
{
  return sqrtf(GetLengthSquared());
}

float Vector3D::GetLengthSquared() const
{
  return x*x + y*y + z*z;
}

float Vector3D::DistanceTo(const Vector3D& other) const
{
  return (other - (*this)).GetLength();
}

Vector3D& Vector3D::CalculateFromAngle(float yAxisAngle, float zAxisAngle, AngleUnits units)
{
  return *this;
}


Vector3D& Vector3D::Invert()
{
  x = -x;
  y = -y;
  z = -z;
  return *this;
}


