#include "include/OurWorld.hpp"
#include "include/Graphics/GraphicsWorld.hpp"
#include "include/GUI/GUIWorld.hpp"
#include "include/GameScene.hpp"
#include "include/Graphics/BeamVisuals.hpp"
#include "include/GUI/EditorWorld.hpp"

#include <iostream>

int main(int argc, char const *argv[])
try
{
    OurWorld world;

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

    StaticComponent leftBase  = StaticComponent(0.0f, 0.0f);
    leftBase.setUpStaticComponent();
    world.addStaticComponent(leftBase);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(leftBase));

    StaticComponent rightBase = StaticComponent(5.0f, 0.0f);
    rightBase.setUpStaticComponent();
    world.addStaticComponent(rightBase);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(rightBase));

    JoiningPoint jp1 = JoiningPoint(0.0f, 0.0f);
    jp1.setUpJoiningPoint();
    world.addJoiningPoint(jp1);

    JoiningPoint jp2 = JoiningPoint(5.0f, 0.0f); //creating joining points in the same place
    jp2.setUpJoiningPoint();
    world.addJoiningPoint(jp2);

    OurComponent comp1 = OurComponent(0.0f, 0.0f, 5.0f, 0.5f, 10.0f); //it turns out, that coodrinates are left top corner, not center
    comp1.setUpComponent();
    comp1.setReturningLeftAnchor();
    world.addComponent(comp1);
    graphics.addDrawable(std::make_unique<most::BeamVisuals>(comp1));

    OurJoint j1 = OurJoint();
    j1.setIndexOfBodies(leftBase.getCompIndex(), jp1.getIndex());
    j1.setBBodyJoiningPoint();
    world.addJoint(j1);

    OurJoint j2 = OurJoint();
    j2.setIndexOfBodies(jp1.getIndex(), comp1.getCompIndex());
    j2.setABodyJoiningPoint();
    world.addJoint(j2);
    comp1.setReturningRightAnchor();

    OurJoint j3;
    j3.setIndexOfBodies(comp1.getCompIndex(), jp2.getIndex());
    j3.setBBodyJoiningPoint();
    world.addJoint(j3);

    OurJoint j4;
    j4.setIndexOfBodies(jp2.getIndex(), rightBase.getCompIndex());
    j4.setABodyJoiningPoint();
    world.addJoint(j4);



   
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
