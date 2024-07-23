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
#include <iostream>
#include "Structures/TArray.h"
#include "Structures/TMap.h"
#include "Structures/TSet.h"

#include <vector>
int main() {
	// TArray Example
  EngineUtilities::TArray<int> MyArray;
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

  // TMap Example
  EngineUtilities::TMap<int, std::string> MyMap;  ///< Crear una instancia de TMap para claves enteras y valores string.
  MyMap.Add(1, "One");  ///< Añadir pares clave-valor al mapa.
  MyMap.Add(2, "Two");
  MyMap.Add(3, "Three");

  MyMap.Remove(2);  ///< Eliminar el par con clave 2.

  std::cout << "Key 1: " << MyMap[1] << std::endl;  ///< Acceder e imprimir el valor asociado con la clave 1.
  std::cout << "Key 3: " << MyMap[3] << std::endl;  ///< Acceder e imprimir el valor asociado con la clave 3.

  std::cout << "Size: " << MyMap.Num() << ", Capacity: " << MyMap.GetCapacity() << std::endl;  ///< Imprimir el tamaño y la capacidad del mapa.
	
  // TSet
  EngineUtilities::TSet<int> MySet;  ///< Crear una instancia de TSet para elementos enteros.
  MySet.Add(1);  ///< Añadir elementos al conjunto.
  MySet.Add(2);
  MySet.Add(3);

  MySet.Remove(2);  ///< Eliminar el elemento 2 del conjunto.

  std::cout << "Contains 1: " << MySet.Contains(1) << std::endl;  ///< Verificar e imprimir si el conjunto contiene el elemento 1.
  std::cout << "Contains 2: " << MySet.Contains(2) << std::endl;  ///< Verificar e imprimir si el conjunto contiene el elemento 2.

  std::cout << "Size: " << MySet.Num() << ", Capacity: " << MySet.GetCapacity() << std::endl;  ///< Imprimir el tamaño y la capacidad del conjunto.
  return 0;
}