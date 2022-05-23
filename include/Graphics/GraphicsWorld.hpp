#pragma once

#include <map>
#include <list>
#include <memory>
#include <functional>

#include <SFML/Graphics.hpp>

namespace most
{
	/// @brief Class containing the main window and the rendering chain.
	class GraphicsWorld
	{
	private:
		constexpr static const char* windowTitle = "pwjc-most";
		sf::RenderWindow wnd;

		std::map<sf::Drawable*, std::unique_ptr<sf::Drawable>> allDrawables;
		std::list<std::function<void(const sf::Event&)>> eventCallbacks;

		using EventCallback = decltype(eventCallbacks)::value_type;
		using EventCallbackHandle = decltype(eventCallbacks)::const_iterator;
	public:
		GraphicsWorld();
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
		void addDrawable(sf::Drawable* const drawable);
		/// @brief Adds the provided drawable to the rendering chain and obtains its ownership.
		/// @param drawable Drawable to add
		void addDrawable(std::unique_ptr<sf::Drawable>&& drawable);
		/// @brief Removes the provided drawable from the rendering chain.
		/// @param drawable Drawable to remove
		void removeDrawable(sf::Drawable* const drawable);
	};
}
