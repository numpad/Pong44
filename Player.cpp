#include "Player.hpp"


Player::Player(Player::ID id) {
	Player::id = id;
	Player::side = Vec2(0.0, 0.0);
	Player::color = Player::colorOf(id);
	
}

void Player::setSide(int left_or_right, int up_or_down) {
	Player::side = Vec2(left_or_right, up_or_down);
}

void Player::setColor(sf::Color color) {
	Player::color = color;
}

void Player::setKeys(sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key use) {
	Player::left = left;
	Player::right = right;
	Player::use = use;
	
}

sf::Color Player::colorOf(Player::ID id) {
	switch (id) {
		case PLAYER_1:
			return sf::Color(0xF9, 0x59, 0x59);
		case PLAYER_2:
			return sf::Color(0x59, 0xF9, 0x59);
		case PLAYER_3:
			return sf::Color(0x59, 0x59, 0xF9);
		case PLAYER_4:
			return sf::Color(0xF9, 0xF9, 0x59);
		default:
			return sf::Color(233, 233, 233);
	};
}

Vec2 Player::getSide() {
	return Player::side;
}

sf::Color Player::getColor() {
	return Player::color;
}

Player::ID Player::getID() {
	return Player::id;
}