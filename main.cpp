#include "include/OurWorld.hpp"
#include "include/Graphics/GraphicsWorld.hpp"
#include "include/GUI/GUIWorld.hpp"
#include "include/GameScene.hpp"
#include "include/Graphics/BeamVisuals.hpp"

int main(int argc, char const *argv[])
{
    OurWorld world;

    most::GraphicsWorld graphics;
    auto& guiWorld = graphics.addDrawable(std::make_unique<most::GUI::World>());

    bool shouldRun = true;
    graphics.addEventCallback([&shouldRun](const sf::Event& e)
    {
        if (e.type == sf::Event::Closed)
        {
            shouldRun = false;
        }
    });

   
    world.initializeWorld();
    world.setSimParams();
#ifdef GRA
    auto& gameScene = graphics.addDrawable(std::make_unique<most::GameScene>());
    auto level = std::make_unique<most::Level>();


    gameScene.setLevel(std::move(level));
#endif

    long long accumulatedTime = 0;
    constexpr long long fixedUpdateTime = 16666;
    // Main loop.
    while (shouldRun)
    {
        graphics.processEvents();
        graphics.update();
        accumulatedTime += graphics.getDeltaTime().asMicroseconds();
        while (accumulatedTime >= fixedUpdateTime)
        {
            accumulatedTime -= fixedUpdateTime;
            world.update();
            graphics.physicsUpdate();
        }
        graphics.present();
    }

    return 0;
}
