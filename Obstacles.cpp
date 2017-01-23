#include "Obstacles.hpp"

Obstacles::Obstacles() {
	Obstacles::corners = std::vector<sf::VertexArray>();
	
	sf::VertexArray corner1(sf::TrianglesStrip, 6);
	corner1[0].position = sf::Vector2f( 0.0,  0.0);
	corner1[1].position = sf::Vector2f( 0.0, 35.0);
	corner1[2].position = sf::Vector2f(35.0,  0.0);
	corner1[3].position = sf::Vector2f(13.0, 47.0);
	corner1[4].position = sf::Vector2f(47.0, 13.0);
	corner1[5].position = sf::Vector2f(47.0, 47.0);
	corner1[0].color = sf::Color(233, 233, 233);
	corner1[1].color = sf::Color(233, 233, 233);
	corner1[2].color = sf::Color(233, 233, 233);
	corner1[3].color = sf::Color(233, 233, 233);
	corner1[4].color = sf::Color(233, 233, 233);
	corner1[5].color = sf::Color(233, 233, 233);
	
	sf::VertexArray corner2(sf::TrianglesStrip, 6);
	corner2[0].position = sf::Vector2f(800.0 -  0.0,  0.0);
	corner2[1].position = sf::Vector2f(800.0 -  0.0, 35.0);
	corner2[2].position = sf::Vector2f(800.0 - 35.0,  0.0);
	corner2[3].position = sf::Vector2f(800.0 - 13.0, 47.0);
	corner2[4].position = sf::Vector2f(800.0 - 47.0, 13.0);
	corner2[5].position = sf::Vector2f(800.0 - 47.0, 47.0);
	corner2[0].color = sf::Color(233, 233, 233);
	corner2[1].color = sf::Color(233, 233, 233);
	corner2[2].color = sf::Color(233, 233, 233);
	corner2[3].color = sf::Color(233, 233, 233);
	corner2[4].color = sf::Color(233, 233, 233);
	corner2[5].color = sf::Color(233, 233, 233);

	sf::VertexArray corner3(sf::TrianglesStrip, 6);
	corner3[0].position = sf::Vector2f( 0.0, 800.0 -  0.0);
	corner3[1].position = sf::Vector2f( 0.0, 800.0 - 35.0);
	corner3[2].position = sf::Vector2f(35.0, 800.0 -  0.0);
	corner3[3].position = sf::Vector2f(13.0, 800.0 - 47.0);
	corner3[4].position = sf::Vector2f(47.0, 800.0 - 13.0);
	corner3[5].position = sf::Vector2f(47.0, 800.0 - 47.0);
	corner3[0].color = sf::Color(233, 233, 233);
	corner3[1].color = sf::Color(233, 233, 233);
	corner3[2].color = sf::Color(233, 233, 233);
	corner3[3].color = sf::Color(233, 233, 233);
	corner3[4].color = sf::Color(233, 233, 233);
	corner3[5].color = sf::Color(233, 233, 233);

	sf::VertexArray corner4(sf::TrianglesStrip, 6);
	corner4[0].position = sf::Vector2f(800.0 -  0.0, 800.0 -  0.0);
	corner4[1].position = sf::Vector2f(800.0 -  0.0, 800.0 - 35.0);
	corner4[2].position = sf::Vector2f(800.0 - 35.0, 800.0 -  0.0);
	corner4[3].position = sf::Vector2f(800.0 - 13.0, 800.0 - 47.0);
	corner4[4].position = sf::Vector2f(800.0 - 47.0, 800.0 - 13.0);
	corner4[5].position = sf::Vector2f(800.0 - 47.0, 800.0 - 47.0);
	corner4[0].color = sf::Color(233, 233, 233);
	corner4[1].color = sf::Color(233, 233, 233);
	corner4[2].color = sf::Color(233, 233, 233);
	corner4[3].color = sf::Color(233, 233, 233);
	corner4[4].color = sf::Color(233, 233, 233);
	corner4[5].color = sf::Color(233, 233, 233);


	Obstacles::corners.push_back(corner1);
	Obstacles::corners.push_back(corner2);
	Obstacles::corners.push_back(corner3);
	Obstacles::corners.push_back(corner4);
}

void Obstacles::draw(sf::RenderWindow &window) {
	for (size_t i = 0; i < Obstacles::corners.size(); ++i) {
		window.draw(Obstacles::corners[i]);
	}
}