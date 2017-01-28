#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#include "Vec2.hpp"
#include "ParticleFuel.hpp"
#include "Background.hpp"
#include "Player.hpp"
#include "Paddle.hpp"
#include "Obstacles.hpp"
#include "Ball.hpp"
#include "Random.hpp"
#include "Item.hpp"

#include <vector>

int main(int argc, char *argv[]) {
	sf::RenderWindow window(sf::VideoMode(800, 800), "Pong for four", sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(60);

	/* Background color */
	Background background;
	Obstacles obstacles;

	std::vector<Ball> balls = std::vector<Ball>();

	/* Players and Paddles */
	Player player1(Player::PLAYER_1, Player::SIDE_LEFT);
	Player player2(Player::PLAYER_2, Player::SIDE_TOP);
	Player player3(Player::PLAYER_3, Player::SIDE_RIGHT);
	Player player4(Player::PLAYER_4, Player::SIDE_BOTTOM);
	player1.setKeys(sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::A);
	player2.setKeys(sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Up);
	player3.setKeys(sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::L);
	player4.setKeys(sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::G);

	std::vector<Paddle> paddles = std::vector<Paddle>();
	paddles.push_back(Paddle(player1));
	paddles.push_back(Paddle(player2));
	paddles.push_back(Paddle(player3));
	paddles.push_back(Paddle(player4));
	
	sf::View screenView(sf::Vector2f(400.0, 400.0), sf::Vector2f(800.0, 800.0));
	window.setView(screenView);

	Item item(Vec2(270.0, 590.0));

	sf::Clock ballSpawner;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			};
		}
		Vec2 mouse = Vec2(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		/* Update */
		if (ballSpawner.getElapsedTime().asSeconds() > 3.0) {
			ballSpawner.restart();
			balls.push_back(Ball(Vec2(400.0, 400.0), false, 1.0));
		}
		if (balls.empty()) {
			balls.push_back(Ball(Vec2(400.0, 400.0)));
		}

		for (size_t i = 0; i < balls.size(); ++i) {
			if (balls.at(i).removable()) {
				balls.erase(balls.begin() + i);
			}
		}
		item.intersect(balls);

		/* Rendering */
		window.setView(screenView);

		background.draw(window);

		for (size_t i = 0; i < paddles.size(); ++i) {
			paddles.at(i).update();
			paddles.at(i).draw(window);
		}

		item.draw(window);

		for (size_t i = 0; i < balls.size(); ++i) {
			balls.at(i).update();
			balls.at(i).collide(paddles);
			balls.at(i).checkScored(background, 800.0, 800.0);
			balls.at(i).draw(window);
		}

		obstacles.draw(window);
		window.display();
	}

	return 0;
}