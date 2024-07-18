#pragma once
namespace EngineMathLib {
  /**
 * @brief A 3x3 matrix class.
 *
 * This class represents a 3x3 matrix and provides basic matrix operations such as
 * addition, subtraction, multiplication, determinant calculation, and inversion.
 */
  class Matrix3x3 {
  public:
    float m[3][3]; /**< The elements of the matrix. */

    /**
     * @brief Default constructor.
     *
     * Initializes the matrix to the identity matrix.
     */
    Matrix3x3() {
      m[0][0] = 1; m[0][1] = 0; m[0][2] = 0;
      m[1][0] = 0; m[1][1] = 1; m[1][2] = 0;
      m[2][0] = 0; m[2][1] = 0; m[2][2] = 1;
    }

    /**
     * @brief Parameterized constructor.
     *
     * Initializes the matrix with the given values.
     *
     * @param a11 Element at row 1, column 1.
     * @param a12 Element at row 1, column 2.
     * @param a13 Element at row 1, column 3.
     * @param a21 Element at row 2, column 1.
     * @param a22 Element at row 2, column 2.
     * @param a23 Element at row 2, column 3.
     * @param a31 Element at row 3, column 1.
     * @param a32 Element at row 3, column 2.
     * @param a33 Element at row 3, column 3.
     */
    Matrix3x3(float a11, float a12, float a13, float a21, float a22, float a23, float a31, float a32, float a33) {
      m[0][0] = a11; m[0][1] = a12; m[0][2] = a13;
      m[1][0] = a21; m[1][1] = a22; m[1][2] = a23;
      m[2][0] = a31; m[2][1] = a32; m[2][2] = a33;
    }

    /**
     * @brief Adds another matrix to this matrix.
     *
     * @param other The matrix to add.
     * @return The result of the addition.
     */
    Matrix3x3 operator+(const Matrix3x3& other) const {
      return Matrix3x3(
        m[0][0] + other.m[0][0], m[0][1] + other.m[0][1], m[0][2] + other.m[0][2],
        m[1][0] + other.m[1][0], m[1][1] + other.m[1][1], m[1][2] + other.m[1][2],
        m[2][0] + other.m[2][0], m[2][1] + other.m[2][1], m[2][2] + other.m[2][2]
      );
    }

    /**
     * @brief Subtracts another matrix from this matrix.
     *
     * @param other The matrix to subtract.
     * @return The result of the subtraction.
     */
    Matrix3x3 operator-(const Matrix3x3& other) const {
      return Matrix3x3(
        m[0][0] - other.m[0][0], m[0][1] - other.m[0][1], m[0][2] - other.m[0][2],
        m[1][0] - other.m[1][0], m[1][1] - other.m[1][1], m[1][2] - other.m[1][2],
        m[2][0] - other.m[2][0], m[2][1] - other.m[2][1], m[2][2] - other.m[2][2]
      );
    }

    /**
     * @brief Multiplies this matrix by another matrix.
     *
     * @param other The matrix to multiply by.
     * @return The result of the multiplication.
     */
    Matrix3x3 operator*(const Matrix3x3& other) const {
      return Matrix3x3(
        m[0][0] * other.m[0][0] + m[0][1] * other.m[1][0] + m[0][2] * other.m[2][0], m[0][0] * other.m[0][1] + m[0][1] * other.m[1][1] + m[0][2] * other.m[2][1], m[0][0] * other.m[0][2] + m[0][1] * other.m[1][2] + m[0][2] * other.m[2][2],
        m[1][0] * other.m[0][0] + m[1][1] * other.m[1][0] + m[1][2] * other.m[2][0], m[1][0] * other.m[0][1] + m[1][1] * other.m[1][1] + m[1][2] * other.m[2][1], m[1][0] * other.m[0][2] + m[1][1] * other.m[1][2] + m[1][2] * other.m[2][2],
        m[2][0] * other.m[0][0] + m[2][1] * other.m[1][0] + m[2][2] * other.m[2][0], m[2][0] * other.m[0][1] + m[2][1] * other.m[1][1] + m[2][2] * other.m[2][1], m[2][0] * other.m[0][2] + m[2][1] * other.m[1][2] + m[2][2] * other.m[2][2]
      );
    }

    /**
     * @brief Multiplies this matrix by a scalar.
     *
     * @param scalar The scalar to multiply by.
     * @return The result of the multiplication.
     */
    Matrix3x3 operator*(float scalar) const {
      return Matrix3x3(
        m[0][0] * scalar, m[0][1] * scalar, m[0][2] * scalar,
        m[1][0] * scalar, m[1][1] * scalar, m[1][2] * scalar,
        m[2][0] * scalar, m[2][1] * scalar, m[2][2] * scalar
      );
    }

    /**
     * @brief Calculates the determinant of the matrix.
     *
     * @return The determinant of the matrix.
     */
    float determinant() const {
      return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
        - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
        + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
    }

    /**
     * @brief Calculates the inverse of the matrix.
     *
     * @return The inverse of the matrix.
     */
    Matrix3x3 inverse() const {
      float det = determinant();
      if (det == 0) {
        // Handle non-invertible matrix gracefully.
        return Matrix3x3();
      }
      float invDet = 1.0f / det;

      return Matrix3x3(
        (m[1][1] * m[2][2] - m[1][2] * m[2][1]) * invDet,
        (m[0][2] * m[2][1] - m[0][1] * m[2][2]) * invDet,
        (m[0][1] * m[1][2] - m[0][2] * m[1][1]) * invDet,

        (m[1][2] * m[2][0] - m[1][0] * m[2][2]) * invDet,
        (m[0][0] * m[2][2] - m[0][2] * m[2][0]) * invDet,
        (m[0][2] * m[1][0] - m[0][0] * m[1][2]) * invDet,

        (m[1][0] * m[2][1] - m[1][1] * m[2][0]) * invDet,
        (m[0][1] * m[2][0] - m[0][0] * m[2][1]) * invDet,
        (m[0][0] * m[1][1] - m[0][1] * m[1][0]) * invDet
      );
    }
  };
}