#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Notes.h"
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include "SoundMaker.h"
#include "SoundGenerator.h"
#include "Keybord.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	window.setVerticalSyncEnabled(true);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	 // SoundGenerator SG;
	 // SG.generateAllSound();

	Keybord* KInstance = Keybord::getInstance();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				KInstance->play(event.key.code);
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}