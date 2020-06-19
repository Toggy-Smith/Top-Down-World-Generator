#pragma once

#include "SFML/Graphics.hpp"

#include <string>
#include <vector>
#include <tuple>
#include <iostream>

class TextureManager {
	private:
		std::vector<std::tuple<std::string, sf::Texture*>> textures;

	public:
		~TextureManager();

		void load_texture(const std::string& name, const std::string& location);
		sf::Texture* get_texture(const std::string& name) const;
};