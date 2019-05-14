#ifndef DEF_Instrument
#define DEF_Instrument

#include <iostream>
#include <string>
#include <map> 
#include "Notes.h"

#pragma once
class Instrument
{
	public:
		Instrument(std::string name);
		Instrument(std::string name, std::map<int, Notes[42]>);
		~Instrument();

	private:
		std::map<int, Notes [42]> listNotes;
		std::string nameInstrument;
};

#endif