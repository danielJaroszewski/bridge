#pragma once

#include "Drawable.hpp"

namespace most
{
	class GridRenderer
		: public Drawable
	{
	private:
		mutable sf::VertexArray vertexArray;
		float gridSeparation;
	public:
		GridRenderer();

		void setGridSeparation(const float newSep);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		virtual void update() override;
		virtual void physicsUpdate() override;
	};
}
