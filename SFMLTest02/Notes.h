#ifndef DEF_Notes
#define DEF_Notes

#include <string>
#include <SFML/Audio.hpp>

#pragma once
class Notes
{
	public:
		Notes();
		Notes(std::string file);
		Notes(sf::SoundBuffer soundBuffer);
		~Notes();
		int load(std::string file);
		int load(sf::SoundBuffer soundBuffer);
		void play();
	
	private:
		sf::SoundBuffer buffer;
		sf::Sound sound;
		std::string note;
};

#endif