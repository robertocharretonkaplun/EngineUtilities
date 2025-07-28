#pragma once

#include <iostream>
#include "Structures/TArray.h"
#include "Vectors/Vector2.h"
#include "Vectors/Vector3.h"

class DeviceContext;

namespace EU {

	/**
	 * @brief Estructura que representa un v�rtice en el espacio 3D.
	 * Contiene una posici�n 3D y coordenadas de textura 2D.
	 */
	struct Vertex {
		EU::Vector3 Pos;  ///< Posici�n del v�rtice en el espacio 3D.
		EU::Vector2 Tex;  ///< Coordenadas de textura del v�rtice.
	};

	/**
	 * @brief Componente de malla que contiene informaci�n de geometr�a.
	 *
	 * Esta clase almacena los v�rtices e �ndices necesarios para representar
	 * una malla 3D, as� como m�todos b�sicos para inicializaci�n, actualizaci�n,
	 * renderizado y destrucci�n.
	 *
	 * Nota: Actualmente no hereda de una clase `Component`, pero est� preparado para ello.
	 */
	class MeshComponent /*: public Component*/ {
	public:
		/**
		 * @brief Constructor por defecto.
		 * Inicializa el componente con 0 v�rtices e �ndices.
		 */
		MeshComponent() : m_numVertex(0), m_numIndex(0)/*, Component(ComponentType::MESH)*/ {}

		/**
		 * @brief Destructor virtual por defecto.
		 */
		virtual ~MeshComponent() = default;

		/**
		 * @brief Inicializa el componente.
		 * Actualmente es un placeholder para l�gica de inicializaci�n personalizada.
		 */
		void init() /*override*/ {}

		/**
		 * @brief Actualiza el componente de malla.
		 *
		 * @param deltaTime Tiempo transcurrido desde la �ltima actualizaci�n.
		 * @param deviceContext Contexto del dispositivo gr�fico (no utilizado actualmente).
		 */
		void update(float deltaTime) /*override*/ {}

		/**
		 * @brief Renderiza la malla utilizando el contexto del dispositivo gr�fico.
		 *
		 * @param deviceContext Referencia al contexto del dispositivo gr�fico.
		 */
		void render(DeviceContext& deviceContext) /*override*/ {}

		/**
		 * @brief Libera los recursos asociados al componente.
		 */
		void destroy() /*override*/ {}

	public:
		std::string m_name;                     ///< Nombre del componente o malla.
		unsigned int m_numVertex;              ///< N�mero de v�rtices en la malla.
		unsigned int m_numIndex;               ///< N�mero de �ndices en la malla.
		EngineUtilities::TArray<Vertex> m_vertex; ///< Arreglo de v�rtices.
		EngineUtilities::TArray<unsigned int> m_index; ///< Arreglo de �ndices.
	};

} // namespace EU
