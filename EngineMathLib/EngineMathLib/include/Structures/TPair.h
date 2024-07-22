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
#pragma once
#include <iostream>

	/**
	 * @brief Clase TPair para representar un par de valores.
	 *
	 * La clase TPair almacena un par de valores de tipos específicos. Es similar a std::pair,
	 * pero se ha diseñado para ser simple y adaptable a tus necesidades. Esta clase proporciona
	 * una manera eficiente de manejar pares de datos en tu código.
	 *
	 * @tparam KeyType Tipo del primer valor (clave) del par.
	 * @tparam ValueType Tipo del segundo valor (valor) del par.
	 */
	template <typename KeyType, typename ValueType>
	class TPair {
	public:
		/**
		 * @brief Constructor por defecto que inicializa el par con valores predeterminados.
		 */
		TPair() : Key(KeyType()), Value(ValueType()) {}

		/**
		 * @brief Constructor que inicializa el par con los valores especificados.
		 *
		 * @param InKey Valor para el primer elemento del par (clave).
		 * @param InValue Valor para el segundo elemento del par (valor).
		 */
		TPair(const KeyType& InKey, const ValueType& InValue) : Key(InKey), Value(InValue) {}

		/**
		 * @brief Clave del par.
		 */
		KeyType Key;

		/**
		 * @brief Valor del par.
		 */
		ValueType Value;

		/**
		 * @brief Compara dos pares para verificar si son iguales.
		 *
		 * @param Other Otro par a comparar.
		 * @return true Si los pares son iguales.
		 * @return false Si los pares son diferentes.
		 */
		bool operator==(const TPair<KeyType, ValueType>& Other) const {
			return Key == Other.Key && Value == Other.Value;
		}

		/**
		 * @brief Compara dos pares para verificar si son diferentes.
		 *
		 * @param Other Otro par a comparar.
		 * @return true Si los pares son diferentes.
		 * @return false Si los pares son iguales.
		 */
		bool operator!=(const TPair<KeyType, ValueType>& Other) const {
			return !(*this == Other);
		}

		/**
		 * @brief Compara dos pares para verificar si el par actual es menor que el otro.
		 *
		 * @param Other Otro par a comparar.
		 * @return true Si el par actual es menor que el otro.
		 * @return false Si el par actual no es menor que el otro.
		 */
		bool operator<(const TPair<KeyType, ValueType>& Other) const {
			return Key < Other.Key || (Key == Other.Key && Value < Other.Value);
		}

		/**
		 * @brief Compara dos pares para verificar si el par actual es mayor que el otro.
		 *
		 * @param Other Otro par a comparar.
		 * @return true Si el par actual es mayor que el otro.
		 * @return false Si el par actual no es mayor que el otro.
		 */
		bool operator>(const TPair<KeyType, ValueType>& Other) const {
			return Other < *this;
		}

		/**
		 * @brief Compara dos pares para verificar si el par actual es menor o igual al otro.
		 *
		 * @param Other Otro par a comparar.
		 * @return true Si el par actual es menor o igual al otro.
		 * @return false Si el par actual no es menor o igual al otro.
		 */
		bool operator<=(const TPair<KeyType, ValueType>& Other) const {
			return !(Other < *this);
		}

		/**
		 * @brief Compara dos pares para verificar si el par actual es mayor o igual al otro.
		 *
		 * @param Other Otro par a comparar.
		 * @return true Si el par actual es mayor o igual al otro.
		 * @return false Si el par actual no es mayor o igual al otro.
		 */
		bool operator>=(const TPair<KeyType, ValueType>& Other) const {
			return !(*this < Other);
		}

		/**
		 * @brief Imprime el par en la consola.
		 *
		 * Muestra el valor de la clave y del valor en la consola.
		 */
		void Print() const {
			std::cout << "Key: " << Key << ", Value: " << Value << std::endl;
		}
	};

}
