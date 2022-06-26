#pragma once

#include <cmath>

#include <SFML/System.hpp>

#if __cplusplus >= 201703L
#define FALLTHROUGH [[fallthrough]];
#else
#define FALLTHROUGH // fall through
#endif

namespace most
{
	constexpr float Pi = 3.14159265358979323846;

	inline sf::Vector2f operator-(const sf::Vector2f& a, const sf::Vector2f& b)
	{
		return sf::Vector2f(a.x - b.x, a.y - b.y);
	}

	inline float dot(const sf::Vector2f& a, const sf::Vector2f& b)
	{
		return (a.x * b.x) + (a.y * b.y);
	}

	inline float magnitude(const sf::Vector2f& vec)
	{
		return std::sqrt(dot(vec, vec));
	}

	inline sf::Vector2f normalize(const sf::Vector2f& vec, const float mag)
	{
		return sf::Vector2f(vec.x / mag, vec.y / mag);
	}

	inline sf::Vector2f normalize(const sf::Vector2f& vec)
	{
		return normalize(vec, magnitude(vec));
	}

	inline float distance(const sf::Vector2f& a, const sf::Vector2f& b)
	{
		return magnitude(a - b);
	}

	inline float clamp(const float value, const float min, const float max)
	{
		return std::max(std::min(value, max), min);
	}

	inline float rad2deg(const float rad)
	{
		return rad / Pi * 180.0f;
	}

	inline float deg2rad(const float deg)
	{
		return deg / 180.0f * Pi;
	}

	class Rectangle
	{
	private:

	};
}
