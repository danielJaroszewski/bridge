#include "../include/GameState.hpp"

most::GameState* most::GameState::instance = nullptr;

most::GameState::GameState()
{
	instance = this;
}

most::GameState* most::GameState::getInstance()
{
	return instance;
}
