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

    OurJoint j1 = OurJoint();
    j1.setLeftBodyStatic();
    j1.setIndexOfBodies(leftBase.getCompIndex(), firstBlock.getCompIndex());
    world.addJoint(j1);

    OurJoint j2 = OurJoint();
    j2.setIndexOfBodies(firstBlock.getCompIndex(), secondBlock.getCompIndex());
    world.addJoint(j2);

    OurJoint j3 = OurJoint();
    j3.setRightBodyStatic();
    j3.setIndexOfBodies(secondBlock.getCompIndex(), rightBase.getCompIndex());
    world.addJoint(j3);

    Car car = Car();
    car.setUpCar();
    world.addCar(car);

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
