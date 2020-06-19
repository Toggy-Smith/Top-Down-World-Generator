#pragma once

#include "SFML/Graphics.hpp"

#include "TextureManager.hpp"
#include "TileMap.hpp"
#include "WorldGenerator.hpp"
#include "Player.hpp"
#include "ViewManager.hpp"
#include "TreeMap.hpp"

#include <random>
#include <tuple>

class Game
{
	private:
		sf::RenderWindow& window;

		TextureManager texture_manager;
		TileMap tile_map;
		WorldGenerator world_generator;
		Player player;
		ViewManager view_manager;
		TreeMap tree_map;

		bool is_window_focused = true;

	public:
		     Game         (sf::RenderWindow&);

		void handleEvents ();
		void update       ();
		void render       ();
};