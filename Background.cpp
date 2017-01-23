#include "Background.hpp"

Background::Background() : Background(sf::Color(33, 33, 33)) {
}

Background::Background(sf::Color bgColor) {
	Background::flashTime = 0.0;
	Background::flashTimeMax = 30.0;

	Background::background = bgColor;
}

void Background::flash(sf::Color flashColor) {
	Background::flashColor = flashColor;
	Background::flashTime = Background::flashTimeMax;
}

void Background::draw(sf::RenderWindow &window) {
	const float flash_percent = Background::flashTime / (float)(Background::flashTimeMax);
	window.clear(sf::Color(
		Background::background.r * (1.0 - flash_percent) + Background::flashColor.r * (flash_percent),
		Background::background.g * (1.0 - flash_percent) + Background::flashColor.g * (flash_percent),
		Background::background.b * (1.0 - flash_percent) + Background::flashColor.b * (flash_percent)
	));

	if (Background::flashTime > 0) {
		Background::flashTime -= 1.0;
	}
}