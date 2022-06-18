#include "../include/Level.hpp"
#include "../include/CommonDefs.hpp"

#include <SFML/Graphics.hpp>

namespace most
{
	void Level::TerrainBlock::toShape(sf::ConvexShape& shape, const float gridSize) const
	{
		shape.setPointCount(hull.size());
		shape.setFillColor(sf::Color(86, 219, 117));
		unsigned int counter = 0;
		for (const auto& x : hull)
		{
			shape.setPoint(counter++, sf::Vector2f(x.x, x.y) * gridSize);
		}
	}

	void Level::updateTerrain()
	{
		wholeTerrain.resize(terrains.size());
		auto it = terrains.begin();
		for (auto& x : wholeTerrain)
		{
			(it++)->toShape(x, constants::gridSize);
		}
	}

	void Level::updateJointShapes()
	{
		jointShapes.resize(permaJoints.size());
		auto it = jointShapes.begin();
		for (const auto& x : permaJoints)
		{
			it->setPosition(x.x * constants::gridSize, x.y * constants::gridSize);
			(it++)->setRadius(jointRadius);
		}
	}

	void Level::setCarPos(const sf::Vector2i& newPos)
	{
		carStartPos = newPos;
	}

	void Level::setJointRadius(const float newRadius)
	{
		jointRadius = newRadius;
		updateJointShapes();
	}

	void Level::draw(sf::RenderTarget& rt, sf::RenderStates states) const
	{
		for (const auto& x : wholeTerrain)
		{
			rt.draw(x, states);
		}
	}
}
