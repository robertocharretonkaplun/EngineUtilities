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
 * @brief Clase TStaticPtr para manejo de un puntero estático.
 *
 * La clase TStaticPtr gestiona un único objeto estático y proporciona métodos
 * para acceder al objeto, verificar si el puntero es nulo y realizar operaciones
 * básicas de manejo de memoria.
 */
  template<typename T>
  class TStaticPtr
  {
  public:
    /**
     * @brief Inicializa el puntero estático al objeto.
     *
     * Inicializa el puntero estático a nullptr.
     */
    TStaticPtr() = default;

    /**
     * @brief Constructor que toma un puntero crudo.
     *
     * @param rawPtr Puntero crudo al objeto que se va a gestionar.
     */
    explicit TStaticPtr(T* rawPtr)
    {
      if (instance != nullptr)
      {
        delete instance;
      }
      instance = rawPtr;
    }

    /**
     * @brief Destructor.
     *
     * Libera la memoria del objeto gestionado si es la última instancia.
     */
    ~TStaticPtr()
    {
      if (instance != nullptr)
      {
        delete instance;
        instance = nullptr;
      }
    }

    /**
     * @brief Obtener el puntero crudo.
     *
     * @return Puntero crudo al objeto gestionado.
     */
    static T* get()
    {
      return instance;
    }

    /**
     * @brief Verificar si el puntero es nulo.
     *
     * @return true si el puntero es nulo, false en caso contrario.
     */
    static bool isNull()
    {
      return instance == nullptr;
    }

    /**
     * @brief Reiniciar el puntero estático con un nuevo objeto.
     *
     * Libera la memoria del objeto actual (si existe) y toma la propiedad de un nuevo puntero crudo.
     *
     * @param rawPtr Puntero crudo al nuevo objeto que se va a gestionar.
     */
    static void reset(T* rawPtr = nullptr)
    {
      if (instance != nullptr)
      {
        delete instance;
      }
      instance = rawPtr;
    }

  private:
    static T* instance; ///< Puntero estático al objeto gestionado.
  };

  /*
  // Inicializar el puntero estático
  template<typename T>
  T* TStaticPtr<T>::instance = nullptr;

  // Ejemplo de uso de TStaticPtr
  class MyClass
  {
  public:
    MyClass(int value) : value(value)
    {
      std::cout << "MyClass constructor: " << value << std::endl;
    }

    ~MyClass()
    {
      std::cout << "MyClass destructor: " << value << std::endl;
    }

    void display() const
    {
      std::cout << "Value: " << value << std::endl;
    }

  private:
    int value;
  };

  int main()
  {
    {
      // Crear un TStaticPtr usando un puntero crudo
      TStaticPtr<MyClass>::reset(new MyClass(10));
      TStaticPtr<MyClass>::get()->display(); // Output: Value: 10

      // Comprobar si el puntero no es nulo
      if (!TStaticPtr<MyClass>::isNull())
      {
        std::cout << "TStaticPtr is not null" << std::endl;
      }

      // Reiniciar TStaticPtr con un nuevo objeto
      TStaticPtr<MyClass>::reset(new MyClass(20));
      TStaticPtr<MyClass>::get()->display(); // Output: Value: 20

      // Reiniciar con nullptr
      TStaticPtr<MyClass>::reset();
      if (TStaticPtr<MyClass>::isNull())
      {
        std::cout << "TStaticPtr is null after reset" << std::endl;
      }
    }

    return 0;
  }
  */
}
