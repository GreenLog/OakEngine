/****************************************************************************
 *  File name: Matrix2D.cpp
 *  Description:
 *      - Contains the definition for the Matrix2D class
  
*****************************************************************************/
#include "OEngine.h"
#include "Matrix2D.h"
#include "assert.h"

#include <iostream>
#include <iomanip>
/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

/* Private functions declarations */

/* Public functions definitions   */


Matrix2D::Matrix2D()
{
  AllocateMatrix();
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (i == j)
      {
        matrix_[i][j] = 1;
        continue;
      }
      matrix_[i][j] = 0;
    }
  }
  
}

Matrix2D::Matrix2D(MatrixTypes type, float x, float y, float z)
{
  
  AllocateMatrix();
  Matrix2D xTemp;
  Matrix2D yTemp;
  Matrix2D zTemp;

  switch (type)
  {
  case MatrixTypes::Identity:
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if (i == j)
        {
          matrix_[i][j] = 1;
          continue;
        }
        matrix_[i][j] = 0;
      }
      return;
    }

    break;
  case MatrixTypes::Rotation:
  {
    if (x)
    {
      xTemp(1, 1) = cosf(x);
      xTemp(1, 2) = sinf(x);
      xTemp(2, 2) = cosf(x);
      xTemp(2, 1) = -sinf(x);
    }

    if (y)
    {
      yTemp(0, 0) = cosf(x);
      yTemp(2, 2) = cosf(x);
      yTemp(2, 0) = sinf(x);
      yTemp(0, 2) = -sinf(x);
    }

    if (z)
    {
      zTemp(0, 0) =  cosf(z);
      zTemp(1, 0) =  -sinf(z);
      zTemp(0, 1) =  sinf(z);
      zTemp(1, 1) =  cosf(z);
    }

     Matrix2D temp = (zTemp * xTemp);
     Matrix2D secondtemp = temp * yTemp;

    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        matrix_[i][j] = secondtemp(i, j);
      }
      return;
    }
    break;
  }
  case MatrixTypes::Scaling:

    break;
  case MatrixTypes::Transform:

    break;
  default:
    break;
  }


}

Matrix2D::~Matrix2D()
{
  if (!matrix_)
  {
    return;
  }
  DeallocateMatrix();
}

void Matrix2D::DeallocateMatrix()
{
  if (!matrix_)
  {
    return;
  }

  for (int i = 0; i < 3; i++)
  {
    delete matrix_[i];
  }
  delete[] matrix_;
  matrix_ = NULL;
  std::cout << "Deallocated matrix \n";
}

void Matrix2D::AllocateMatrix()
{
  matrix_ = new float* [3];
  for (int i = 0; i < 3; i++)
  {
    matrix_[i] = new float[3];
  }
  std::cout << "Allocated matrix \n";
}

Matrix2D Matrix2D::operator*(const Matrix2D& other)
{
  Matrix2D temp;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        temp(i, j) = 0;
      }
    }
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        temp(i,j) += matrix_[i][k] * other(k,j);
      }
    }
  }
    

  temp.Print();
  return temp;

}

Matrix2D::Matrix2D(float **array)
{
  matrix_ = array;
}

float& Matrix2D::operator()(int index1, int index2)
{
  if (index1 < 0 || index2 < 0 || index2 >= 3 || index1 >= 3)
  {
    assert(false, "YOU HAVE INPUTTED THE WRONG INDEX. NOW PERISH!");
    return matrix_[0][0];
  }
  return matrix_[index1][index2];
}

float Matrix2D::operator()(int index1, int index2) const
{
  if (index1 < 0 || index2 < 0 || index2 >= 3 || index1 >= 3)
  {
    assert(false, "YOU HAVE INPUTTED THE WRONG INDEX. NOW PERISH!");
    return matrix_[0][0];
  }
  return matrix_[index1][index2];
}

Matrix2D& Matrix2D::operator=(const Matrix2D& other)
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      matrix_[i][j] = other(i, j);
    }
  }
  return *this;
}

void Matrix2D::Print()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      std::cout << std::setw(10) << std::setprecision(3) << matrix_[i][j];
    }
    std::cout << '\n';
    std::cout << '\n';

  }
}

/* Private functions definitions  */

