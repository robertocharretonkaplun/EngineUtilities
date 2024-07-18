# Biblioteca Matemática en C++

Esta biblioteca proporciona una serie de operaciones matemáticas básicas y utilidades para el manejo de vectores y matrices en C++. 

## Contenido

1. [Operaciones Matemáticas Generales](#operaciones-matemáticas-generales)
2. [Clase `Vector2`](#clase-vector2)
3. [Clase `Vector3`](#clase-vector3)
4. [Instalación y Uso](#instalación-y-uso)

## Operaciones Matemáticas Generales

Este módulo contiene funciones matemáticas básicas implementadas sin depender de la biblioteca estándar `<cmath>`. Las funciones incluyen:

- **`add`**: Suma dos números.
- **`subtract`**: Resta dos números.
- **`multiply`**: Multiplica dos números.
- **`divide`**: Divide dos números.
- **`sqrt`**: Calcula la raíz cuadrada de un número.
- **`pow`**: Calcula la potencia de un número.
- **`abs`**: Calcula el valor absoluto de un número.

### Ejemplo de Código

```cpp
#include "MathUtils.h"

int main() {
    double result = MathUtils::sqrt(16.0);
    std::cout << "La raíz cuadrada de 16 es: " << result << std::endl;
    return 0;
}
```

## Clase `Vector2`

La clase `Vector2` representa un vector en 2D. Proporciona operaciones básicas como suma, resta y cálculo de la longitud.

### Métodos Principales

- **Constructor**: `Vector2(double x = 0.0, double y = 0.0)`
- **Método `length`**: Calcula la longitud del vector.
- **Método `normalize`**: Normaliza el vector.
- **Método `dot`**: Calcula el producto punto entre dos vectores.

### Ejemplo de Código

```cpp
#include "Vector2.h"

int main() {
    Vector2 v1(3.0, 4.0);
    Vector2 v2(1.0, 2.0);
    Vector2 result = v1 + v2;
    std::cout << "La longitud de v1 es: " << v1.length() << std::endl;
    return 0;
}

```

## Clase `Vector3`

La clase `Vector3` representa un vector en 3D y proporciona operaciones adicionales como el cálculo del producto cruz y la proyección sobre un eje.

### Métodos Principales

- **Constructor**: `Vector3(double x = 0.0, double y = 0.0, double z = 0.0)`
- **Método `length`**: Calcula la longitud del vector.
- **Método `normalize`**: Normaliza el vector.
- **Método `cross`**: Calcula el producto cruz entre dos vectores.
- **Método `dot`**: Calcula el producto punto entre dos vectores.
- **Método `project`**: Proyecta el vector sobre un eje.

### Ejemplo de Código

```cpp
#include "Vector3.h"

int main() {
    Vector3 v1(1.0, 2.0, 3.0);
    Vector3 v2(4.0, 5.0, 6.0);
    Vector3 crossProduct = v1.cross(v2);
    std::cout << "El producto cruz de v1 y v2 es: (" 
              << crossProduct.x << ", " 
              << crossProduct.y << ", " 
              << crossProduct.z << ")" << std::endl;
    return 0;
}
```

## Instalación y Uso

Para instalar y usar la biblioteca:

1. **Incluir los archivos de encabezado en tu proyecto**: `MathUtils.h`, `Vector2.h`, `Vector3.h`.
2. **Incluir las implementaciones en tu proyecto**: `MathUtils.cpp`, `Vector2.cpp`, `Vector3.cpp`.
3. **Compilar el proyecto** junto con los archivos de la biblioteca.
