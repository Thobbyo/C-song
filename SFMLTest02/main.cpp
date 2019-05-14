#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Notes.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	window.setVerticalSyncEnabled(true);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	Notes maNote("Ressources/Sond/petitSond.wav");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed) {
				maNote.play();
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}