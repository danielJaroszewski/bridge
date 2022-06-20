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

    OurComponent leftBlock = OurComponent(0.0f, 0.0f, 4.9f, 0.5f, 10.0f);
    leftBlock.setUpComponent();
    world.addComponent(leftBlock);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(leftBlock));

    OurComponent rightBlock = OurComponent(10.0f, 0.0f, 4.9f, 0.5f, 10.0f);
    rightBlock.setUpComponent();
    world.addComponent(rightBlock);

    OurJoint j1 = OurJoint();
    j1.setIndexOfBodies(leftBlock.getCompIndex(), rightBlock.getCompIndex());
    j1.setLinearStiffness();
    world.addJoint(j1);


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
