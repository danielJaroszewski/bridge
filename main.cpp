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

    OurComponent leftBase = OurComponent(1.0f, 1.0f, 50.0f, 10.0f, 50.0f);
    leftBase.createBodyDefinition();
    leftBase.createBodyFixtureDefinition();
    world.addComponent(leftBase);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(leftBase));

    OurComponent rightBase = OurComponent(150.0f, 1.0f, 50.0f, 10.0f, 50.0f);
    rightBase.createBodyDefinition();
    rightBase.createBodyFixtureDefinition();
    world.addComponent(rightBase);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(rightBase));

    OurComponent comp1 = OurComponent(50.0f, 25.0f, 10.0f, 1.0f, 50.0f);
    comp1.createBodyDefinition();
    comp1.createBodyFixtureDefinition();
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(comp1));

    OurComponent comp2 = OurComponent(65.0f, 25.0f, 10.0f, 1.0f, 50.0f);
    comp2.createBodyDefinition();
    comp2.createBodyFixtureDefinition();
    world.addComponent(comp1);
    world.addComponent(comp2);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(comp2));

    OurJoint joint1 = OurJoint();
    joint1.setIndexOfBodies(0,1);
    world.addJoint(joint1);
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
