#include "WorldGenerator.hpp"

int WorldGenerator::get_tile(const int x, const int y, const int width, const int height) {
	int tile_ID{};

	static pn2d::PerlinNoise perlin_noise(seed);

	float factor = 8.5f;

	float perlin_noise_value = (float) perlin_noise.noise((float) (x / (float) width) * factor, (float) (y / (float) height) * factor, 0.0);

	float distance_to_center = std::sqrt(std::pow(std::abs((width / 2.0f) - x), 2) + std::pow(std::abs((height / 2.0f) - y), 2));

	distance_to_center /= std::sqrt(std::pow(width / 2.0f, 2) + std::pow(height / 2.0f, 2));

	perlin_noise_value -= (distance_to_center / 2.25f);

	float increase = -0.02f;

	if (perlin_noise_value > 0.71f + increase) {
		tile_ID = 4;
	} else if (perlin_noise_value > 0.63f + increase) {
		tile_ID = 3;
	} else if (perlin_noise_value > 0.53f + increase) {
		tile_ID = 2;
	} else if (perlin_noise_value > 0.5f + increase) {
		tile_ID = 1;
	} else {
		tile_ID = 0;
	}

	return tile_ID;
}

std::vector<sf::Vector2i> WorldGenerator::create_trees(std::vector<std::vector<int>>& world) {
	std::mt19937 mt(seed);
	std::uniform_int_distribution<int> dist(0, 10); // 10%

	std::vector<sf::Vector2i> trees;

	for (unsigned int y = 0; y < world.size(); ++y) {
		for (unsigned int x = 0; x < world[y].size(); ++x) {
			if (world[y][x] == 2) {
				if (dist(mt) == 0) {
					trees.push_back(sf::Vector2i(x, y));
				}
			}
		}
	}

	return trees;
}

std::tuple<std::vector<std::vector<int>>, std::vector<sf::Vector2i>> WorldGenerator::generate(const int width, const int height) {
	static bool first = true;

	if (first) {
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<unsigned int> dist(0, std::numeric_limits<unsigned int>::max());

		seed = dist(mt);

		//seed = 46;

		first = false;
	}
	
	std::vector<std::vector<int>> world;

	for (int y = 0; y < height; ++y) {
		std::vector<int> row_of_tiles;

		for (int x = 0; x < width; ++x) {
			row_of_tiles.push_back(get_tile(x, y, width, height));
		}

		world.push_back(row_of_tiles);
	}

	std::vector<sf::Vector2i> trees = create_trees(world);

	return std::make_tuple(world, trees);
}