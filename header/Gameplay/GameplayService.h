#pragma once
#include <SFML/Graphics.hpp>
namespace Gameplay
{
	class GameplayController;

	class GameplayService
	{
	private:
		GameplayController* gameplay_controller;
		sf::RenderWindow* game_window = nullptr;

	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();

		void restart();
	};
}