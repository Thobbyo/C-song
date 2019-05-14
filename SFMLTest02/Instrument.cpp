#include "Instrument.h"
#include "Notes.h"
#include <map>

Instrument::Instrument(std::string name)
{
	nameInstrument = name;
}

Instrument::Instrument(std::string name, std::map<int, Notes> tabNotes)
{
	nameInstrument = name;
	listNotes = tabNotes;
}

Instrument::~Instrument()
{
}

void Instrument::addNotes(int emp, Notes noteSup)
{
	listNotes.insert(std::pair<int, Notes>(emp, noteSup));
}

void Instrument::addNotes(int emp, std::string noteFile)
{
	Notes noteSup(noteFile);
	listNotes.insert(std::pair<int, Notes>(emp, noteSup));
}

void Instrument::addNotes(int emp, sf::SoundBuffer noteBuff)
{
	Notes noteSup(noteBuff);
	listNotes.insert(std::pair<int, Notes>(emp, noteSup));
}

void Instrument::play(int emp)
{
	listNotes[emp].play();
}
