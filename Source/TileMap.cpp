#include "TileMap.hpp"

sf::Vector2f TileMap::get_texture_coords(const int tile_ID) {
	switch (tile_ID) {
		case 0: // water
			return sf::Vector2f(0.0f, 0.0f);
		case 1: // sand
			return sf::Vector2f(TILE_SIZE, 0.0f);
		case 2: // grass
			return sf::Vector2f(TILE_SIZE * 2.0f, 0.0f);
		case 3: // rock
			return sf::Vector2f(TILE_SIZE * 3.0f, 0.0f);
		case 4: // snow
			return sf::Vector2f(TILE_SIZE * 4.0f, 0.0f);
	}

	std::cerr << "Error: TileMap received an unknown tile ID.\n";

	return sf::Vector2f(0.0f, 0.0f);
}

void TileMap::load(std::vector<std::vector<int>>& world, TextureManager& texture_manager) {
	vertex_array.setPrimitiveType(sf::Quads);

	sf::Transform transform;

	transform.scale(sf::Vector2f(MAP_SCALE, MAP_SCALE));

	render_states.transform *= transform;
	render_states.texture = texture_manager.get_texture("tileset");

	for (unsigned int y = 0; y < world.size(); ++y) {
		for (unsigned int x = 0; x < world[y].size(); ++x) {
			sf::Vertex top_left, top_right, bottom_left, bottom_right;

			top_left.position = sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE);
			top_right.position = sf::Vector2f(top_left.position.x + TILE_SIZE, top_left.position.y);
			bottom_left.position = sf::Vector2f(top_left.position.x, top_left.position.y + TILE_SIZE);
			bottom_right.position = sf::Vector2f(top_right.position.x, bottom_left.position.y);

			top_left.texCoords = get_texture_coords(world[y][x]);
			top_right.texCoords = sf::Vector2f(top_left.texCoords.x + TILE_SIZE, top_left.texCoords.y);
			bottom_left.texCoords = sf::Vector2f(top_left.texCoords.x, top_left.texCoords.y + TILE_SIZE);
			bottom_right.texCoords = sf::Vector2f(top_right.texCoords.x, bottom_left.texCoords.y);

			vertex_array.append(top_left);
			vertex_array.append(top_right);
			vertex_array.append(bottom_right);
			vertex_array.append(bottom_left);
		}
	}
}

void TileMap::update(const float elapsedTime) {
	///
}

void TileMap::render(sf::RenderWindow& window) {
	window.draw(vertex_array, render_states);
}