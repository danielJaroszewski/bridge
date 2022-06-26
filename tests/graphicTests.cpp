#include "../include/OurWorld.hpp"
#include "../include/Graphics/GraphicsWorld.hpp"
#include "../include/GUI/GUIWorld.hpp"
#include "../include/GameScene.hpp"
#include "../include/Graphics/BeamVisuals.hpp"
#include "catch2/catch_test_macros.hpp"
#include <iostream>


TEST_CASE("3 element bridge")
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

    StaticComponent leftBase  = StaticComponent(-0.2f, 0.0f);
    leftBase.setUpStaticComponent();
    world.addStaticComponent(leftBase);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(leftBase));

    StaticComponent rightBase = StaticComponent(10.0f, 0.0f);
    rightBase.setUpStaticComponent();
    world.addStaticComponent(rightBase);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(rightBase));

    OurComponent comp1 = OurComponent(1.65f, 0.25f, 3.4f, 0.5f, 0.0f);
    comp1.setUpComponent();
    world.addComponent(comp1);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(comp1));

    OurComponent comp2 = OurComponent(5.0f, 0.25f, 3.4f, 0.5f, 0.0f);
    comp2.setUpComponent();
    world.addComponent(comp2);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(comp2));

    OurComponent comp3 = OurComponent(8.3f, 0.25f, 3.4f, 0.5f, 0.0f);
    comp3.setUpComponent();
    world.addComponent(comp3);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(comp3));

    OurComponent comp4 = OurComponent(3.0f, 3.0f, 2.0f, 1.0f, 90.0f);
    comp4.setUpComponent();
    world.addComponent(comp4);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(comp4));


    JoiningPoint jp1 = JoiningPoint(0.0f, 0.0f);
    jp1.setUpJoiningPoint();
    world.addJoiningPoint(jp1);
    JoiningPoint jp2 = JoiningPoint(3.3f, 0.0f);
    jp2.setUpJoiningPoint();
    world.addJoiningPoint(jp2);
    JoiningPoint jp3 = JoiningPoint(6.6f, 0.0f);
    jp3.setUpJoiningPoint();
    world.addJoiningPoint(jp3);
    JoiningPoint jp4 = JoiningPoint(10.0f, 0.0f);
    jp4.setUpJoiningPoint();
    world.addJoiningPoint(jp4);


    OurJoint j1;
    j1.setIndexOfBodies(leftBase.getCompIndex(), jp1.getIndex());
    j1.setBBodyJoiningPoint();
    world.addJoint(j1);

    OurJoint j2;
    j2.setIndexOfBodies(jp1.getIndex(), comp1.getCompIndex());
    j2.setABodyJoiningPoint();
    world.addJoint(j2);

    OurJoint j3;
    j3.setIndexOfBodies(comp1.getCompIndex(), jp2.getIndex());
    j3.setBBodyJoiningPoint();
    world.addJoint(j3);

    OurJoint j4;
    j4.setIndexOfBodies(jp2.getIndex(), comp2.getCompIndex());
    j4.setABodyJoiningPoint();
    world.addJoint(j4);

    OurJoint j5;
    j5.setIndexOfBodies(comp2.getCompIndex(), jp3.getIndex());
    j5.setBBodyJoiningPoint();
    world.addJoint(j5);

    OurJoint j6;
    j6.setIndexOfBodies(jp3.getIndex(), comp3.getCompIndex());
    j6.setABodyJoiningPoint();
    world.addJoint(j6);

    OurJoint j7;
    j7.setIndexOfBodies(comp3.getCompIndex(), jp4.getIndex());
    j7.setBBodyJoiningPoint();
    world.addJoint(j7);

    OurJoint j8;
    j8.setIndexOfBodies(jp4.getIndex(), rightBase.getCompIndex());
    j8.setABodyJoiningPoint();
    world.addJoint(j8);


    world.initializeWorld();
    std::cout<<"Position: "<<comp1.getXCoordinate()<<"  "<<comp1.getYCoordinate()<<"\n";

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
        accumulatedTime += graphics.getDeltaTime().asMicroseconds();
        graphics.processEvents();
        graphics.update();
        while (accumulatedTime >= fixedUpdateTime)
        {
            accumulatedTime -= fixedUpdateTime;
            world.update();
            graphics.physicsUpdate();
        }
        graphics.present();
       
    }
}

