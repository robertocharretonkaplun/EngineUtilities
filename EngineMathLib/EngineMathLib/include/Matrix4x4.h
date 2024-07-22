/*
 * MIT License
 *
 * Copyright (c) 2024 Roberto Charreton
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * In addition, any project or software that uses this library or class must include
 * the following acknowledgment in the credits:
 *
 * "This project uses software developed by Roberto Charreton and Attribute Overload."
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/
#pragma once
namespace EngineUtilities {
  /**
 * @brief A 4x4 matrix class.
 *
 * This class represents a 4x4 matrix and provides basic matrix operations such as
 * addition, subtraction, multiplication, determinant calculation, and inversion.
 */
  class Matrix4x4 {
  public:
    float m[4][4]; /**< The elements of the matrix. */

    // Default constructor initializes to identity matrix
    Matrix4x4() {
      for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
          m[i][j] = (i == j) ? 1.0f : 0.0f;
        }
      }
    }

    /**
     * @brief Default constructor.
     *
     * Initializes the matrix to the identity matrix.
     */
    Matrix4x4() {
      m[0][0] = 1; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
      m[1][0] = 0; m[1][1] = 1; m[1][2] = 0; m[1][3] = 0;
      m[2][0] = 0; m[2][1] = 0; m[2][2] = 1; m[2][3] = 0;
      m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 1;
    }


    /**
     * @brief Parameterized constructor.
     *
     * Initializes the matrix with the given values.
     *
     * @param a11 Element at row 1, column 1.
     * @param a12 Element at row 1, column 2.
     * @param a13 Element at row 1, column 3.
     * @param a14 Element at row 1, column 4.
     * @param a21 Element at row 2, column 1.
     * @param a22 Element at row 2, column 2.
     * @param a23 Element at row 2, column 3.
     * @param a24 Element at row 2, column 4.
     * @param a31 Element at row 3, column 1.
     * @param a32 Element at row 3, column 2.
     * @param a33 Element at row 3, column 3.
     * @param a34 Element at row 3, column 4.
     * @param a41 Element at row 4, column 1.
     * @param a42 Element at row 4, column 2.
     * @param a43 Element at row 4, column 3.
     * @param a44 Element at row 4, column 4.
     */
    Matrix4x4(float a11, float a12, float a13, float a14,
      float a21, float a22, float a23, float a24,
      float a31, float a32, float a33, float a34,
      float a41, float a42, float a43, float a44) {
      m[0][0] = a11; m[0][1] = a12; m[0][2] = a13; m[0][3] = a14;
      m[1][0] = a21; m[1][1] = a22; m[1][2] = a23; m[1][3] = a24;
      m[2][0] = a31; m[2][1] = a32; m[2][2] = a33; m[2][3] = a34;
      m[3][0] = a41; m[3][1] = a42; m[3][2] = a43; m[3][3] = a44;
    }

    // Copy constructor
    Matrix4x4(const Matrix4x4& other) {
      for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
          m[i][j] = other.m[i][j];
        }
      }
    }

    /**
     * @brief Adds another matrix to this matrix.
     *
     * @param other The matrix to add.
     * @return The result of the addition.
     */
    Matrix4x4 operator+(const Matrix4x4& other) const {
      return Matrix4x4(
        m[0][0] + other.m[0][0], m[0][1] + other.m[0][1], m[0][2] + other.m[0][2], m[0][3] + other.m[0][3],
        m[1][0] + other.m[1][0], m[1][1] + other.m[1][1], m[1][2] + other.m[1][2], m[1][3] + other.m[1][3],
        m[2][0] + other.m[2][0], m[2][1] + other.m[2][1], m[2][2] + other.m[2][2], m[2][3] + other.m[2][3],
        m[3][0] + other.m[3][0], m[3][1] + other.m[3][1], m[3][2] + other.m[3][2], m[3][3] + other.m[3][3]
      );
    }

    /**
     * @brief Subtracts another matrix from this matrix.
     *
     * @param other The matrix to subtract.
     * @return The result of the subtraction.
     */
    Matrix4x4 operator-(const Matrix4x4& other) const {
      return Matrix4x4(
        m[0][0] - other.m[0][0], m[0][1] - other.m[0][1], m[0][2] - other.m[0][2], m[0][3] - other.m[0][3],
        m[1][0] - other.m[1][0], m[1][1] - other.m[1][1], m[1][2] - other.m[1][2], m[1][3] - other.m[1][3],
        m[2][0] - other.m[2][0], m[2][1] - other.m[2][1], m[2][2] - other.m[2][2], m[2][3] - other.m[2][3],
        m[3][0] - other.m[3][0], m[3][1] - other.m[3][1], m[3][2] - other.m[3][2], m[3][3] - other.m[3][3]
      );
    }

    /**
     * @brief Multiplies this matrix by another matrix.
     *
     * @param other The matrix to multiply by.
     * @return The result of the multiplication.
     */
    Matrix4x4 operator*(const Matrix4x4& other) const {
      return Matrix4x4(
        m[0][0] * other.m[0][0] + m[0][1] * other.m[1][0] + m[0][2] * other.m[2][0] + m[0][3] * other.m[3][0],
        m[0][0] * other.m[0][1] + m[0][1] * other.m[1][1] + m[0][2] * other.m[2][1] + m[0][3] * other.m[3][1],
        m[0][0] * other.m[0][2] + m[0][1] * other.m[1][2] + m[0][2] * other.m[2][2] + m[0][3] * other.m[3][2],
        m[0][0] * other.m[0][3] + m[0][1] * other.m[1][3] + m[0][2] * other.m[2][3] + m[0][3] * other.m[3][3],

        m[1][0] * other.m[0][0] + m[1][1] * other.m[1][0] + m[1][2] * other.m[2][0] + m[1][3] * other.m[3][0],
        m[1][0] * other.m[0][1] + m[1][1] * other.m[1][1] + m[1][2] * other.m[2][1] + m[1][3] * other.m[3][1],
        m[1][0] * other.m[0][2] + m[1][1] * other.m[1][2] + m[1][2] * other.m[2][2] + m[1][3] * other.m[3][2],
        m[1][0] * other.m[0][3] + m[1][1] * other.m[1][3] + m[1][2] * other.m[2][3] + m[1][3] * other.m[3][3],

        m[2][0] * other.m[0][0] + m[2][1] * other.m[1][0] + m[2][2] * other.m[2][0] + m[2][3] * other.m[3][0],
        m[2][0] * other.m[0][1] + m[2][1] * other.m[1][1] + m[2][2] * other.m[2][1] + m[2][3] * other.m[3][1],
        m[2][0] * other.m[0][2] + m[2][1] * other.m[1][2] + m[2][2] * other.m[2][2] + m[2][3] * other.m[3][2],
        m[2][0] * other.m[0][3] + m[2][1] * other.m[1][3] + m[2][2] * other.m[2][3] + m[2][3] * other.m[3][3],

        m[3][0] * other.m[0][0] + m[3][1] * other.m[1][0] + m[3][2] * other.m[2][0] + m[3][3] * other.m[3][0],
        m[3][0] * other.m[0][1] + m[3][1] * other.m[1][1] + m[3][2] * other.m[2][1] + m[3][3] * other.m[3][1],
        m[3][0] * other.m[0][2] + m[3][1] * other.m[1][2] + m[3][2] * other.m[2][2] + m[3][3] * other.m[3][2],
        m[3][0] * other.m[0][3] + m[3][1] * other.m[1][3] + m[3][2] * other.m[2][3] + m[3][3] * other.m[3][3]
      );
    }

    /**
     * @brief Computes the determinant of the matrix.
     *
     * @return The determinant of the matrix.
     */
    float determinant() const {
      return
        m[0][0] * (
          m[1][1] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) -
          m[1][2] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) +
          m[1][3] * (m[2][1] * m[3][2] - m[2][2] * m[3][1])
          ) -
        m[0][1] * (
          m[1][0] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) -
          m[1][2] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) +
          m[1][3] * (m[2][0] * m[3][2] - m[2][2] * m[3][0])
          ) +
        m[0][2] * (
          m[1][0] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) -
          m[1][1] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) +
          m[1][3] * (m[2][0] * m[3][1] - m[2][1] * m[3][0])
          ) -
        m[0][3] * (
          m[1][0] * (m[2][1] * m[3][2] - m[2][2] * m[3][1]) -
          m[1][1] * (m[2][0] * m[3][2] - m[2][2] * m[3][0]) +
          m[1][2] * (m[2][0] * m[3][1] - m[2][1] * m[3][0])
          );
    }

    /**
     * @brief Computes the inverse of the matrix.
     *
     * @return The inverse of the matrix.
     */
    
    //Matrix4x4 inverse() const {
    //  float det = determinant();
    //  if (det == 0) {
    //    // Return identity matrix for simplicity when the matrix is singular.
    //    return Matrix4x4();
    //  }

    //  float invDet = 1.0f / det;

    //  return Matrix4x4(
    //    (m[1][1] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) -
    //      m[1][2] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) +
    //      m[1][3] * (m[2][1] * m[3][2] - m[2][2] * m[3][1])) * invDet,
    //    -(m[0][1] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) -
    //      m[0][2] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) +
    //      m[0][3] * (m[2][1] * m[3][2] - m[2][2] * m[3][1])) * invDet,
    //    (m[0][1] * (m[1][2] * m[3][3] - m[1][3] * m[3][2]) -
    //      m[0][2] * (m[1][1] * m[3][3] - m[1][3] * m[3][1]) +
    //      m[0][3] * (m[1][1] * m[3][2] - m[1][2] * m[3][1])) * invDet,
    //    -(m[0][1] * (m[1][2] * m[2][3] - m[1][3] * m[2][2]) -
    //      m[0][2] * (m[1][1] * m[2][3] - m[1][3] * m[2][1]) +
    //      m[0][3] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])) * invDet,

    //    -(m[1][0] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) -
    //      m[1][2] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) +
    //      m[1][3] * (m[2][0] * m[3][2] - m[2][2] * m[3][0])) * invDet,
    //    (m[0][0] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) -
    //      m[0][2] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) +
    //      m[0][3] * (m[2][0] * m[3][2] - m[2][2] * m[3][0])) * invDet,
    //    -(m[0][0] * (m[1][2] * m[3][3] - m[1][3] * m[3][2]) -
    //      m[0][2] * (m[1][0] * m[3][3] - m[1][3] * m[3][0]) +
    //      m[0][3] * (m[1][0] * m[3][2] - m[1][2] * m[3][0])) * invDet,
    //    (m[0][0] * (m[1][2] * m[2][3] - m[1][3] * m[2][2]) -
    //      m[0][2] * (m[1][0] * m[2][3] - m[1][3] * m[2][0]) +
    //      m[0][3] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])) * invDet,

    //    (m[1][0] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) -
    //      m[1][1] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) +
    //      m[1][3] * (m[2][0] * m[3][1] - m[2][1] * m[3][0])) * invDet,
    //    -(m[0][0] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) -
    //      m[0][1] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) +
    //      m[0][3] * (m[2][0] * m[3][1] - m[2][1] * m[3][0])) * invDet,
    //    (m[0][0] * (m[1][1] * m[3][3] - m[1][3] * m[3][1]) -
    //      m[0][1] * (m[1][0] * m[3][3] - m[1][3] * m[3][0]) +
    //      m[0][3] * (m[1][0] * m[3][1] - m[1][1] * m[3][0])) * invDet,
    //    -(m[0][0] * (m[1][1] * m[2][3] - m[1][3] * m[2][1]) -
    //      m[0][1] * (m[1][0] * m[2][3] - m[1][3] * m[2][0]) +
    //      m[0][3] * (m[1][0] * m[2][1] - m[1][1] * m[2][0])) * invDet
    //  );
    //}


  };
}