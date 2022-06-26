#include "../../include/Graphics/GridRenderer.hpp"

namespace most
{
	GridRenderer::GridRenderer()
		: vertexArray(sf::PrimitiveType::Lines)
	{
	}

	void GridRenderer::setGridSeparation(const float newSep)
	{
		gridSeparation = newSep;
	}

	void GridRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// TODO
	}

	void GridRenderer::update()
	{
	}

	void GridRenderer::physicsUpdate()
	{
	}
}
