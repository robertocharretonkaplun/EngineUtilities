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
	 * @brief TArray es una clase de array dinámica para almacenar elementos de tipo T.
	 *
	 * Esta implementación de TArray proporciona una forma sencilla de almacenar y gestionar
	 * colecciones de elementos, con operaciones básicas como agregar, eliminar y acceder a elementos.
	 * La memoria se gestiona dinámicamente, aumentando la capacidad del array según sea necesario.
	 *
	 * @tparam T El tipo de elementos almacenados en el array.
	 */
	template<typename T>
	class TArray
	{
	private:
		T* Data;           ///< Puntero a la memoria donde se almacenan los elementos del array.
		size_t Capacity;   ///< Capacidad actual del array (número de elementos que puede almacenar).
		size_t Size;       ///< Número de elementos actualmente en el array.

		/**
		 * @brief Redimensiona el array para tener una nueva capacidad.
		 *
		 * @param NewCapacity La nueva capacidad del array.
		 */
		void Resize(size_t NewCapacity)
		{
			T* NewData = new T[NewCapacity];  ///< Crear un nuevo bloque de memoria con la nueva capacidad.
			for (size_t i = 0; i < Size; ++i)
			{
				NewData[i] = Data[i];  ///< Copiar los elementos existentes al nuevo bloque de memoria.
			}
			delete[] Data;  ///< Liberar la memoria del array antiguo.
			Data = NewData; ///< Actualizar el puntero Data para que apunte al nuevo bloque de memoria.
			Capacity = NewCapacity;  ///< Actualizar la capacidad del array.
		}

	public:
		/**
		 * @brief Constructor por defecto que inicializa el array con capacidad y tamaño cero.
		 */
		TArray() : Data(nullptr), Capacity(0), Size(0)	{}

		/**
		 * @brief Destructor que libera la memoria asignada al array.
		 */
		~TArray()	{
			delete[] Data;  ///< Liberar la memoria del array.
		}

		/**
		 * @brief Añade un nuevo elemento al final del array.
		 *
		 * @param Element El elemento a añadir al array.
		 */
		void Add(const T& Element)
		{
			if (Size == Capacity)
			{
				Resize(Capacity == 0 ? 1 : Capacity * 2);  ///< Redimensionar si es necesario.
			}
			Data[Size++] = Element;  ///< Añadir el nuevo elemento y aumentar el tamaño.
		}

		/**
		 * @brief Elimina el elemento en la posición especificada.
		 *
		 * @param Index La posición del elemento a eliminar.
		 */
		void RemoveAt(size_t Index)
		{
			if (Index >= Size)
			{
				std::cerr << "Index out of range" << std::endl;  ///< Manejar el caso de índice fuera de rango.
				return;
			}
			for (size_t i = Index; i < Size - 1; ++i)
			{
				Data[i] = Data[i + 1];  ///< Desplazar los elementos hacia la izquierda para llenar el hueco.
			}
			--Size;  ///< Disminuir el tamaño del array.
		}

		/**
		 * @brief Sobrecarga del operador [] para acceder a elementos por índice.
		 *
		 * @param Index La posición del elemento a acceder.
		 * @return Referencia al elemento en la posición especificada.
		 */
		T& operator[](size_t Index)
		{
			if (Index >= Size)
			{
				std::cerr << "Index out of range" << std::endl;  ///< Manejar el caso de índice fuera de rango.
				exit(1);  ///< Salir del programa en caso de error.
			}
			return Data[Index];  ///< Devolver el elemento en la posición especificada.
		}

		/**
		 * @brief Versión constante de la sobrecarga del operador [] para acceder a elementos por índice.
		 *
		 * @param Index La posición del elemento a acceder.
		 * @return Referencia constante al elemento en la posición especificada.
		 */
		const T& operator[](size_t Index) const
		{
			if (Index >= Size)
			{
				std::cerr << "Index out of range" << std::endl;  ///< Manejar el caso de índice fuera de rango.
				exit(1);  ///< Salir del programa en caso de error.
			}
			return Data[Index];  ///< Devolver el elemento en la posición especificada.
		}

		/**
		 * @brief Devuelve el número de elementos actualmente en el array.
		 *
		 * @return El número de elementos en el array.
		 */
		size_t Num() const
		{
			return Size;  ///< Devolver el tamaño actual del array.
		}

		/**
		 * @brief Devuelve la capacidad actual del array.
		 *
		 * @return La capacidad del array.
		 */
		size_t GetCapacity() const
		{
			return Capacity;  ///< Devolver la capacidad actual del array.
		}
	};

	// EXAMPLE

	/*
	int main() {

		// TArray Example
		TArray<int> MyArray;
		MyArray.Add(1);
		MyArray.Add(2);
		MyArray.Add(3);
		MyArray.Add(4);
		MyArray.Add(5);

		MyArray.Add(6);
		MyArray.RemoveAt(2);

		for (size_t i = 0; i < MyArray.Num(); ++i)
		{
			std::cout << MyArray[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "Size: " << MyArray.Num() << ", Capacity: " << MyArray.GetCapacity() << std::endl;

		return 0;
	}
	*/
}