#pragma once

#include <list>
#include <vector>

#include <SFML/Graphics.hpp>

namespace most
{
	class Level
		: public sf::Drawable
	{
	public:
		struct TerrainBlock
		{
			std::list<sf::Vector2i> hull;

			void toShape(sf::ConvexShape& shape, const float gridSize) const;
		};
	private:
		std::list<TerrainBlock> terrains;
		std::list<sf::Vector2i> permaJoints;
		sf::Vector2i carStartPos;
		std::vector<sf::ConvexShape> wholeTerrain;
		std::vector<sf::CircleShape> jointShapes;
		float jointRadius;
	private:
		/// @brief Update the internal geometry of the terrain.
		void updateTerrain();
		/// @brief Update internal shapes of permanent joints.
		void updateJointShapes();
	public:
		Level() = default;
		template<class It>
		Level(It first, It last)
			: terrains(first, last), permaJoints(), carStartPos(), wholeTerrain(), jointShapes(), jointRadius(8.0f)
		{
		}
		virtual ~Level() = default;
		Level(const Level&) = default;
		Level(Level&&) noexcept = default;

		Level& operator=(const Level&) = default;
		Level& operator=(Level&&) noexcept = default;

		template<class It>
		void setTerrain(It first, It last)
		{
			terrains.assign(first, last);
			updateTerrain();
		}
		template<class It>
		void setJoints(It first, It last)
		{
			permaJoints.assign(first, last);
			updateJointShapes();
		}
		void setCarPos(const sf::Vector2i& newPos);
		void setJointRadius(const float newRadius);

		virtual void draw(sf::RenderTarget& rt, sf::RenderStates states) const override;
	};
}
