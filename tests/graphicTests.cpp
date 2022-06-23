#include "catch2/catch_test_macros.hpp"
#include "../include/OurWorld.hpp"
#include <iostream>
#include "../include/Graphics/GraphicsWorld.hpp"
#include "../include/GUI/GUIWorld.hpp"
#include "../include/GameScene.hpp"
#include "../include/Graphics/BeamVisuals.hpp"


TEST_CASE("single dynamic component")
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

    StaticComponent leftBase = StaticComponent(0.0f, 0.0f);
    leftBase.setUpStaticComponent();
    world.addStaticComponent(leftBase);

    StaticComponent rightBase = StaticComponent(10.0f, 0.0f);
    rightBase.setUpStaticComponent();
    world.addStaticComponent(rightBase);

    OurComponent comp1 = OurComponent(5.0f, 0.0f, 9.5f, 0.5f, 10.0f);
    comp1.setUpComponent();
    world.addComponent(comp1);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(comp1));

    OurJoint j1;
    j1.setLeftBodyStatic();
    j1.setIndexOfBodies(leftBase.getCompIndex(), comp1.getCompIndex());
    world.addJoint(j1);

    OurJoint j2;
    j2.setRightBodyStatic();
    j2.setIndexOfBodies(comp1.getCompIndex(), rightBase.getCompIndex());
    world.addJoint(j2);

    world.initializeWorld();
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
}