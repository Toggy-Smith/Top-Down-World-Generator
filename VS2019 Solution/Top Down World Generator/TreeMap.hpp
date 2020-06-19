#pragma once

#include "SFML/Graphics.hpp"

#include "TextureManager.hpp"

#include <vector>

class TreeMap {
	private:
		std::vector<sf::Sprite> trees;

	public:
		void load(std::vector<sf::Vector2i>&, TextureManager&);
		void render(sf::RenderWindow&);
};