/*
 * MIT License
 *
 * Copyright (c) 2025 Roberto Charreton
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
#include "TSharedPointer.h"

namespace
	EU {
	/**
		 * @brief Clase TWeakPointer para observar objetos gestionados por TSharedPointer sin aumentar el recuento de referencias.
		 *
		 * La clase TWeakPointer proporciona una manera de observar un objeto gestionado por un TSharedPointer
		 * sin tener influencia sobre el recuento de referencias del objeto. Permite acceder al objeto solo si
		 * aún existe.
		 */
	template<typename T>
	class TWeakPointer {
	public:
		/**
		 * @brief Constructor por defecto.
		 */
		TWeakPointer() : ptr(nullptr), refCount(nullptr) {}

		/**
		 * @brief Constructor que toma un TSharedPointer.
		 *
		 * @param sharedPtr TSharedPointer desde el cual se observará el objeto.
		 */
		TWeakPointer(const TSharedPointer<T>& sharedPtr)
			: ptr(sharedPtr.ptr), refCount(sharedPtr.refCount) {
		}

		/**
		 * @brief Convertir TWeakPointer a TSharedPointer.
		 *
		 * @return Un TSharedPointer al objeto gestionado, o nullptr si el objeto ha sido destruido.
		 */
		TSharedPointer<T>
			lock() const {
			if (refCount && *refCount > 0) {
				return TSharedPointer<T>(ptr, refCount);
			}
			return TSharedPointer<T>();
		}

		// Hacer que TSharedPointer sea un amigo para acceder a los miembros privados.
		template<typename U>
		friend class TSharedPointer;

	private:
		T* ptr;       ///< Puntero al objeto observado.
		int* refCount; ///< Puntero al recuento de referencias del TSharedPointer original.
	};

	/*
	#include "TSharedPointer.h"
#include "TWeakPointer.h"

class MyClass
{
public:
		MyClass(int val) : value(val) {}
		void display() const { std::cout << "Value: " << value << std::endl; }

private:
		int value;
};

int main()
{
		{
				// Crear un TSharedPointer que gestiona un objeto MyClass
				EngineUtilities::TSharedPointer<MyClass> sp1 = EngineUtilities::MakeShared<MyClass>(10);
				sp1->display();

				// Crear un TWeakPointer a partir del TSharedPointer
				EngineUtilities::TWeakPointer<MyClass> wp1(sp1);

				// Intentar obtener un TSharedPointer a partir del TWeakPointer
				EngineUtilities::TSharedPointer<MyClass> sp2 = wp1.lock();
				if (!sp2.isNull())
				{
						sp2->display(); // Debería mostrar el valor 10
				}
				else
				{
						std::cout << "wp1 expired." << std::endl;
				}

				// Crear un nuevo TSharedPointer y mover el puntero compartido
				EngineUtilities::TSharedPointer<MyClass> sp3 = EngineUtilities::MakeShared<MyClass>(20);
				sp3 = std::move(sp1); // Mueve la propiedad de sp1 a sp3

				// El puntero compartido original (sp1) ahora está vacío
				EngineUtilities::TSharedPointer<MyClass> sp4 = wp1.lock();
				if (sp4.isNull())
				{
						std::cout << "sp1 has been moved and is now null." << std::endl;
				}

				// Intentar obtener un TSharedPointer después del movimiento
				if (sp3.isNull())
				{
						std::cout << "sp3 is null." << std::endl;
				}
				else
				{
						sp3->display(); // Debería mostrar el valor 20
				}
		} // Aquí, tanto sp2 como sp4 se destruyen y la memoria de MyClass se libera automáticamente

		return 0;
}
	*/
}