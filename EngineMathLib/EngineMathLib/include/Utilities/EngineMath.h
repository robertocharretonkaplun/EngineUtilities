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

  // Constantes matemáticas
  constexpr float PI = 3.14159265358979323846f;
  constexpr float E = 2.71828182845904523536f;

	/**
		 * @brief Computes the square root using the Newton-Raphson method.
		 *
		 * @param value The value to compute the square root of.
		 * @return The computed square root.
		 */
	inline float sqrt(float value) {
		if (value < 0) {
			return 0; // Handle negative input gracefully.
		}
		float x = value;
		float y = 1.0f;
		float epsilon = 0.00001f; // Desired precision.
		while (x - y > epsilon) {
			x = (x + y) / 2.0f;
			y = value / x;
		}
		return x;
	}

  /**
   * @brief Calcula el cuadrado de un número.
   *
   * @param value El valor del cual se desea calcular el cuadrado.
   * @return El cuadrado del valor dado.
   */
  inline float square(float value) {
    return value * value;
  }

  /**
   * @brief Calcula el cubo de un número.
   *
   * @param value El valor del cual se desea calcular el cubo.
   * @return El cubo del valor dado.
   */
  inline float cube(float value) {
    return value * value * value;
  }

  /**
   * @brief Calcula la potencia de un número base elevado a un exponente usando el método de exponenciación rápida.
   *
   * @param base La base de la potencia.
   * @param exponent El exponente al que se eleva la base.
   * @return La base elevada al exponente.
   */
  inline float power(float base, int exponent) {
    if (exponent == 0) return 1;
    if (exponent < 0) return 1.0f / power(base, -exponent);
    float result = 1;
    while (exponent) {
      if (exponent % 2 == 1) result *= base;
      base *= base;
      exponent /= 2;
    }
    return result;
  }

  /**
   * @brief Calcula el valor absoluto de un número.
   *
   * @param value El valor del cual se desea calcular el valor absoluto.
   * @return El valor absoluto del valor dado.
   */
  inline float abs(float value) {
    return (value < 0) ? -value : value;
  }

  /**
   * @brief Devuelve el valor máximo de dos números.
   *
   * @param a El primer valor.
   * @param b El segundo valor.
   * @return El mayor de los dos valores dados.
   */
  inline float EMax(float a, float b) {
    return (a > b) ? a : b;
  }

  /**
   * @brief Devuelve el valor mínimo de dos números.
   *
   * @param a El primer valor.
   * @param b El segundo valor.
   * @return El menor de los dos valores dados.
   */
  inline float EMin(float a, float b) {
    return (a < b) ? a : b;
  }

  /**
   * @brief Redondea un número al entero más cercano.
   *
   * @param value El valor que se desea redondear.
   * @return El valor redondeado al entero más cercano.
   */
  inline float round(float value) {
    return (value > 0) ? static_cast<int>(value + 0.5f) : static_cast<int>(value - 0.5f);
  }

  /**
   * @brief Trunca un número a su parte entera, redondeando hacia abajo.
   *
   * @param value El valor que se desea truncar.
   * @return La parte entera del valor dado, redondeada hacia abajo.
   */
  inline float floor(float value) {
    int intValue = static_cast<int>(value);
    return (value < intValue) ? intValue - 1 : intValue;
  }

  /**
   * @brief Redondea un número hacia arriba al entero más cercano.
   *
   * @param value El valor que se desea redondear hacia arriba.
   * @return El valor redondeado hacia arriba al entero más cercano.
   */
  inline float ceil(float value) {
    int intValue = static_cast<int>(value);
    return (value > intValue) ? intValue + 1 : intValue;
  }

  /**
   * Calcula el valor absoluto de un número flotante.
   * @param value Valor flotante.
   * @return Valor absoluto del número flotante.
   */
  inline float fabs(float value) {
    return value < 0.0f ? -value : value;
  }

  // Funciones Trigonométricas
  /**
   * Calcula el seno de un ángulo en radianes.
   * @param angle Ángulo en radianes.
   * @return Valor del seno del ángulo.
   */
  inline float sin(float angle) {
    float result = 0.0f;
    float term = angle;
    float angle_squared = angle * angle;
    int n = 1;
    while (term > 1e-6f || term < -1e-6f) {
      result += term;
      term *= -angle_squared / ((2 * n) * (2 * n + 1));
      ++n;
    }
    return result;
  }

  /**
   * Calcula el coseno de un ángulo en radianes.
   * @param angle Ángulo en radianes.
   * @return Valor del coseno del ángulo.
   */
  inline float cos(float angle) {
    return sin(angle + PI / 2);
  }

  /**
   * Calcula la tangente de un ángulo en radianes.
   * @param angle Ángulo en radianes.
   * @return Valor de la tangente del ángulo.
   */
  inline float tan(float angle) {
    float s = sin(angle);
    float c = cos(angle);
    return c != 0.0f ? s / c : 0.0f; // Evita la división por cero
  }

  /**
   * Calcula el arco seno de un valor.
   * @param value Valor en el rango [-1, 1].
   * @return Ángulo en radianes.
   */
  inline float asin(float value) {
    // Aproximación con la serie de Taylor
    float x = value;
    float result = x;
    float term = x;
    for (int n = 1; n < 10; ++n) {
      term *= x * x * (2 * n - 1) / ((2 * n + 1) * (2 * n));
      result += term;
    }
    return result;
  }

  /**
   * Calcula el arco coseno de un valor.
   * @param value Valor en el rango [-1, 1].
   * @return Ángulo en radianes.
   */
  inline float acos(float value) {
    return PI / 2 - asin(value);
  }

  /**
   * Calcula el arco tangente de un valor.
   * @param value Valor.
   * @return Ángulo en radianes.
   */
  inline float atan(float value) {
    // Aproximación de la función arcotangente
    float result = 0.0f;
    float term = value;
    for (int n = 0; n < 10; ++n) {
      result += term / (2 * n + 1);
      term *= -value * value;
    }
    return result;
  }

  /**
   * Calcula el seno hiperbólico de un valor.
   * @param value Valor.
   * @return Seno hiperbólico.
   */
  inline float sinh(float value) {
    return (exp(value) - exp(-value)) / 2;
  }

  /**
   * Calcula el coseno hiperbólico de un valor.
   * @param value Valor.
   * @return Coseno hiperbólico.
   */
  inline float cosh(float value) {
    return (exp(value) + exp(-value)) / 2;
  }

  /**
   * Calcula la tangente hiperbólica de un valor.
   * @param value Valor.
   * @return Tangente hiperbólica.
   */
  inline float tanh(float value) {
    return sinh(value) / cosh(value);
  }

  // Conversión entre Radianes y Grados
  /**
   * Convierte grados a radianes.
   * @param degrees Ángulo en grados.
   * @return Ángulo en radianes.
   */
  inline float radians(float degrees) {
    return degrees * PI / 180.0f;
  }

  /**
   * Convierte radianes a grados.
   * @param radians Ángulo en radianes.
   * @return Ángulo en grados.
   */
  inline float degrees(float radians) {
    return radians * 180.0f / PI;
  }

  // Funciones Exponenciales y Logarítmicas
  /**
   * Calcula la función exponencial e^x.
   * @param value Exponente.
   * @return Valor de e^x.
   */
  inline float exp(float value) {
    float result = 1.0f;
    float term = 1.0f;
    for (int n = 1; n < 20; ++n) {
      term *= value / n;
      result += term;
    }
    return result;
  }

  /**
   * Calcula el logaritmo natural de un valor.
   * @param value Valor.
   * @return Logaritmo natural.
   */
  inline float log(float value) {
    // Aproximación usando la serie de Taylor
    if (value <= 0) return 0;
    float x = (value - 1) / (value + 1);
    float x2 = x * x;
    float result = 0.0f;
    float term = x;
    for (int n = 1; n < 20; ++n) {
      result += term / (2 * n - 1);
      term *= x2;
    }
    return 2 * result;
  }

  /**
   * Calcula el logaritmo en base 10 de un valor.
   * @param value Valor.
   * @return Logaritmo en base 10.
   */
  inline float log10(float value) {
    return log(value) / log(10);
  }

  // Operaciones de Redondeo Avanzadas
  /**
   * Calcula el módulo de dos números.
   * @param a Valor.
   * @param b Divisor.
   * @return Módulo.
   */
  inline float mod(float a, float b) {
    return a - b * static_cast<int>(a / b);
  }

  // Funciones de Geometría
  /**
   * Calcula el área de un círculo dado su radio.
   * @param radius Radio del círculo.
   * @return Área del círculo.
   */
  inline float circleArea(float radius) {
    return PI * radius * radius;
  }

  /**
   * Calcula la circunferencia de un círculo dado su radio.
   * @param radius Radio del círculo.
   * @return Circunferencia del círculo.
   */
  inline float circleCircumference(float radius) {
    return 2 * PI * radius;
  }

  /**
   * Calcula el área de un rectángulo dado su ancho y alto.
   * @param width Ancho del rectángulo.
   * @param height Alto del rectángulo.
   * @return Área del rectángulo.
   */
  inline float rectangleArea(float width, float height) {
    return width * height;
  }

  /**
   * Calcula el perímetro de un rectángulo dado su ancho y alto.
   * @param width Ancho del rectángulo.
   * @param height Alto del rectángulo.
   * @return Perímetro del rectángulo.
   */
  inline float rectanglePerimeter(float width, float height) {
    return 2 * (width + height);
  }

  /**
   * Calcula el área de un triángulo dado su base y altura.
   * @param base Base del triángulo.
   * @param height Altura del triángulo.
   * @return Área del triángulo.
   */
  inline float triangleArea(float base, float height) {
    return 0.5f * base * height;
  }

  /**
   * Calcula la distancia entre dos puntos en un plano bidimensional.
   * @param x1 Coordenada x del primer punto.
   * @param y1 Coordenada y del primer punto.
   * @param x2 Coordenada x del segundo punto.
   * @param y2 Coordenada y del segundo punto.
   * @return Distancia entre los dos puntos.
   */
  inline float distance(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
  }

  // Funciones de Cálculo Numérico
  /**
   * Interpola linealmente entre dos valores.
   * @param a Valor inicial.
   * @param b Valor final.
   * @param t Parámetro de interpolación entre 0 y 1.
   * @return Valor interpolado.
   */
  inline float lerp(float a, float b, float t) {
    return a + t * (b - a);
  }

  /**
   * Calcula el factorial de un número entero.
   * @param n Número entero no negativo.
   * @return Factorial de n.
   */
  inline int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
      result *= i;
    }
    return result;
  }

  /**
   * Verifica si dos valores flotantes son aproximadamente iguales.
   * @param a Primer valor.
   * @param b Segundo valor.
   * @param epsilon Margen de error.
   * @return Verdadero si los valores son aproximadamente iguales.
   */
  inline bool approxEqual(float a, float b, float epsilon) {
    return fabs(a - b) < epsilon;
  }

}
