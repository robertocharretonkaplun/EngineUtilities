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
	 * @brief TSet es una clase de conjunto dinámica para almacenar elementos únicos.
	 *
	 * Esta implementación de TSet proporciona una forma sencilla de almacenar y gestionar
	 * colecciones de elementos únicos, con operaciones básicas como agregar, eliminar y verificar la existencia de elementos.
	 * La memoria se gestiona dinámicamente, aumentando la capacidad del conjunto según sea necesario.
	 *
	 * @tparam T El tipo de los elementos almacenados en el conjunto.
	 */
	template<typename T>
	class TSet
	{
	private:
		T* Data;        ///< Puntero a la memoria donde se almacenan los elementos.
		size_t Capacity;   ///< Capacidad actual del conjunto (número de elementos que puede almacenar).
		size_t Size;       ///< Número de elementos actualmente en el conjunto.

		/**
		 * @brief Redimensiona el conjunto para tener una nueva capacidad.
		 *
		 * @param NewCapacity La nueva capacidad del conjunto.
		 */
		void Resize(size_t NewCapacity)
		{
			T* NewData = new T[NewCapacity];  ///< Crear un nuevo bloque de memoria con la nueva capacidad.
			for (size_t i = 0; i < Size; ++i)
			{
				NewData[i] = Data[i];  ///< Copiar los elementos existentes al nuevo bloque de memoria.
			}
			delete[] Data;  ///< Liberar la memoria del conjunto antiguo.
			Data = NewData; ///< Actualizar el puntero Data para que apunte al nuevo bloque de memoria.
			Capacity = NewCapacity;  ///< Actualizar la capacidad del conjunto.
		}

	public:
		/**
		 * @brief Constructor por defecto que inicializa el conjunto con capacidad y tamaño cero.
		 */
		TSet()
			: Data(nullptr), Capacity(0), Size(0)
		{
		}

		/**
		 * @brief Destructor que libera la memoria asignada al conjunto.
		 */
		~TSet()
		{
			delete[] Data;  ///< Liberar la memoria del conjunto.
		}

		/**
		 * @brief Añade un nuevo elemento al conjunto.
		 *
		 * @param Element El elemento a añadir.
		 */
		void Add(const T& Element)
		{
			if (Contains(Element))
			{
				return;  ///< No añadir duplicados.
			}
			if (Size == Capacity)
			{
				Resize(Capacity == 0 ? 1 : Capacity * 2);  ///< Redimensionar si es necesario.
			}
			Data[Size++] = Element;  ///< Añadir el nuevo elemento y aumentar el tamaño.
		}

		/**
		 * @brief Elimina el elemento especificado del conjunto.
		 *
		 * @param Element El elemento a eliminar.
		 */
		void Remove(const T& Element)
		{
			for (size_t i = 0; i < Size; ++i)
			{
				if (Data[i] == Element)
				{
					for (size_t j = i; j < Size - 1; ++j)
					{
						Data[j] = Data[j + 1];  ///< Desplazar los elementos hacia la izquierda para llenar el hueco.
					}
					--Size;  ///< Disminuir el tamaño del conjunto.
					return;
				}
			}
			std::cerr << "Element not found" << std::endl;  ///< Manejar el caso de elemento no encontrado.
		}

		/**
		 * @brief Verifica si el conjunto contiene el elemento especificado.
		 *
		 * @param Element El elemento a verificar.
		 * @return true Si el conjunto contiene el elemento.
		 * @return false Si el conjunto no contiene el elemento.
		 */
		bool Contains(const T& Element) const
		{
			for (size_t i = 0; i < Size; ++i)
			{
				if (Data[i] == Element)
				{
					return true;  ///< Devolver true si el elemento se encuentra.
				}
			}
			return false;  ///< Devolver false si el elemento no se encuentra.
		}

		/**
		 * @brief Devuelve el número de elementos actualmente en el conjunto.
		 *
		 * @return El número de elementos en el conjunto.
		 */
		size_t Num() const
		{
			return Size;  ///< Devolver el tamaño actual del conjunto.
		}

		/**
		 * @brief Devuelve la capacidad actual del conjunto.
		 *
		 * @return La capacidad del conjunto.
		 */
		size_t GetCapacity() const
		{
			return Capacity;  ///< Devolver la capacidad actual del conjunto.
		}
	};

	// Example

	/*
	int main()
	{
		TSet<int> MySet;  ///< Crear una instancia de TSet para elementos enteros.
		MySet.Add(1);  ///< Añadir elementos al conjunto.
		MySet.Add(2);
		MySet.Add(3);

		MySet.Remove(2);  ///< Eliminar el elemento 2 del conjunto.

		std::cout << "Contains 1: " << MySet.Contains(1) << std::endl;  ///< Verificar e imprimir si el conjunto contiene el elemento 1.
		std::cout << "Contains 2: " << MySet.Contains(2) << std::endl;  ///< Verificar e imprimir si el conjunto contiene el elemento 2.

		std::cout << "Size: " << MySet.Num() << ", Capacity: " << MySet.GetCapacity() << std::endl;  ///< Imprimir el tamaño y la capacidad del conjunto.

		return 0;
	}
	*/
}