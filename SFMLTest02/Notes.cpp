#include "Notes.h"
#include <iostream>
#include <string>
#include <SFML/Audio.hpp>

using namespace std;

Notes::Notes()
{
}

Notes::Notes(string file)
{
	if (!buffer.loadFromFile(file)) {
		throw new exception("Erreur du chargement de la ressource");
	}
	sound.setBuffer(buffer);
}

Notes::Notes(sf::SoundBuffer soundBuffer)
{
	buffer = soundBuffer;
	sound.setBuffer(soundBuffer);
}

Notes::~Notes()
{

}

// Fonction qui charge un sond depuis un fichier
int Notes::load(string file) {
	if (!buffer.loadFromFile("Ressources/Sond/petitSond.wav")) {
		return -1;
	}
	sound.setBuffer(buffer);
	return 0;
}

// Fonction qui charge un sond depuis un buffer
int Notes::load(sf::SoundBuffer soundBuffer) {
	buffer = soundBuffer;
	sound.setBuffer(soundBuffer);
	return 0;
}

void Notes::play() {
	sound.play();
}

