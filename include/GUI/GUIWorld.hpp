#pragma once

#include "../Graphics/Drawable.hpp"

namespace most
{
	namespace GUI
	{
		/// @brief Class managing GUI scenes. A scene is a predefined set of GUI elements eg. main menu or game GUi are 2 separate GUI scenes which are independent from each other and can be swapped between eg. when the user begins a new game.
		class World
			: public Drawable
		{
		private:
			static World* instance;
			mutable std::unique_ptr<sf::Drawable> currentScene, newScene; // Mutable because of draw's constness.
		protected:
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
			virtual void update() override {};
			virtual void physicsUpdate() override {};
		public:
			World();

			/// @brief Returns the current scene.
			/// @return Current scene
			sf::Drawable* getScene();
			/// @brief Returns the current scene.
			/// @return Current scene
			const sf::Drawable* getScene() const;
			/// @brief Sets the scene. If a scene is already present, the scene will be changed on the next draw call, otherwise immediately. This allows the scene to be changed from within the current scene.
			/// @param scene Scene to set
			void setScene(std::unique_ptr<sf::Drawable>&& scene);

			static World* getInstance();
		};
	}
}
