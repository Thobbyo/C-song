#ifndef SOUND_GENERATOR
#define SOUND_GENERATOR

#include <iostream>
#include <map>
#include <vector>
#include "SoundMaker.h"

#pragma once
class SoundGenerator
{
public:
	SoundGenerator(double max_amplitude = 32760, double hz = 44100.0);
	~SoundGenerator();
	void generateAllSound(int startOctave = 0);
private:
	void generate_data(SoundMaker& S, double freq, double amount_time = 1.0);
	
	double max_amplitude;
	double hz;

	static double two_pi;
	static int nombreOctave;
	// music_map[ note_letter ][ octave 0 - 8 ] == frequency
	static std::map< char, std::vector<double>> music_map;
};

#endif