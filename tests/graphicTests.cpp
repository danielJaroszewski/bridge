#include "../include/OurWorld.hpp"
#include "../include/Graphics/GraphicsWorld.hpp"
#include "../include/GUI/GUIWorld.hpp"
#include "../include/GameScene.hpp"
#include "../include/Graphics/BeamVisuals.hpp"
#include "catch2/catch_test_macros.hpp"


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

    StaticComponent leftBase  = StaticComponent(0.0f, 0.0f);
    leftBase.setUpStaticComponent();
    world.addStaticComponent(leftBase);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(leftBase));

    StaticComponent rightBase = StaticComponent(10.0f, 0.0f);
    rightBase.setUpStaticComponent();
    world.addStaticComponent(rightBase);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(rightBase));

    OurComponent comp1 = OurComponent(0.0f, 0.0f, 3.4f, 0.5f, 1.0f);
    comp1.setUpComponent();
    world.addComponent(comp1);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(comp1));

    OurComponent comp2 = OurComponent(3.3f, 0.0f, 3.4f, 0.5f, 1.0f);
    comp2.setUpComponent();
    world.addComponent(comp2);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(comp2));

    OurComponent comp3 = OurComponent(6.6f, 0.0f, 3.4f, 0.5f, 1.0f);
    comp3.setUpComponent();
    world.addComponent(comp3);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(comp3));

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