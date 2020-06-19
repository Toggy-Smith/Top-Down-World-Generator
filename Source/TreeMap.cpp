#include "TreeMap.hpp"

void TreeMap::load(std::vector<sf::Vector2i>& tree_locations, TextureManager& texture_manager) {
	texture_manager.load_texture("tree", "assets/tree.png");

	for (unsigned int i = 0; i < tree_locations.size(); ++i) {
		sf::Sprite sprite;

		sprite.setTexture(*texture_manager.get_texture("tree"));
		
		const int TILE_SIZE = 64;

		sprite.setPosition(sf::Vector2f((float) tree_locations[i].x * TILE_SIZE, (float) tree_locations[i].y * TILE_SIZE));
		sprite.setScale(sf::Vector2f(2.0f, 2.0f));

		trees.push_back(sprite);
	}
}

void TreeMap::render(sf::RenderWindow& window) {
	for (unsigned int i = 0; i < trees.size(); ++i) {
		window.draw(trees[i]);
	}
}