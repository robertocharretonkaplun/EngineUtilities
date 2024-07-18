#pragma once

#include "EngineMath.h"
namespace EngineMathLib {
  /**
 * @brief A quaternion class.
 *
 * This class represents a quaternion, providing operations such as addition,
 * subtraction, scalar multiplication, normalization, and quaternion multiplication.
 */
  class Quaternion {
  public:
    float w; /**< The real part of the quaternion. */
    float x; /**< The i component of the quaternion. */
    float y; /**< The j component of the quaternion. */
    float z; /**< The k component of the quaternion. */

    /**
     * @brief Default constructor.
     *
     * Initializes the quaternion to (1, 0, 0, 0).
     */
    Quaternion() : w(1), x(0), y(0), z(0) {}

    /**
     * @brief Parameterized constructor.
     *
     * Initializes the quaternion to the given w, x, y, and z values.
     *
     * @param w The real part.
     * @param x The i component.
     * @param y The j component.
     * @param z The k component.
     */
    Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}

    /**
     * @brief Adds another quaternion to this quaternion.
     *
     * @param other The quaternion to add.
     * @return The result of the addition.
     */
    Quaternion operator+(const Quaternion& other) const {
      return Quaternion(w + other.w, x + other.x, y + other.y, z + other.z);
    }

    /**
     * @brief Subtracts another quaternion from this quaternion.
     *
     * @param other The quaternion to subtract.
     * @return The result of the subtraction.
     */
    Quaternion operator-(const Quaternion& other) const {
      return Quaternion(w - other.w, x - other.x, y - other.y, z - other.z);
    }

    /**
     * @brief Multiplies this quaternion by a scalar.
     *
     * @param scalar The scalar to multiply by.
     * @return The result of the multiplication.
     */
    Quaternion operator*(float scalar) const {
      return Quaternion(w * scalar, x * scalar, y * scalar, z * scalar);
    }

    /**
     * @brief Multiplies this quaternion by another quaternion.
     *
     * @param other The quaternion to multiply by.
     * @return The result of the multiplication.
     */
    Quaternion operator*(const Quaternion& other) const {
      return Quaternion(
        w * other.w - x * other.x - y * other.y - z * other.z,
        w * other.x + x * other.w + y * other.z - z * other.y,
        w * other.y - x * other.z + y * other.w + z * other.x,
        w * other.z + x * other.y - y * other.x + z * other.w
      );
    }

    /**
     * @brief Calculates the magnitude (length) of the quaternion.
     *
     * @return The magnitude of the quaternion.
     */
    float magnitude() const {
      return EngineMathLib::sqrt(w * w + x * x + y * y + z * z);
    }

    /**
     * @brief Normalizes the quaternion.
     *
     * @return The normalized quaternion.
     */
    Quaternion normalize() const {
      float mag = magnitude();
      if (mag == 0) {
        return Quaternion(1, 0, 0, 0);
      }
      return Quaternion(w / mag, x / mag, y / mag, z / mag);
    }
  };
}
