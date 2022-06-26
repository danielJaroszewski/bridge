#pragma once

#include "Drawable.hpp"

namespace most
{
	class GridRenderer
		: public Drawable
	{
	private:
		sf::VertexArray vertexArray;
		float gridSeparation;
		bool dirty;
		sf::Vector2f viewport;
	public:
		GridRenderer(const float gridSep);

		void setGridSeparation(const float newSep);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		virtual void update() override;
		virtual void physicsUpdate() override;
	};
}
