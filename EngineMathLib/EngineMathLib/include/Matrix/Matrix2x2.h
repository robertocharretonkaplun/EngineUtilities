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
 * @brief A 2x2 matrix class.
 *
 * This class represents a 2x2 matrix and provides basic matrix operations such as
 * addition, subtraction, multiplication, determinant calculation, and inversion.
 */
  class Matrix2x2 {
  public:
    float m[2][2]; /**< The elements of the matrix. */

    /**
     * @brief Default constructor.
     *
     * Initializes the matrix to the identity matrix.
     */
    Matrix2x2() {
      m[0][0] = 1; m[0][1] = 0;
      m[1][0] = 0; m[1][1] = 1;
    }

    /**
     * @brief Parameterized constructor.
     *
     * Initializes the matrix with the given values.
     *
     * @param a11 Element at row 1, column 1.
     * @param a12 Element at row 1, column 2.
     * @param a21 Element at row 2, column 1.
     * @param a22 Element at row 2, column 2.
     */
    Matrix2x2(float a11, float a12, float a21, float a22) {
      m[0][0] = a11; m[0][1] = a12;
      m[1][0] = a21; m[1][1] = a22;
    }

    /**
     * @brief Adds another matrix to this matrix.
     *
     * @param other The matrix to add.
     * @return The result of the addition.
     */
    Matrix2x2 operator+(const Matrix2x2& other) const {
      return Matrix2x2(
        m[0][0] + other.m[0][0], m[0][1] + other.m[0][1],
        m[1][0] + other.m[1][0], m[1][1] + other.m[1][1]
      );
    }

    /**
     * @brief Subtracts another matrix from this matrix.
     *
     * @param other The matrix to subtract.
     * @return The result of the subtraction.
     */
    Matrix2x2 operator-(const Matrix2x2& other) const {
      return Matrix2x2(
        m[0][0] - other.m[0][0], m[0][1] - other.m[0][1],
        m[1][0] - other.m[1][0], m[1][1] - other.m[1][1]
      );
    }

    /**
     * @brief Multiplies this matrix by another matrix.
     *
     * @param other The matrix to multiply by.
     * @return The result of the multiplication.
     */
    Matrix2x2 operator*(const Matrix2x2& other) const {
      return Matrix2x2(
        m[0][0] * other.m[0][0] + m[0][1] * other.m[1][0], m[0][0] * other.m[0][1] + m[0][1] * other.m[1][1],
        m[1][0] * other.m[0][0] + m[1][1] * other.m[1][0], m[1][0] * other.m[0][1] + m[1][1] * other.m[1][1]
      );
    }

    /**
     * @brief Multiplies this matrix by a scalar.
     *
     * @param scalar The scalar to multiply by.
     * @return The result of the multiplication.
     */
    Matrix2x2 operator*(float scalar) const {
      return Matrix2x2(
        m[0][0] * scalar, m[0][1] * scalar,
        m[1][0] * scalar, m[1][1] * scalar
      );
    }

    /**
     * @brief Calculates the determinant of the matrix.
     *
     * @return The determinant of the matrix.
     */
    float determinant() const {
      return m[0][0] * m[1][1] - m[0][1] * m[1][0];
    }

    /**
     * @brief Calculates the inverse of the matrix.
     *
     * @return The inverse of the matrix.
     */
    Matrix2x2 inverse() const {
      float det = determinant();
      if (det == 0) {
        // Handle non-invertible matrix gracefully.
        return Matrix2x2();
      }
      float invDet = 1.0f / det;
      return Matrix2x2(
        m[1][1] * invDet, -m[0][1] * invDet,
        -m[1][0] * invDet, m[0][0] * invDet
      );
    }
  };
}
