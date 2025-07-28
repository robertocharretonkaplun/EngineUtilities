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

namespace EU {
  /**
 * @brief Clase TUniquePtr para manejo exclusivo de memoria.
 *
 * La clase TUniquePtr gestiona la memoria de un objeto de tipo T y garantiza
 * que solo una instancia de TUniquePtr puede poseer y gestionar el objeto en
 * cualquier momento.
 */
  template<typename T>
  class TUniquePtr {
  public:
    /**
     * @brief Constructor por defecto.
     *
     * Inicializa el puntero a nullptr.
     */
    TUniquePtr() : ptr(nullptr) {}

    /**
     * @brief Constructor que toma un puntero crudo.
     *
     * @param rawPtr Puntero crudo al objeto que se va a gestionar.
     */
    explicit TUniquePtr(T* rawPtr) : ptr(rawPtr) {}

    /**
     * @brief Constructor de movimiento.
     *
     * Transfiere la propiedad del puntero del otro TUniquePtr al nuevo objeto TUniquePtr.
     *
     * @param other Otro objeto TUniquePtr del mismo tipo T.
     */
    TUniquePtr(TUniquePtr<T>&& other) noexcept : ptr(other.ptr) {
      other.ptr = nullptr;
    }

    /**
     * @brief Operador de asignación de movimiento.
     *
     * Libera el objeto actual y transfiere la propiedad del puntero del otro
     * TUniquePtr al actual.
     *
     * @param other Otro objeto TUniquePtr del mismo tipo T.
     * @return Referencia al objeto TUniquePtr actual.
     */
    TUniquePtr<T>&
      operator=(TUniquePtr<T>&& other) noexcept {
      if (this != &other) {
        // Liberar el objeto actual
        delete ptr;

        // Transferir los datos del otro puntero exclusivo
        ptr = other.ptr;
        other.ptr = nullptr;
      }
      return *this;
    }

    /**
     * @brief Destructor.
     *
     * Libera la memoria del objeto gestionado.
     */
    ~TUniquePtr() {
      delete ptr;
    }

    // Prohibir la copia de TUniquePtr
    TUniquePtr(const TUniquePtr<T>&) = delete;
    TUniquePtr<T>& operator=(const TUniquePtr<T>&) = delete;

    /**
     * @brief Operador de desreferenciación.
     *
     * @return Referencia al objeto gestionado.
     */
    T&
      operator*() const {
      return *ptr;
    }

    /**
     * @brief Operador de acceso a miembros.
     *
     * @return Puntero al objeto gestionado.
     */
    T*
      operator->() const {
      return ptr;
    }

    /**
     * @brief Obtener el puntero crudo.
     *
     * @return Puntero crudo al objeto gestionado.
     */
    T*
      get() const {
      return ptr;
    }

    /**
     * @brief Liberar la propiedad del puntero crudo.
     *
     * Libera la propiedad del puntero crudo gestionado y devuelve el puntero sin gestionar.
     *
     * @return Puntero crudo al objeto gestionado.
     */
    T*
      release() {
      T* oldPtr = ptr;
      ptr = nullptr;
      return oldPtr;
    }

    /**
     * @brief Reiniciar el puntero gestionado.
     *
     * Libera el objeto actual (si existe) y toma la propiedad de un nuevo puntero crudo.
     *
     * @param rawPtr Puntero crudo al nuevo objeto que se va a gestionar.
     */
    void
      reset(T* rawPtr = nullptr) {
      delete ptr;
      ptr = rawPtr;
    }

    /**
     * @brief Verificar si el puntero es nulo.
     *
     * @return true si el puntero es nulo, false en caso contrario.
     */
    bool
      isNull() const {
      return ptr == nullptr;
    }
  private:
    T* ptr; ///< Puntero al objeto gestionado.
  };

  /**
   * @brief Función de utilidad para crear un TUniquePtr.
   *
   * @tparam T Tipo del objeto gestionado.
   * @tparam Args Tipos de los argumentos del constructor del objeto gestionado.
   * @param args Argumentos del constructor del objeto gestionado.
   * @return Un objeto TUniquePtr gestionando un nuevo objeto de tipo T.
   */
  template<typename T, typename... Args>
  TUniquePtr<T>
    MakeUnique(Args... args) {
    return TUniquePtr<T>(new T(args...));
  }

  /*
  // Ejemplo de uso de TUniquePtr
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
    int value; ///< Valor del objeto MyClass.
  };

  int main()
  {
    {
      TUniquePtr<MyClass> up1 = MakeUnique<MyClass>(10);
      up1->display();

      TUniquePtr<MyClass> up2 = MakeUnique<MyClass>(20);
      up2->display();

      // Transferencia de propiedad
      up2 = std::move(up1);
      up2->display();

      // Liberar propiedad
      MyClass* rawPtr = up2.release();
      rawPtr->display();
      delete rawPtr; // Manualmente liberar la memoria ya que fue liberada del TUniquePtr
    } // Aquí, up1 y up2 se destruyen y la memoria de MyClass se libera automáticamente si no fue liberada antes

    return 0;
  }
  */
}