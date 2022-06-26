#include "include/OurWorld.hpp"
#include "include/Graphics/GraphicsWorld.hpp"
#include "include/GUI/GUIWorld.hpp"
#include "include/GameScene.hpp"
#include "include/Graphics/BeamVisuals.hpp"
#include "include/GUI/EditorWorld.hpp"
#include "include/GameState.hpp"

#include <iostream>

int main(int argc, char const *argv[])
try
{
	most::GameState gameState;
	OurWorld physicsWorld;

	most::GraphicsWorld graphics;
	auto& guiWorld = graphics.addDrawable(std::make_unique<most::GUI::World>());
	guiWorld.setScene(std::make_unique<most::GUI::EditorWorld>());

	bool shouldRun = true;
	graphics.addEventCallback([&shouldRun](const sf::Event& e)
	{
		if (e.type == sf::Event::Closed)
		{
			shouldRun = false;
		}
	});

	long long accumulatedTime = 0;
	constexpr long long fixedUpdateTime = 16666;
	// Main loop.
	while (shouldRun)
	{
		accumulatedTime += graphics.getDeltaTime().asMicroseconds();
		graphics.processEvents();
		graphics.update();
		if (gameState.physicsEnabled)
		{
			while (accumulatedTime >= fixedUpdateTime)
			{
				accumulatedTime -= fixedUpdateTime;
				graphics.physicsUpdate();
			}
		}
		else
		{
			accumulatedTime = 0;
		}
		graphics.present();
	}

	return 0;
}
catch (const std::exception& e)
{
	std::cerr << "Application error: " << e.what() << std::endl;
	return 1;
}
catch (...)
{
	std::cerr << "Application error: UNKNOWN" << std::endl;
	return 1;
}