TEST_CASE("angles")
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

    OurComponent comp1 = OurComponent(0.0f, 0.0f, 2.5f, 0.5f, 45);
    comp1.setUpComponent();
    world.addComponent(comp1);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(comp1));
    world.initializeWorld();
    // b2Vec2 leftAnchor = comp1.getLeftAnchorPoint();
    // b2Vec2 rightAnchor = comp1.getRightAnchorPoint();

    // std::cout<<"Left anchor point x: "<<leftAnchor.x<<"   y: "<<leftAnchor.y<<"\n";
    // std::cout<<"Right anchor point x: "<<rightAnchor.x<<"   y: "<<rightAnchor.y<<"\n";
    // std::cout<<"Position: "<<comp1.getXCoordinate()<<"  "<<comp1.getYCoordinate()<<"\n";
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
        accumulatedTime += graphics.getDeltaTime().asMicroseconds();
        graphics.processEvents();
        graphics.update();
        while (accumulatedTime >= fixedUpdateTime)
        {
            accumulatedTime -= fixedUpdateTime;
            world.update();
            graphics.physicsUpdate();
        }
        graphics.present();
    }
}


TEST_CASE("with ledges")
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

    Ledge ledge1 = Ledge(-10.0f, -0.5f);
    ledge1.setUpLedge();
    world.addLedge(ledge1);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(ledge1));

    Ledge ledge2 = Ledge(20.0f, -0.5f);
    ledge2.setUpLedge();
    world.addLedge(ledge2); 
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(ledge2));   

    b2Vec2 lb = ledge1.getRightEdgeCoordinates();
    b2Vec2 rb = ledge2.getLeftEdgeCoordiantes();

    StaticComponent leftBase = StaticComponent(0.0f, 0.0f);
    leftBase.setUpStaticComponent();
    world.addStaticComponent(leftBase);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(leftBase));


    StaticComponent rightBase = StaticComponent(10.0f, 0.0f);
    rightBase.setUpStaticComponent();
    world.addStaticComponent(rightBase);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(rightBase));


    JoiningPoint jp1 = JoiningPoint(0.0f, 0.0f);
    jp1.setUpJoiningPoint();
    world.addJoiningPoint(jp1);


    JoiningPoint jp2 = JoiningPoint(5.0f, 0.0f);
    jp2.setUpJoiningPoint();
    world.addJoiningPoint(jp2);

    JoiningPoint jp3 = JoiningPoint(10.0f, 0.0f);
    jp3.setUpJoiningPoint();
    world.addJoiningPoint(jp3);


    OurComponent comp1 = OurComponent(2.5f, 0.0f, 5.5f, 0.5f, 0.0f);
    comp1.setUpComponent();
    world.addComponent(comp1);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(comp1));

    OurComponent comp2 = OurComponent(7.5f, 0.0f, 5.5f, 0.5f, 0.0f);
    comp2.setUpComponent();
    world.addComponent(comp2);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(comp2));


    OurJoint j1;
    j1.setIndexOfBodies(leftBase.getCompIndex(), jp1.getIndex());
    j1.setBBodyJoiningPoint();
    world.addJoint(j1);

    OurJoint j2;
    j2.setIndexOfBodies(jp1.getIndex(), comp1.getCompIndex());
    j2.setABodyJoiningPoint();
    world.addJoint(j2);

    OurJoint j3;
    j3.setIndexOfBodies(comp1.getCompIndex(), jp2.getIndex());
    j3.setBBodyJoiningPoint();
    world.addJoint(j3);

    OurJoint j4;
    j4.setIndexOfBodies(jp2.getIndex(), comp2.getCompIndex());
    j4.setABodyJoiningPoint();
    world.addJoint(j4);

    OurJoint j5;
    j5.setIndexOfBodies(comp2.getCompIndex(), jp3.getIndex());
    j5.setBBodyJoiningPoint();
    world.addJoint(j5);

    OurJoint j6;
    j6.setIndexOfBodies(jp3.getIndex(), rightBase.getCompIndex());
    j6.setBBodyJoiningPoint();
    world.addJoint(j6);


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
        accumulatedTime += graphics.getDeltaTime().asMicroseconds();
        graphics.processEvents();
        graphics.update();
        while (accumulatedTime >= fixedUpdateTime)
        {
            accumulatedTime -= fixedUpdateTime;
            world.update();
            graphics.physicsUpdate();
        }
        graphics.present();
    }
}