#pragma once

#include <array>
#include <list>

#include "../Graphics/GraphicsWorld.hpp"

namespace most
{
	namespace GUI
	{
		class EditorWorld
			: public Drawable
		{
		public:
			enum class ElementType
			{
				None,
				Beam,
				Road,
				Remove,

				ElemsCount
			};

			struct Beam
			{
				sf::RectangleShape visuals;
				ElementType type;
			};
		private:
			static constexpr float GridSeparation = 40.0f;
			static constexpr float BeamWidth = 15.0f;

			ElementType currentElement = ElementType::None;
			static const std::array<float, ((unsigned int)ElementType::ElemsCount) - 1> maxDistances;

			bool buildInProgress;
			sf::CircleShape gridGizmo;
			sf::RectangleShape buildGizmo, ledgeLeft, ledgeRight;
			sf::Sprite woodSprite, roadSprite;
			sf::Vector2f beginBuildPos;
			GraphicsWorld::EventCallbackHandle userInteractions;
			std::list<Beam> placedBeams;
		private:
			void processEvent(const sf::Event& e);
			void setBuildGizmoTransform(const sf::Vector2f& to);
			void setCurrentElement(const ElementType type);
			sf::Vector2f globalPosToGlobalGridPos(const sf::Vector2f& pos) const;
		public:
			EditorWorld();
			~EditorWorld();

			virtual inline void physicsUpdate() override {};
			virtual void update() override;

			virtual void draw(sf::RenderTarget& rt, sf::RenderStates states) const override;
		};
	}
}
