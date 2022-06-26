#include "../../include/GUI/GameWorld.hpp"
#include "../../include/GUI/GUIWorld.hpp"
#include "../../include/GUI/EditorWorld.hpp"

#include <imgui.h>

namespace most
{
	namespace GUI
	{
		void GameWorld::draw(sf::RenderTarget& rt, sf::RenderStates states) const
		{
			if (ImGui::Begin("Stop"))
			{
				if (ImGui::Button("Stop"))
				{
					// TODO: Stop the simulation, reset the scene
					GUI::World::getInstance()->setScene(std::make_unique<GUI::EditorWorld>());
				}
			}
			ImGui::End();
		}
	}
}
