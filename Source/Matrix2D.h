/****************************************************************************
 *  File name: Matrix2D.h
 *  Description:
 *      - Contains the declaration for the Matrix2D class

*****************************************************************************/
#pragma once
/* Constants                      */

/* Enums                          */

enum class MatrixTypes
{
  Identity = -1,
  Rotation,
  Scaling,
  Transform,
};

/* Public classes                 */

class Matrix2D
{
public:
  //Default constructor that creates an identity matrix
  Matrix2D();

  //Creates a matrix from a given 3x3 array
  Matrix2D(float **array);

  Matrix2D(MatrixTypes type, float x, float y, float z);
  ~Matrix2D();
  void DeallocateMatrix();
  void AllocateMatrix();
  Matrix2D operator*(const Matrix2D& other);
  float& operator()(int index1, int index2);
  float operator()(int index1, int index2)const;
  Matrix2D& operator=(const Matrix2D& other);
  void Print();
private:
  float** matrix_;

};

/* Public functions declarations  */

