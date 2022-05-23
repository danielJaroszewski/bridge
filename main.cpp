#include "include/OurWorld.hpp"
#include "include/Graphics/GraphicsWorld.hpp"
#include "include/GUI/GUIWorld.hpp"

int main(int argc, char const *argv[])
{
    constexpr float gravityConstant = -9.807f;

    // Initialization.
    OurWorld physicsWorld(gravityConstant);
    most::GraphicsWorld graphics;
    most::GUI::World guiWorld;
    graphics.addDrawable(&guiWorld);

    bool shouldRun = true;
    graphics.addEventCallback([&shouldRun](const sf::Event& e)
    {
        if (e.type == sf::Event::Closed)
        {
            shouldRun = false;
        }
    });

    // Main loop.
    while (shouldRun)
    {
        graphics.processEvents();
        // TODO: Process physics here.
        graphics.present();
    }

    return 0;
}