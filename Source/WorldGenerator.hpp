#pragma once

#include "SFML/Graphics.hpp"

#include "pn2d.hpp"

#include <cmath>
#include <vector>
#include <random>
#include <tuple>

class WorldGenerator {
	private:
		unsigned int seed;

	public:
		int get_tile(const int, const int, const int, const int);
		std::vector<sf::Vector2i> create_trees(std::vector<std::vector<int>>&);
		std::tuple<std::vector<std::vector<int>>, std::vector<sf::Vector2i>> generate(const int, const int);
};