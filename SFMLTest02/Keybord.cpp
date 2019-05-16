#include "Keybord.h"
#include <map>
#include "Notes.h"
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <vector>
#include <string>
//#include <SFML/Window/Keyboard.hpp>

Keybord *Keybord::singleton = nullptr;

Keybord::Keybord()
{
	loadAll();
}

Keybord* Keybord::getInstance()
{
	// instanciation unique garantie (du moins si
	// le programme n'a qu'un seul thread)
	if (!singleton)
		singleton = new Keybord;
	return singleton;
}

void Keybord::loadAll()
{
	std::vector< std::string > notesChar = {"c", "d", "e", "f", "g", "a", "b"};

	std::vector< int > tabDo = { sf::Keyboard::Num1, sf::Keyboard::Num2, sf::Keyboard::Num3, sf::Keyboard::Num4, sf::Keyboard::Num5, sf::Keyboard::Num6 };// { 27, 28, 29, 30, 31, 32 };
	std::vector< int > tabRe = { sf::Keyboard::A, sf::Keyboard::Z, sf::Keyboard::E, sf::Keyboard::R, sf::Keyboard::T, sf::Keyboard::Y }; // { 0, 25, 4, 17, 19, 24 };
	std::vector< int > tabMi = { sf::Keyboard::Q, sf::Keyboard::S, sf::Keyboard::D, sf::Keyboard::F, sf::Keyboard::G, sf::Keyboard::H };
	std::vector< int > tabFa = { sf::Keyboard::Num7, sf::Keyboard::Num8, sf::Keyboard::Num9, sf::Keyboard::Num0, 46, 55 }; // { 33, 34, 35, 26, 46, 55 };
	std::vector< int > tabSol = { sf::Keyboard::U, sf::Keyboard::I, sf::Keyboard::O, sf::Keyboard::P, 47, 48 };// { 20, 8, 14, 15, 47, 48 };
	std::vector< int > tabLa = { sf::Keyboard::J, sf::Keyboard::K, sf::Keyboard::L, sf::Keyboard::M, 54, 53 };
	std::vector< int > tabSi = { sf::Keyboard::W, sf::Keyboard::X, sf::Keyboard::C, sf::Keyboard::V, sf::Keyboard::B, sf::Keyboard::N };

	std::vector< std::vector<int> > tabAllKey = { tabDo, tabRe, tabMi, tabFa, tabSol, tabLa, tabSi };

	for (int singleNotesChar = 0; singleNotesChar < notesChar.size(); singleNotesChar++) {
		std::string soundName = "Ressources/Sond/" + notesChar[singleNotesChar];

		for (int singleNoteKey = 0; singleNoteKey < tabAllKey[singleNotesChar].size() ; singleNoteKey++) {
			std::string soundNameFile = soundName + std::to_string(singleNoteKey) + ".wav";
			mapKN[tabAllKey[singleNotesChar][singleNoteKey]] = std::unique_ptr<Notes>(new Notes(soundNameFile));
		}
	}
}

Keybord::~Keybord()
{
}


void Keybord::reload()
{
}

void Keybord::play(int key)
{
	if (mapKN.find(key) != mapKN.end()) {
		mapKN[key]->play();
	}
}
