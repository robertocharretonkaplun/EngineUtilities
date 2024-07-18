#pragma once
#include "EngineMath.h"
namespace EngineMathLib {
  /**
   * @brief A 2D vector class.
   *
   * This class represents a vector in 2-dimensional space and provides
   * basic vector operations such as addition, subtraction, scalar multiplication,
   * and normalization.
   */
  class Vector2 {
  public:
    float x; /**< The x-coordinate of the vector. */
    float y; /**< The y-coordinate of the vector. */

    /**
     * @brief Default constructor.
     *
     * Initializes the vector to (0, 0).
     */
    Vector2() : x(0), y(0) {}

    /**
     * @brief Parameterized constructor.
     *
     * Initializes the vector to the given x and y values.
     *
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     */
    Vector2(float x, float y) : x(x), y(y) {}

    /**
     * @brief Adds another vector to this vector.
     *
     * @param other The vector to add.
     * @return The result of the addition.
     */
    Vector2 operator+(const Vector2& other) const {
      return Vector2(x + other.x, y + other.y);
    }

    /**
     * @brief Subtracts another vector from this vector.
     *
     * @param other The vector to subtract.
     * @return The result of the subtraction.
     */
    Vector2 operator-(const Vector2& other) const {
      return Vector2(x - other.x, y - other.y);
    }

    /**
     * @brief Multiplies this vector by a scalar.
     *
     * @param scalar The scalar to multiply by.
     * @return The result of the multiplication.
     */
    Vector2 operator*(float scalar) const {
      return Vector2(x * scalar, y * scalar);
    }

    /**
     * @brief Calculates the magnitude (length) of the vector.
     *
     * @return The magnitude of the vector.
     */
    float magnitude() const {
      return EngineMathLib::sqrt(x * x + y * y);
    }

    /**
     * @brief Normalizes the vector.
     *
     * @return The normalized vector.
     */
    Vector2 normalize() const {
      float mag = magnitude();
      if (mag == 0) {
        return Vector2(0, 0);
      }
      return Vector2(x / mag, y / mag);
    }
  };
}
