#include <iostream>
#include "catch2/catch_test_macros.hpp"
#include "../include/OurWorld.hpp"
#include "../include/GameScene.hpp"
#include "../include/GUI/GUIWorld.hpp"
#include "../include/Graphics/GraphicsWorld.hpp"
#include "../include/Graphics/BeamVisuals.hpp"
#include "../include/Graphics/CarVisuals.hpp"


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
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(leftBase));

    StaticComponent rightBase = StaticComponent(10.0f, 0.0f);
    rightBase.setUpStaticComponent();
    world.addStaticComponent(rightBase);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(rightBase));


    OurComponent comp1 = OurComponent(2.0f, 0.0f, 8.0f, 0.5f, 10.0f);
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

TEST_CASE("Complex test with 2+ components")
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
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(leftBase));

    StaticComponent rightBase = StaticComponent(5.0f, 0.0f);
    rightBase.setUpStaticComponent();
    world.addStaticComponent(rightBase);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(rightBase));


    OurComponent comp1 = OurComponent(-4.0f, 1.0f, 3.0f, 0.5f, 10.0f);
    comp1.setUpComponent();
    world.addComponent(comp1);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(comp1));

    OurComponent comp2 = OurComponent(9.0f, 1.0f, 3.0f, 0.5f, 10.0f);
    comp2.setUpComponent();
    world.addComponent(comp2);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(comp2));

    OurJoint j1;
    j1.setLeftBodyStatic();
    j1.setIndexOfBodies(rightBase.getCompIndex(), comp2.getCompIndex());
    world.addJoint(j1);

    OurJoint j3;
    j3.setRightBodyStatic();
    j3.setIndexOfBodies(comp1.getCompIndex(), leftBase.getCompIndex());
    world.addJoint(j3);


    world.initializeWorld();

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

TEST_CASE("Car test")
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

    Car car;
    car.setUpCar();
    world.addCar(car);
    graphics.addDrawable(std::make_unique<most::CarVisuals>(car));

    world.initializeWorld();

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