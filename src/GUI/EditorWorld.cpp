#include "../../include/GUI/GameWorld.hpp"
#include "../../include/GUI/GUIWorld.hpp"
#include "../../include/GUI/EditorWorld.hpp"

#include <imgui.h>
#include <imgui-SFML.h>

namespace most
{
	namespace GUI
	{
		void EditorWorld::draw(sf::RenderTarget& rt, sf::RenderStates states) const
		{
			if (ImGui::Begin("Toolbox"))
			{
				// TODO: ImageButtons
			}
			ImGui::End();
			if (ImGui::Begin("Play!"))
			{
				if (ImGui::Button("Play!"))
				{
					// TODO: Change scene, create physics objects, begin simulation.
					GUI::World::getInstance()->setScene(std::make_unique<GUI::GameWorld>());
				}
			}
			ImGui::End();
		}
	}
}
