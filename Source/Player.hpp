#pragma once

#include "TextureManager.hpp"

class Player {
	private:
		const float SPEED = 250.0f;

		sf::Sprite sprite;

	public:
		Player(TextureManager&);

		void set_position(const int, const int);
		sf::Vector2f get_position() const;
		void update(const float, bool is_window_focused);
		void render(sf::RenderWindow&);
};