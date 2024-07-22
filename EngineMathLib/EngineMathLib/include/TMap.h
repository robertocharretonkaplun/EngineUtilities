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
	 * @brief TMap es una clase de mapa (diccionario) dinámica para almacenar pares clave-valor.
	 *
	 * Esta implementación de TMap proporciona una forma sencilla de almacenar y gestionar
	 * colecciones de pares clave-valor, con operaciones básicas como agregar, eliminar y acceder a valores.
	 * La memoria se gestiona dinámicamente, aumentando la capacidad del mapa según sea necesario.
	 *
	 * @tparam K El tipo de las claves.
	 * @tparam V El tipo de los valores.
	 */
	template<typename K, typename V>
	class TMap
	{
	private:
		struct Pair
		{
			K Key;
			V Value;

			Pair() : Key(), Value() {}
			Pair(const K& Key, const V& Value) : Key(Key), Value(Value) {}
		};

		Pair* Data;        ///< Puntero a la memoria donde se almacenan los pares clave-valor.
		size_t Capacity;   ///< Capacidad actual del mapa (número de pares que puede almacenar).
		size_t Size;       ///< Número de pares actualmente en el mapa.

		/**
		 * @brief Redimensiona el mapa para tener una nueva capacidad.
		 *
		 * @param NewCapacity La nueva capacidad del mapa.
		 */
		void Resize(size_t NewCapacity)
		{
			Pair* NewData = new Pair[NewCapacity];  ///< Crear un nuevo bloque de memoria con la nueva capacidad.
			for (size_t i = 0; i < Size; ++i)
			{
				NewData[i] = Data[i];  ///< Copiar los pares existentes al nuevo bloque de memoria.
			}
			delete[] Data;  ///< Liberar la memoria del mapa antiguo.
			Data = NewData; ///< Actualizar el puntero Data para que apunte al nuevo bloque de memoria.
			Capacity = NewCapacity;  ///< Actualizar la capacidad del mapa.
		}

	public:
		/**
		 * @brief Constructor por defecto que inicializa el mapa con capacidad y tamaño cero.
		 */
		TMap()
			: Data(nullptr), Capacity(0), Size(0)
		{
		}

		/**
		 * @brief Destructor que libera la memoria asignada al mapa.
		 */
		~TMap()
		{
			delete[] Data;  ///< Liberar la memoria del mapa.
		}

		/**
		 * @brief Añade un nuevo par clave-valor al mapa.
		 *
		 * @param Key La clave del nuevo par.
		 * @param Value El valor del nuevo par.
		 */
		void Add(const K& Key, const V& Value)
		{
			for (size_t i = 0; i < Size; ++i)
			{
				if (Data[i].Key == Key)
				{
					Data[i].Value = Value;  ///< Actualizar el valor si la clave ya existe.
					return;
				}
			}
			if (Size == Capacity)
			{
				Resize(Capacity == 0 ? 1 : Capacity * 2);  ///< Redimensionar si es necesario.
			}
			Data[Size++] = Pair(Key, Value);  ///< Añadir el nuevo par y aumentar el tamaño.
		}

		/**
		 * @brief Elimina el par clave-valor en la posición especificada.
		 *
		 * @param Key La clave del par a eliminar.
		 */
		void Remove(const K& Key)
		{
			for (size_t i = 0; i < Size; ++i)
			{
				if (Data[i].Key == Key)
				{
					for (size_t j = i; j < Size - 1; ++j)
					{
						Data[j] = Data[j + 1];  ///< Desplazar los pares hacia la izquierda para llenar el hueco.
					}
					--Size;  ///< Disminuir el tamaño del mapa.
					return;
				}
			}
			std::cerr << "Key not found" << std::endl;  ///< Manejar el caso de clave no encontrada.
		}

		/**
		 * @brief Sobrecarga del operador [] para acceder a valores por clave.
		 *
		 * @param Key La clave del valor a acceder.
		 * @return Referencia al valor asociado con la clave especificada.
		 */
		V& operator[](const K& Key)
		{
			for (size_t i = 0; i < Size; ++i)
			{
				if (Data[i].Key == Key)
				{
					return Data[i].Value;  ///< Devolver el valor si la clave se encuentra.
				}
			}
			std::cerr << "Key not found" << std::endl;  ///< Manejar el caso de clave no encontrada.
			exit(1);  ///< Salir del programa en caso de error.
		}

		/**
		 * @brief Versión constante de la sobrecarga del operador [] para acceder a valores por clave.
		 *
		 * @param Key La clave del valor a acceder.
		 * @return Referencia constante al valor asociado con la clave especificada.
		 */
		const V& operator[](const K& Key) const
		{
			for (size_t i = 0; i < Size; ++i)
			{
				if (Data[i].Key == Key)
				{
					return Data[i].Value;  ///< Devolver el valor si la clave se encuentra.
				}
			}
			std::cerr << "Key not found" << std::endl;  ///< Manejar el caso de clave no encontrada.
			exit(1);  ///< Salir del programa en caso de error.
		}

		/**
		 * @brief Devuelve el número de pares actualmente en el mapa.
		 *
		 * @return El número de pares en el mapa.
		 */
		size_t Num() const
		{
			return Size;  ///< Devolver el tamaño actual del mapa.
		}

		/**
		 * @brief Devuelve la capacidad actual del mapa.
		 *
		 * @return La capacidad del mapa.
		 */
		size_t GetCapacity() const
		{
			return Capacity;  ///< Devolver la capacidad actual del mapa.
		}
	};

	// EXAMPLE

	/*
	int main()
	{
		TMap<int, std::string> MyMap;  ///< Crear una instancia de TMap para claves enteras y valores string.
		MyMap.Add(1, "One");  ///< Añadir pares clave-valor al mapa.
		MyMap.Add(2, "Two");
		MyMap.Add(3, "Three");

		MyMap.Remove(2);  ///< Eliminar el par con clave 2.

		std::cout << "Key 1: " << MyMap[1] << std::endl;  ///< Acceder e imprimir el valor asociado con la clave 1.
		std::cout << "Key 3: " << MyMap[3] << std::endl;  ///< Acceder e imprimir el valor asociado con la clave 3.

		std::cout << "Size: " << MyMap.Num() << ", Capacity: " << MyMap.GetCapacity() << std::endl;  ///< Imprimir el tamaño y la capacidad del mapa.

		return 0;
	}
	*/
}