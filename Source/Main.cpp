#include "SFML/Graphics.hpp"

#include "Game.hpp"

int main()
{
	const int         WINDOW_WIDTH  = 800;
	const int         WINDOW_HEIGHT = 800;
	const std::string WINDOW_TITLE  = "Top Down World Generator";

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);

	Game game(window);

	while (window.isOpen())
	{
		game.handleEvents();

		game.update();

		game.render();
	}
}