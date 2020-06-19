#pragma once

#include "SFML/Graphics.hpp"

#include <cmath>

class ViewManager {
	private:
		float zoom = 1.0f;
		
		const float zoom_per_mouse_wheel_tick = 0.4f;

		const float minimum_zoom = 0.6f;

	public:
		void handle_event(const sf::Event&);
		void adjust(sf::RenderWindow&, sf::Vector2f);
};