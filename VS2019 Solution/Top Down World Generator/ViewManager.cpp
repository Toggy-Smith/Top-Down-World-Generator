#include "ViewManager.hpp"

void ViewManager::handle_event(const sf::Event& event) {
	if (event.type == sf::Event::MouseWheelMoved) {
		float zoom_delta = -(event.mouseWheel.delta * zoom_per_mouse_wheel_tick);

		zoom += zoom_delta;

		if (zoom < minimum_zoom) zoom = minimum_zoom;
	}
}

void ViewManager::adjust(sf::RenderWindow& window, sf::Vector2f view_center) {
	sf::View view = window.getView();

	sf::Vector2f new_view_size = (sf::Vector2f) window.getSize() * zoom;

	view.setSize(sf::Vector2f(std::floor(new_view_size.x + 0.5f), std::floor(new_view_size.y + 0.5f)));
	view.setCenter(sf::Vector2f(std::floor(view_center.x + 0.5f), std::floor(view_center.y + 0.5f)));

	window.setView(view);
}