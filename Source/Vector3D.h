/****************************************************************************
 *  File name: Vector3D.h
 *  Description:
 *      - An interface for a simple Vector3D class that contains three values
  
*****************************************************************************/
#pragma once
#include "Vector2D.h"

/* Constants                      */

/* Enums                          */
enum class VectorAxis
{
  Invalid = -1,
  Xaxis,
  Yaxis,
  Zaxis
};
/* Public classes                 */

class Vector3D : public Vector2D
{
public:
  Vector3D();
  Vector3D(float x, float y, float z);

  Vector3D& Set(float xCoor, float yCoor, float zCoor);
  Vector3D GetNormal()const;
  Vector3D& Normalize();
  Vector3D& operator-();
  Vector3D operator-(const Vector3D& other) const;
  Vector3D& operator-=(const Vector3D& other);
  Vector3D operator+(const Vector3D& other) const;
  Vector3D& operator+=(const Vector3D& other);
  Vector3D& operator*();
  float operator*(const Vector3D& other) const;
  Vector3D operator*(const float& scale) const;
  Vector3D& operator*=(const float& scale);
  float GetLength()const;
  float GetLengthSquared()const;
  float DistanceTo(const Vector3D& other) const;
  Vector3D& CalculateFromAngle(float yAxisAngle, float zAxisAngle, AngleUnits units);
  float ToAngle(AngleUnits units);
  Vector3D CrossProduct(Vector3D& other);

  Vector3D& Invert();
  Vector3D& Rotate(VectorAxis axis, float angle, AngleUnits units);

  float z;
private:
};

/* Public functions declarations  */
