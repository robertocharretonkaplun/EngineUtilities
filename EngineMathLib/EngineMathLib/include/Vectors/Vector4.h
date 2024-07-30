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

#include "Utilities/EngineMath.h"
namespace EngineUtilities {
  /**
 * @brief A 4D vector class.
 *
 * This class represents a vector in 4-dimensional space and provides
 * basic vector operations such as addition, subtraction, scalar multiplication,
 * and normalization.
 */
  class Vector4 {
  public:
    float x; /**< The x-coordinate of the vector. */
    float y; /**< The y-coordinate of the vector. */
    float z; /**< The z-coordinate of the vector. */
    float w; /**< The w-coordinate of the vector. */

    /**
     * @brief Default constructor.
     *
     * Initializes the vector to (0, 0, 0, 0).
     */
    Vector4() : x(0), y(0), z(0), w(0) {}

    /**
     * @brief Parameterized constructor.
     *
     * Initializes the vector to the given x, y, z, and w values.
     *
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @param z The z-coordinate.
     * @param w The w-coordinate.
     */
    Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    /**
     * @brief Adds another vector to this vector.
     *
     * @param other The vector to add.
     * @return The result of the addition.
     */
    Vector4 operator+(const Vector4& other) const {
      return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    /**
     * @brief Subtracts another vector from this vector.
     *
     * @param other The vector to subtract.
     * @return The result of the subtraction.
     */
    Vector4 operator-(const Vector4& other) const {
      return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    /**
     * @brief Multiplies this vector by a scalar.
     *
     * @param scalar The scalar to multiply by.
     * @return The result of the multiplication.
     */
    Vector4 operator*(float scalar) const {
      return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    /**
     * @brief Calculates the magnitude (length) of the vector.
     *
     * @return The magnitude of the vector.
     */
    float magnitude() const {
      return EngineUtilities::sqrt(x * x + y * y + z * z + w * w);
    }

    /**
     * @brief Normalizes the vector.
     *
     * @return The normalized vector.
     */
    Vector4 normalize() const {
      float mag = magnitude();
      if (mag == 0) {
        return Vector4(0, 0, 0, 0);
      }
      return Vector4(x / mag, y / mag, z / mag, w / mag);
    }
  };
}
