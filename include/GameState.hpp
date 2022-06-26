#pragma once

namespace most
{
	class GameState
	{
	private:
		static GameState* instance;
	public:
		bool physicsEnabled = false;
	public:
		GameState();

		static GameState* getInstance();
	};
}
