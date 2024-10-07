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
#include "Vector3.h"
namespace EngineUtilities {
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
		 * @brief Equality operator.
		 *
		 * @param other The quaternion to compare with.
		 * @return True if the quaternions are equal, false otherwise.
		 */
		bool operator==(const Quaternion& other) const {
			return (w == other.w && x == other.x && y == other.y && z == other.z);
		}

		/**
		 * @brief Inequality operator.
		 *
		 * @param other The quaternion to compare with.
		 * @return True if the quaternions are not equal, false otherwise.
		 */
		bool operator!=(const Quaternion& other) const {
			return !(*this == other);
		}

		/**
		 * @brief Calculates the magnitude (length) of the quaternion.
		 *
		 * @return The magnitude of the quaternion.
		 */
		float magnitude() const {
			return EngineUtilities::sqrt(w * w + x * x + y * y + z * z);
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

		/**
		 * @brief Returns the conjugate of the quaternion.
		 *
		 * @return The conjugated quaternion.
		 */
		Quaternion conjugate() const {
			return Quaternion(w, -x, -y, -z);
		}

		/**
		 * @brief Returns the inverse of the quaternion.
		 *
		 * @return The inverted quaternion.
		 */
		Quaternion inverse() const {
			float magSquared = w * w + x * x + y * y + z * z;
			if (magSquared == 0) {
				// Handling division by zero
				return Quaternion(1, 0, 0, 0);
			}
			return conjugate() * (1.0f / magSquared);
		}

		/**
		 * @brief Rotates a vector by this quaternion.
		 *
		 * @param v The vector to rotate.
		 * @return The rotated vector.
		 */
		Vector3 rotate(const Vector3& v) const {
			Quaternion qv(0, v.x, v.y, v.z);
			Quaternion result = (*this) * qv * this->inverse();
			return Vector3(result.x, result.y, result.z);
		}

		/**
		 * @brief Constructs a quaternion from an axis and an angle (in radians).
		 *
		 * @param axis The axis of rotation (must be normalized).
		 * @param angle The angle of rotation in radians.
		 * @return The quaternion representing the rotation.
		 */
		static Quaternion fromAxisAngle(const Vector3& axis, float angle) {
			float halfAngle = angle * 0.5f;
			float sinHalfAngle = EngineUtilities::sin(halfAngle);
			return Quaternion(
				EngineUtilities::cos(halfAngle),
				axis.x * sinHalfAngle,
				axis.y * sinHalfAngle,
				axis.z * sinHalfAngle
			);
		}

		/**
		 * @brief Returns a pointer to the quaternion's data.
		 *
		 * @return Pointer to the first element (w, x, y, z).
		 */
		const float* data() const {
			return &w;
		}

		/**
		 * @brief Converts the quaternion to a 4x4 rotation matrix.
		 *
		 * @return The 4x4 matrix representing the rotation.
		 */
		/*Matrix4x4 toMatrix() const {
			Matrix4x4 result;
			result[0][0] = 1 - 2 * (y * y + z * z);
			result[0][1] = 2 * (x * y - z * w);
			result[0][2] = 2 * (x * z + y * w);
			result[1][0] = 2 * (x * y + z * w);
			result[1][1] = 1 - 2 * (x * x + z * z);
			result[1][2] = 2 * (y * z - x * w);
			result[2][0] = 2 * (x * z - y * w);
			result[2][1] = 2 * (y * z + x * w);
			result[2][2] = 1 - 2 * (x * x + y * y);
			result[3][3] = 1;
			return result;
		}*/
	};
}
