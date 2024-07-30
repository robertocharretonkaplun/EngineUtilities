# EngineUtilities

EngineUtilities es una biblioteca de recursos matemáticos y estructuras de datos diseñada para motores de juegos personalizados. Proporciona una serie de utilidades para realizar operaciones matemáticas, manejar punteros, y trabajar con estructuras de datos comunes en el desarrollo de motores de juego.

## Contenido del Repositorio

### Include
La carpeta `include` contiene los encabezados para las diversas clases y utilidades proporcionadas por la biblioteca.

#### Matrix
Clases para manejar matrices de diferentes tamaños:
- `Matrix2x2.h`
- `Matrix3x3.h`
- `Matrix4x4.h`

#### Memory
Clases para manejar punteros inteligentes personalizados:
- `TSharedPointer.h` - Implementación de un puntero compartido.
- `TStaticPtr.h` - Implementación de un puntero estático.
- `TUniquePtr.h` - Implementación de un puntero único.
- `TWeakPointer.h` - Implementación de un puntero débil.

#### Structures
Clases para manejar estructuras de datos comunes:
- `TArray.h` - Implementación de un arreglo dinámico.
- `TMap.h` - Implementación de un mapa (diccionario).
- `TPair.h` - Implementación de un par.
- `TSet.h` - Implementación de un conjunto.

#### Utilities
Utilidades matemáticas generales:
- `EngineMath.h` - Funciones matemáticas generales para el motor.

#### Vectors
Clases para manejar vectores y cuaterniones:
- `Quaternion.h` - Implementación de cuaterniones para rotaciones.
- `Vector2.h` - Implementación de vectores en 2D.
- `Vector3.h` - Implementación de vectores en 3D.
- `Vector4.h` - Implementación de vectores en 4D.

### Source
La carpeta `source` contendría las implementaciones de las clases y funciones definidas en los archivos de encabezado. Asegúrate de explorar esta carpeta para obtener ejemplos y detalles adicionales sobre cómo utilizar estas utilidades.

## Uso

Para utilizar esta biblioteca en tu proyecto, simplemente incluye los archivos de encabezado necesarios y compila tu proyecto junto con los archivos de implementación. A continuación se muestra un ejemplo de cómo incluir y usar la clase `Vector3`:

```cpp
#include "Vectors/Vector3.h"

int main() {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2(4.0f, 5.0f, 6.0f);
    Vector3 result = v1 + v2;

    std::cout << "Resultado: " << result.x << ", " << result.y << ", " << result.z << std::endl;
    return 0;
}
```

## Contribuciones
Las contribuciones son bienvenidas. Si deseas contribuir a este proyecto, por favor abre un issue o envía un pull request con tus mejoras o correcciones.

## Licencia
Este proyecto está licenciado bajo los términos de la licencia MIT. Consulta el archivo LICENSE para más detalles.