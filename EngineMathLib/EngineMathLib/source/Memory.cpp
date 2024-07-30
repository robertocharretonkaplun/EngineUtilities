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
	/*
	// Sección 1: Uso de TSharedPointer
	{
		TSharedPointer<MyClass> sp1 = MakeShared<MyClass>(10);
		sp1->display(); // Output: Value: 10

		TSharedPointer<MyClass> sp2 = sp1;
		sp2->display(); // Output: Value: 10

		// Sección 2: Uso de TWeakPointer
		TWeakPointer<MyClass> wp1(sp1);
		{
			TSharedPointer<MyClass> sp3 = wp1.lock();
			if (!sp3.isNull())
			{
				sp3->display(); // Output: Value: 10
			}
			else
			{
				std::cout << "wp1 is expired" << std::endl;
			}
		}

		// Destruir sp1 y sp2
		// Esto provocará la destrucción del objeto gestionado
	}

	// Verificar que el objeto ya no está accesible a través del TWeakPointer
	{
		TSharedPointer<MyClass> sp4;
		TWeakPointer<MyClass> wp2(sp4);
		TSharedPointer<MyClass> sp5 = wp2.lock();
		if (sp5.isNull())
		{
			std::cout << "sp5 is null after object destruction" << std::endl;
		}
	}
	*/
	{

		TSharedPointer<MyClass> sp1 = MakeShared<MyClass>(10);
		sp1->display();
		TSharedPointer<MyClass> sp2 = sp1;
		sp2->display();

		TSharedPointer<MyClass> sp3 = MakeShared<MyClass>(20);
		sp3 = std::move(sp1);
		sp3->display();
	}
	// UniquePtr
	{
		TUniquePtr<MyClass> up1 = MakeUnique<MyClass>(30);
		up1->display();

		TUniquePtr<MyClass> up2 = MakeUnique<MyClass>(40);
		up2->display();

		up2 = std::move(up1);
		if (up1.isNull())
		{
			std::cout << "UP1 is null after move" << std::endl;
		}
		up2->display();

		if (up2.isNull())
		{
			std::cout << "UP2 is null after move" << std::endl;
		}
		

		//delete rawPtr;

	}
	return 0;
}
