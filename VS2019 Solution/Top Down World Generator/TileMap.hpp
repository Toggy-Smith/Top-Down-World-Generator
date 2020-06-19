#pragma once

#include "SFML/Graphics.hpp"

#include <iostream>
#include <vector>

#include "TextureManager.hpp"

class TileMap {
	private:
		sf::VertexArray vertex_array;
		sf::RenderStates render_states;

		const float TILE_SIZE = 32;
		const float MAP_SCALE = 2.0f;//0.05f;

	public:
		sf::Vector2f get_texture_coords(const int tile_ID);
		void load(std::vector<std::vector<int>>&, TextureManager&);
		void update(const float);
		void render(sf::RenderWindow&);
};