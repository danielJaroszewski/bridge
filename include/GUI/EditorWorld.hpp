#pragma once

#include <array>

#include <SFML/Graphics.hpp>

namespace most
{
	namespace GUI
	{
		class EditorWorld
			: public sf::Drawable
		{
		private:
			enum class CurrentElement
			{
				None,
				Beam,
				Road,

				ElemsCount
			} currentElement;
			static const std::array<float, ((unsigned int)CurrentElement::ElemsCount) - 1> maxDistances;
		public:
			virtual void draw(sf::RenderTarget& rt, sf::RenderStates states) const override;
		};
	}
}
