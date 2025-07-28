
# 📘 Guía de EngineUtilities

**EngineUtilities** es una biblioteca de utilidades matemáticas y estructuras de datos escrita en C++. Está diseñada para facilitar el desarrollo de motores de juego y aplicaciones gráficas proporcionando clases y algoritmos para:

- Vectores
- Matrices
- Cuaterniones
- Estructuras de datos genéricas
- Punteros inteligentes

Esta guía detalla sus componentes más importantes e incluye ejemplos de uso.

---

## 🗂️ Estructura de la Biblioteca

- Encabezados: Carpeta `include`
- Implementaciones (si las hay): Carpeta `source`
- Subcarpetas principales:
  - `Matrix/`
  - `Vectors/`
  - `Memory/`
  - `Structures/`
  - `Utilities/`

---

## 🧮 Componentes y Funcionalidades

### 🔢 Matrices

Se proporcionan clases para matrices 2×2, 3×3 y 4×4. Operaciones comunes:

- Inicialización con valores individuales o vectores columna
- Suma, resta y multiplicación (matrices y escalares)
- Determinante, traza, transpuesta, inversa

#### Ejemplo:

```cpp
#include "Matrix/Matrix3x3.h"
#include "Vectors/Vector3.h"

Matrix3x3 rotX = Matrix3x3::RotationX(90.0f * DEG_TO_RAD);
Matrix3x3 rotY = Matrix3x3::RotationY(45.0f * DEG_TO_RAD);
Matrix3x3 transform = rotY * rotX;

Vector3 v(1.0f, 0.0f, 0.0f);
Vector3 rotated = transform * v;
```

### 📐 Vectores y Cuaterniones

Clases disponibles: `Vector2`, `Vector3`, `Vector4`, `Quaternion`.

Operaciones comunes:

- Suma, resta, producto escalar, normalización
- Para `Quaternion`: rotaciones 3D, slerp, conjugado, conversión desde Euler

#### Ejemplo de Vector:

```cpp
#include "Vectors/Vector3.h"
#include <iostream>

int main() {
    Vector3 a(3.0f, 4.0f, 0.0f);
    Vector3 b(1.0f, 2.0f, 3.0f);
    Vector3 sum = a + b;
    float len = sum.Length();
    Vector3 unit = sum.Normalized();

    std::cout << "Suma: " << sum.x << "," << sum.y << "," << sum.z << '\n';
    std::cout << "Longitud: " << len << '\n';
    std::cout << "Normalizado: " << unit.x << "," << unit.y << "," << unit.z << '\n';
}
```

#### Ejemplo de Slerp:

```cpp
#include "Vectors/Quaternion.h"

Quaternion qStart = Quaternion::FromEuler(0.0f, 0.0f, 0.0f);
Quaternion qEnd   = Quaternion::FromEuler(0.0f, 90.0f * DEG_TO_RAD, 0.0f);
float t = 0.5f;
Quaternion qMid = Quaternion::Slerp(qStart, qEnd, t);
```

### 🧠 Punteros Inteligentes

- `TSharedPointer`: puntero compartido con contador
- `TUniquePtr`: exclusivo, similar a `std::unique_ptr`
- `TStaticPtr`: puntero estático tipo singleton
- `TWeakPointer`: observador de `TSharedPointer` (no incrementa contador)

#### Ejemplo:

```cpp
#include "Memory/TSharedPointer.h"
#include "Memory/TWeakPointer.h"
#include <iostream>

struct Entity {
    int id;
    Entity(int i) : id(i) {}
};

int main() {
    TSharedPointer<Entity> e1 = TSharedPointer<Entity>::MakeShared(42);
    {
        TSharedPointer<Entity> e2 = e1;
        std::cout << "ID: " << e2->id << '\n';
    }
    TWeakPointer<Entity> weak = e1;
    if (auto locked = weak.Lock()) {
        std::cout << "Aún vivo: " << locked->id << '\n';
    }
}
```

### 🧺 Estructuras de Datos Genéricas

- `TArray`: similar a `std::vector`
- `TMap`: diccionario clave-valor
- `TPair`: estructura de dos valores
- `TSet`: conjunto de elementos únicos

#### Ejemplo:

```cpp
#include "Structures/TMap.h"
#include "Structures/TSet.h"
#include <iostream>

int main() {
    TMap<std::string, int> edades;
    edades.Insert("Ana", 30);
    edades.Insert("Luis", 25);

    if (edades.ContainsKey("Ana")) {
        std::cout << "Edad de Ana: " << edades["Ana"] << '\n';
    }

    TSet<int> numeros;
    numeros.Insert(1);
    numeros.Insert(2);
    numeros.Insert(2);

    for (int n : numeros) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}
```

### 🧮 Utilidades Matemáticas

Archivo: `Utilities/EngineMath.h`

- `DegreesToRadians()`, `RadiansToDegrees()`
- `Lerp()`, `Clamp()`
- Aleatorios
- Constantes: `M_PI`, etc.

#### Ejemplo:

```cpp
#include "Utilities/EngineMath.h"
#include <iostream>

int main() {
    float grados = 90.0f;
    float radianes = DegreesToRadians(grados);
    float t = 0.25f;
    float valor = Lerp(10.0f, 20.0f, t);
    float limitado = Clamp(valor, 0.0f, 15.0f);

    std::cout << grados << "° en radianes: " << radianes << '\n';
    std::cout << "Interpolación: " << valor << '\n';
    std::cout << "Limitado a [0,15]: " << limitado << '\n';
}
```

---

## 🔗 Integración en tu Proyecto

- Clona o descarga el repositorio
- Añade `include/` al path del compilador
- Compila archivos `.cpp` (si existen)

---

## 📄 Licencia

EngineUtilities usa la licencia MIT.

> “This project uses software developed by Roberto Charreton and Attribute Overload.”
