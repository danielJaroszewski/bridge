#include <iostream>
#include "catch2/catch_test_macros.hpp"
#include "../include/OurWorld.hpp"
#include "../include/GameScene.hpp"
#include "../include/GUI/GUIWorld.hpp"
#include "../include/Graphics/GraphicsWorld.hpp"
#include "../include/Graphics/BeamVisuals.hpp"
#include "../include/Graphics/CarVisuals.hpp"

/*
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


    OurComponent comp1 = OurComponent(5.0f, 0.0f, 9.0f, 0.5f, 10.0f);
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

TEST_CASE("bridge test")
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

    StaticComponent leftBase(0.0f,0.0f);
    leftBase.setUpStaticComponent();
    world.addStaticComponent(leftBase);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(leftBase));


    StaticComponent rightBase(10.0f, 0.0f);
    rightBase.setUpStaticComponent();
    world.addStaticComponent(rightBase);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(rightBase));

    OurComponent firstBlock(2.5f,0.0f,4.9f, 0.5f, 10.0f);
    firstBlock.setUpComponent();
    world.addComponent(firstBlock);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(firstBlock));

    OurComponent secondBlock(7.5f, 0.0f, 5.0f, 0.5f, 10.0f);
    secondBlock.setUpComponent();
    world.addComponent(secondBlock);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(secondBlock));

    OurJoint j1;
    j1.setLeftBodyStatic();
    j1.setIndexOfBodies(leftBase.getCompIndex(), firstBlock.getCompIndex());
    world.addJoint(j1);

    OurJoint j2;
    j2.setIndexOfBodies(firstBlock.getCompIndex(), secondBlock.getCompIndex());
    world.addJoint(j2);

    OurJoint j3;
    j3.setRightBodyStatic();
    j3.setIndexOfBodies(secondBlock.getCompIndex(), rightBase.getCompIndex());
    world.addJoint(j3);

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
*/

TEST_CASE("Bridge test full")
{
    OurWorld world;
    most::GraphicsWorld graphics;

    auto &guiWorld = graphics.addDrawable(std::make_unique<most::GUI::World>());
    bool shouldRun = true;
    graphics.addEventCallback([&shouldRun](const sf::Event &e)
                              {
        if (e.type == sf::Event::Closed)
        {
            shouldRun = false;
        } });

    StaticComponent leftBase(0.0f, 0.0f);
    leftBase.setUpStaticComponent();
    world.addStaticComponent(leftBase);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(leftBase));

    StaticComponent rightBase(15.0f, 0.0f);
    rightBase.setUpStaticComponent();
    world.addStaticComponent(rightBase);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(rightBase));

    StaticComponent middleBase(6.5f, 5.0f);
    middleBase.setUpStaticComponent();
    world.addStaticComponent(middleBase);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(middleBase));

    OurComponent firstBlock(1.0f, 0.0f, 3.0f, 0.5f, 10.0f);
    firstBlock.setUpComponent();
    world.addComponent(firstBlock);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(firstBlock));

    OurComponent secondBlock(5.0f, 0.0f, 3.0f, 0.5f, 10.0f);
    secondBlock.setUpComponent();
    world.addComponent(secondBlock);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(secondBlock));

    OurComponent thirdBlock(9.0f, 0.0f, 3.0f, 0.5f, 10.0f);
    thirdBlock.setUpComponent();
    world.addComponent(thirdBlock);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(thirdBlock));

    OurJoint j1;
    j1.setLeftBodyStatic();
    j1.setIndexOfBodies(leftBase.getCompIndex(), firstBlock.getCompIndex());
    world.addJoint(j1);

    OurJoint j2;
    j2.setIndexOfBodies(firstBlock.getCompIndex(), secondBlock.getCompIndex());
    world.addJoint(j2);

    OurJoint j3;
    j3.setIndexOfBodies(secondBlock.getCompIndex(), thirdBlock.getCompIndex());
    world.addJoint(j3);

    OurJoint j4;
    j4.setRightBodyStatic();
    j4.setIndexOfBodies(thirdBlock.getCompIndex(), rightBase.getCompIndex());
    world.addJoint(j4);

    OurJoint j5;
    j5.setRightBodyStatic();
    j5.setIndexOfBodies(firstBlock.getCompIndex(), middleBase.getCompIndex());
    world.addJoint(j5);

    OurJoint j6;
    j6.setLeftBodyStatic();
    j6.setIndexOfBodies(middleBase.getCompIndex(), thirdBlock.getCompIndex());
    world.addJoint(j6);

    world.initializeWorld();

#ifdef GRA
    auto &gameScene = graphics.addDrawable(std::make_unique<most::GameScene>());
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