#ifndef DEF_Instrument
#define DEF_Instrument

#include <iostream>
#include <SFML/Audio.hpp>
#include <string>
#include <map> 
#include "Notes.h"

#pragma once
class Instrument
{
	public:
		Instrument(std::string name);
		Instrument(std::string name, std::map<int, Notes> tabNotes);
		~Instrument();
		void addNotes(int emp, Notes noteSup);
		void addNotes(int emp, std::string noteFile);
		void addNotes(int emp, sf::SoundBuffer noteBuff);
		void play(int emp);

	private:
		std::map<int, Notes> listNotes;
		std::string nameInstrument;
};

#endif