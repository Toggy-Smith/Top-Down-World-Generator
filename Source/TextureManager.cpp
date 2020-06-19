#include "TextureManager.hpp"

TextureManager::~TextureManager() {
	for (unsigned int i = 0; i < textures.size(); ++i) {
		delete std::get<1>(textures[i]);
	}
}

void TextureManager::load_texture(const std::string& name, const std::string& location) {
	sf::Texture* texture = new sf::Texture;

	texture->loadFromFile(location);

	textures.push_back(std::make_tuple(name, texture));
}

sf::Texture* TextureManager::get_texture(const std::string& name) const {
	for (unsigned int i = 0; i < textures.size(); ++i) {
		if (std::get<0>(textures[i]) == name) {
			return std::get<1>(textures[i]);
		}
	}

	std::cerr << "Error: Texture manager unable to find texture with name '" << name << "'." << "\n";
}