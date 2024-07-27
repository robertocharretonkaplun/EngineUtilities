#include <iostream>
#include "Memory/TSharedPointer.h"
#include "Memory/TUniquePtr.h"
#include "Memory/TWeakPointer.h"

using namespace EngineUtilities;

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
  // Ejemplo con TSharedPointer
  {
    TSharedPointer<MyClass> sp1 = MakeShared<MyClass>(10);
    sp1->display(); // Output: Value: 10

    // Crear otro TSharedPointer a partir del primero
    TSharedPointer<MyClass> sp2 = sp1;
    sp2->display(); // Output: Value: 10

    // Crear otro TSharedPointer y asignarle el primero
    TSharedPointer<MyClass> sp3;
    sp3 = sp1;
    sp3->display(); // Output: Value: 10

    // Crear un nuevo TSharedPointer con un nuevo objeto
    TSharedPointer<MyClass> sp4 = MakeShared<MyClass>(20);
    sp4 = std::move(sp1);
    sp4->display(); // Output: Value: 10
  } // Aquí, tanto sp2 como sp4 se destruyen y la memoria de MyClass se libera automáticamente

  // Ejemplo con TUniquePtr
  {
    TUniquePtr<MyClass> up1 = MakeUnique<MyClass>(30);
    up1->display(); // Output: Value: 30

    // Crear otro TUniquePtr
    TUniquePtr<MyClass> up2 = MakeUnique<MyClass>(40);
    up2->display(); // Output: Value: 40

    // Transferir propiedad usando el operador de asignación de movimiento
    up2 = std::move(up1);

    // up1 ahora es nulo, up2 ahora posee el objeto que estaba en up1
    if (up1.isNull())
    {
      std::cout << "up1 is null after move" << std::endl;
    }
    up2->display(); // Output: Value: 30

    // Liberar propiedad usando el método release
    MyClass* rawPtr = up2.release();
    rawPtr->display(); // Output: Value: 30

    // Liberar manualmente la memoria ya que fue liberada del TUniquePtr
    delete rawPtr;
  }

  // Ejemplo con TWeakPointer
  {
    TSharedPointer<MyClass> sp1 = MakeShared<MyClass>(50);
    TWeakPointer<MyClass> weakPtr1(sp1);

    {
      TSharedPointer<MyClass> sp2 = weakPtr1.lock();
      if (!sp2.isNull())
      {
        sp2->display(); // Output: Value: 50
      }
    } // sp2 se destruye aquí, pero sp1 aún existe

    // Reiniciar sp1
    sp1.reset();

    TSharedPointer<MyClass> sp3 = weakPtr1.lock();
    if (sp3.isNull())
    {
      std::cout << "sp3 is null after sp1 is reset" << std::endl;
    }
  }

  return 0;
}