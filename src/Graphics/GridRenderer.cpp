#include "../../include/Graphics/GridRenderer.hpp"

namespace most
{
	GridRenderer::GridRenderer(const float gridSep)
		: vertexArray(sf::PrimitiveType::Lines), gridSeparation(gridSep), dirty(true), viewport(800, 600)
	{
	}

	void GridRenderer::setGridSeparation(const float newSep)
	{
		gridSeparation = newSep;
	}

	void GridRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(vertexArray, states);
	}

	void GridRenderer::update()
	{
		if (dirty)
		{
			dirty = false;
			// TODO
		}
	}

	void GridRenderer::physicsUpdate()
	{
	}
}
