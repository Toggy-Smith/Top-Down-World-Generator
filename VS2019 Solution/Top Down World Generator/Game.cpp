#include "Game.hpp"

Game::Game(sf::RenderWindow& window)
	: window(window), player(texture_manager)
{
	texture_manager.load_texture("tileset", "assets/tileset.png");
	
	auto world_trees_tuple = world_generator.generate(400, 400);

	std::vector<std::vector<int>> world = std::get<0>(world_trees_tuple);
	std::vector<sf::Vector2i> trees = std::get<1>(world_trees_tuple);

	tree_map.load(trees, texture_manager);

	tile_map.load(world, texture_manager);

	// Find a "dry" tile to place the player on
	std::vector<sf::Vector2i> dry_tiles;

	for (unsigned int y = 0; y < world.size(); ++y) {
		for (unsigned int x = 0; x < world[y].size(); ++x) {
			if (world[y][x] != 0) {
				dry_tiles.push_back(sf::Vector2i(x, y));
			}
		}
	}

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, dry_tiles.size() - 1);

	sf::Vector2i selected_dry_tile = dry_tiles[dist(mt)];

	player.set_position(selected_dry_tile.x, selected_dry_tile.y);

	view_manager.adjust(window, player.get_position());
}

void Game::handleEvents()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		view_manager.handle_event(event);

		switch (event.type)
		{
			case sf::Event::Closed:
				window.close();

				break;
			case sf::Event::GainedFocus:
				is_window_focused = true;

				break;
			case sf::Event::LostFocus:
				is_window_focused = false;

				break;
		}
	}
}

void Game::update()
{
	static sf::Clock updateClock;

	const float elapsedTime = updateClock.getElapsedTime().asSeconds();

	tile_map.update(elapsedTime);

	player.update(elapsedTime, is_window_focused);

	view_manager.adjust(window, player.get_position());

	updateClock.restart();
}

void Game::render()
{
	window.clear();

	tile_map.render(window);

	tree_map.render(window);

	player.render(window);

	window.display();
}