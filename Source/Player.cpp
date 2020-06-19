#include "Player.hpp"

Player::Player(TextureManager& texture_manager) {
	texture_manager.load_texture("player", "assets/player.png");

	sprite.setTexture(*texture_manager.get_texture("player"));
	sprite.setScale(sf::Vector2f(2.0f, 2.0f));
}

void Player::set_position(const int x, const int y) {
	const int TILE_SIZE = 64;

	sprite.setPosition(sf::Vector2f(x * (float) TILE_SIZE, y * (float) TILE_SIZE));
}

sf::Vector2f Player::get_position() const {
	sf::Vector2f size = sf::Vector2f(sprite.getTexture()->getSize().x * sprite.getScale().x,
	                                 sprite.getTexture()->getSize().y * sprite.getScale().y);

	return sprite.getPosition() + size / 2.0f;
}

void Player::update(const float elapsedTime, bool is_window_focused) {
	if (is_window_focused) {
		sf::Vector2f direction;

		bool isMovingUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W);
		bool isMovingDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S);
		bool isMovingLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		bool isMovingRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D);

		if (isMovingUp)
			direction.y -= 1.0f;
		if (isMovingDown)
			direction.y += 1.0f;
		if (isMovingLeft)
			direction.x -= 1.0f;
		if (isMovingRight)
			direction.x += 1.0f;

		sf::Vector2f movementAmount = direction * SPEED * elapsedTime;

		sprite.move(movementAmount);
	}
}

void Player::render(sf::RenderWindow& window) {
	window.draw(sprite);
}