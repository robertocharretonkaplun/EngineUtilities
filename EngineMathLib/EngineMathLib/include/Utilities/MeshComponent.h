#pragma once

#include <iostream>
#include "Structures/TArray.h"
#include "Vectors/Vector2.h"
#include "Vectors/Vector3.h"

class DeviceContext;

namespace EU {

	/**
	 * @brief Estructura que representa un vértice en el espacio 3D.
	 * Contiene una posición 3D y coordenadas de textura 2D.
	 */
	struct Vertex {
		EU::Vector3 Pos;  ///< Posición del vértice en el espacio 3D.
		EU::Vector2 Tex;  ///< Coordenadas de textura del vértice.
	};

	/**
	 * @brief Componente de malla que contiene información de geometría.
	 *
	 * Esta clase almacena los vértices e índices necesarios para representar
	 * una malla 3D, así como métodos básicos para inicialización, actualización,
	 * renderizado y destrucción.
	 *
	 * Nota: Actualmente no hereda de una clase `Component`, pero está preparado para ello.
	 */
	class MeshComponent /*: public Component*/ {
	public:
		/**
		 * @brief Constructor por defecto.
		 * Inicializa el componente con 0 vértices e índices.
		 */
		MeshComponent() : m_numVertex(0), m_numIndex(0)/*, Component(ComponentType::MESH)*/ {}

		/**
		 * @brief Destructor virtual por defecto.
		 */
		virtual ~MeshComponent() = default;

		/**
		 * @brief Inicializa el componente.
		 * Actualmente es un placeholder para lógica de inicialización personalizada.
		 */
		void init() /*override*/ {}

		/**
		 * @brief Actualiza el componente de malla.
		 *
		 * @param deltaTime Tiempo transcurrido desde la última actualización.
		 * @param deviceContext Contexto del dispositivo gráfico (no utilizado actualmente).
		 */
		void update(float deltaTime) /*override*/ {}

		/**
		 * @brief Renderiza la malla utilizando el contexto del dispositivo gráfico.
		 *
		 * @param deviceContext Referencia al contexto del dispositivo gráfico.
		 */
		void render(DeviceContext& deviceContext) /*override*/ {}

		/**
		 * @brief Libera los recursos asociados al componente.
		 */
		void destroy() /*override*/ {}

	public:
		std::string m_name;                     ///< Nombre del componente o malla.
		unsigned int m_numVertex;              ///< Número de vértices en la malla.
		unsigned int m_numIndex;               ///< Número de índices en la malla.
		EngineUtilities::TArray<Vertex> m_vertex; ///< Arreglo de vértices.
		EngineUtilities::TArray<unsigned int> m_index; ///< Arreglo de índices.
	};

} // namespace EU
