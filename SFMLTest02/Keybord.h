#ifndef KEYBORD
#define KEYBORD

#include <iostream>
#include <map>
#include "Notes.h"

#pragma once
class Keybord
{
public:
	Keybord& operator=(const Keybord&) = delete;
	Keybord(const Keybord&) = delete;
	~Keybord();
	static Keybord* getInstance();
	void reload();
	void play(int key);

private:
	Keybord();
	
	void loadAll();

	std::map<int, std::unique_ptr<Notes>> mapKN = std::map<int, std::unique_ptr<Notes>>();
	
	static Keybord *singleton;

};

#endif