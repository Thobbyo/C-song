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
	double baseGenerate(int x, int n, double frequency, double hz);
	
	double max_amplitude;
	double hz;

	static double two_pi;
	static int nombreOctave;
	static std::map< char, std::vector<double>> music_map;
};

#endif