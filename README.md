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

# Matrices en C++

Las matrices son estructuras de datos bidimensionales que se utilizan para representar y manipular colecciones de datos organizados en filas y columnas. Son ampliamente utilizadas en matemáticas, gráficos por computadora y otras áreas que requieren el manejo de datos tabulares.

## Conceptos Básicos

### Definición

Una matriz es una colección de elementos dispuestos en una tabla de `m` filas y `n` columnas. Cada elemento de la matriz se identifica por un par de índices (fila, columna).

### Notación

Una matriz se denota comúnmente como `A` y sus elementos se representan como `a_{ij}`, donde `i` es el índice de la fila y `j` es el índice de la columna.

Por ejemplo, una matriz de 2x3 se representa como:

A = [ a_{11} a_{12} a_{13} ]
[ a_{21} a_{22} a_{23} ]


### Tipos de Matrices

1. **Matriz Cuadrada**: Número de filas es igual al número de columnas (`m = n`).
2. **Matriz Rectangular**: Número de filas no es igual al número de columnas (`m ≠ n`).
3. **Matriz Diagonal**: Todos los elementos fuera de la diagonal principal son cero.
4. **Matriz Identidad**: Una matriz diagonal con todos los elementos de la diagonal principal iguales a 1.
5. **Matriz Nula**: Todos los elementos son cero.

## Operaciones Básicas

### Adición y Sustracción

Dos matrices de las mismas dimensiones se pueden sumar o restar sumando o restando sus elementos correspondientes.

### Multiplicación por un Escalar

Cada elemento de una matriz se multiplica por un escalar.

### Multiplicación de Matrices

Para multiplicar dos matrices `A` y `B`, el número de columnas de `A` debe ser igual al número de filas de `B`. El elemento en la posición `(i, j)` de la matriz resultante `C` se calcula como:

c_{ij} = ∑ (a_{ik} * b_{kj})


### Transposición

La matriz transpuesta `A^T` se obtiene intercambiando filas por columnas de la matriz `A`.

### Inversa

Una matriz cuadrada `A` tiene una inversa `A^(-1)` si existe una matriz tal que:

A * A^(-1) = A^(-1) * A = I


donde `I` es la matriz identidad.

## Ejemplo de Código en C++

Aquí tienes un ejemplo básico de cómo definir y operar con matrices en C++:

```cpp
#include <iostream>
#include <vector>

class Matrix {
public:
    Matrix(int rows, int cols) : rows_(rows), cols_(cols), data_(rows, std::vector<double>(cols, 0)) {}

    // Método para establecer un valor en la matriz
    void set(int row, int col, double value) {
        if (row < rows_ && col < cols_) {
            data_[row][col] = value;
        }
    }

    // Método para obtener un valor de la matriz
    double get(int row, int col) const {
        if (row < rows_ && col < cols_) {
            return data_[row][col];
        }
        return 0;
    }

    // Método para imprimir la matriz
    void print() const {
        for (const auto& row : data_) {
            for (const auto& element : row) {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    int rows_, cols_;
    std::vector<std::vector<double>> data_;
};

int main() {
    Matrix mat(2, 3);
    mat.set(0, 0, 1.0);
    mat.set(0, 1, 2.0);
    mat.set(0, 2, 3.0);
    mat.set(1, 0, 4.0);
    mat.set(1, 1, 5.0);
    mat.set(1, 2, 6.0);

    std::cout << "Matriz:" << std::endl;
    mat.print();

    return 0;
}
```


