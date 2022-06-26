#pragma once

#include <map>
#include <list>
#include <memory>
#include <functional>

#include "Drawable.hpp"

namespace most
{
	/// @brief Class containing the main window and the rendering chain.
	class GraphicsWorld
	{
	private:
		constexpr static const char* windowTitle = "pwjc-most";

		static GraphicsWorld* instance;

		sf::RenderWindow wnd;
		sf::Clock deltaClock;
		sf::View view;
		sf::Vector2f lastMousePos;
		bool viewMoving;
		sf::Texture woodTexture, roadTexture, woodLowResTexture, roadLowResTexture;

		std::map<Drawable*, std::unique_ptr<Drawable>> allDrawables;
		std::list<std::function<void(const sf::Event&)>> eventCallbacks;
	public:
		using EventCallback = decltype(eventCallbacks)::value_type;
		using EventCallbackHandle = decltype(eventCallbacks)::const_iterator;
	private:
		void loadTextures(const std::string& pathToResources);
	public:
		/// @brief Creates a new graphics world and loads the default resources.
		/// @param pathToResources Prefix added to all of resource paths. Must be empty or end with "/"
		GraphicsWorld(const std::string& pathToResources = "");
		GraphicsWorld(const GraphicsWorld&) = delete;
		GraphicsWorld(GraphicsWorld&&) noexcept = delete;
		~GraphicsWorld();

		GraphicsWorld& operator=(const GraphicsWorld&) = delete;
		GraphicsWorld& operator=(GraphicsWorld&&) noexcept = delete;

		/// @brief Called to poll events from the OS and disptach them to callbacks.
		void processEvents();
		/// @brief Used to clear the window, redraw drawables and present the result on the screen.
		void present();

		/// @brief Registers a new sf::Event callback (stuff like mouse button pressed, etc.).
		/// @param callback Callback to register
		/// @return Handle to the registered callback that can be used to remove it
		EventCallbackHandle addEventCallback(EventCallback&& callback);
		/// @brief Unregisters a callback.
		/// @param callback Callback to unregister. Use handle returned from addEventCallback.
		void removeEventCallback(const EventCallbackHandle callback);

		/// @brief Adds the provided drawable to the rendering chain.
		/// @param drawable Drawable to add
		void addDrawable(Drawable* const drawable);
		/// @brief Adds the provided drawable to the rendering chain and obtains its ownership.
		/// @tparam T Drawable type
		/// @param drawable Drawable to add
		template<class T>
		T& addDrawable(std::unique_ptr<T>&& drawable)
		{
			const auto ptr = drawable.get(); // Explicit sequencing point.
			allDrawables.emplace(ptr, std::move(drawable));
			return *ptr;
		}
		/// @brief Removes the provided drawable from the rendering chain.
		/// @param drawable Drawable to remove
		void removeDrawable(Drawable* const drawable);

		/// @brief Returns the delta time from the last frame.
		/// @return Delta time
		sf::Time getDeltaTime() const;

		/// @brief Called by main to update elements before physics world update.
		void update();
		/// @brief Called by main to update elements after physics world update (if there was one).
		void physicsUpdate();

		sf::Vector2f mousePositionToWorld(const sf::Vector2i& vec) const;

		const sf::Texture& getWoodTexture() const;
		const sf::Texture& getRoadTexture() const;
		const sf::Texture& getWoodLowResTexture() const;
		const sf::Texture& getRoadLowResTexture() const;

		static GraphicsWorld* getInstance();
	};
}
