#include "SoundGenerator.h"
#include "SoundMaker.h"
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <string>

double SoundGenerator::two_pi = M_PI * 2; // 6.283185307179586476925286766559
int SoundGenerator::nombreOctave = 6;
// https://pages.mtu.edu/~suits/notefreqs.html
// Upper-case letters denote sharp notes
std::map< char, std::vector<double>> SoundGenerator::music_map =	{
														std::make_pair<char, std::vector<double>>('c', { 16.35, 32.70, 65.41, 130.81, 261.63, 523.25, 1046.50, 2093.00, 4186.01 }),
														std::make_pair<char, std::vector<double>>('C', { 17.32, 34.65, 69.30, 138.59, 277.18, 554.37, 1108.73, 2217.46, 2217.46 }),
														std::make_pair<char, std::vector<double>>('d', { 18.35, 36.71, 73.42, 146.83, 293.66, 587.33, 1174.66, 2349.32, 4698.63 }),
														std::make_pair<char, std::vector<double>>('D', { 19.45, 38.89, 77.78, 155.56, 311.13, 622.25, 1244.51, 2489.02,  4978.03 }),
														std::make_pair<char, std::vector<double>>('e', { 20.60, 41.20, 82.41, 164.81, 329.63, 659.25, 1318.51, 2637.02, 5274.04 }),
														std::make_pair<char, std::vector<double>>('f', { 21.83, 43.65, 87.31, 174.61, 349.23, 698.46, 1396.91, 2793.83, 5587.65 }),
														std::make_pair<char, std::vector<double>>('F', { 23.12, 46.25, 92.50, 185.00, 369.99, 739.99, 1479.98, 2959.96, 5919.91 }),
														std::make_pair<char, std::vector<double>>('g', { 24.50, 49.00, 98.00, 196.00, 392.00, 783.99, 1567.98, 3135.96, 6271.93 }),
														std::make_pair<char, std::vector<double>>('G', { 25.96, 51.91, 103.83, 207.65, 415.30, 830.61, 1661.22, 3322.44, 6644.88 }),
														std::make_pair<char, std::vector<double>>('a', { 27.50, 55.00, 110.00, 220.00, 440.00, 880.00, 1760.00, 3520.00, 7040.00 }),
														std::make_pair<char, std::vector<double>>('A', { 29.14, 58.27, 116.54, 233.08, 466.16, 932.33, 1864.66, 3729.31, 7458.62 }),
														std::make_pair<char, std::vector<double>>('b', { 30.87, 61.74, 123.47, 246.94, 493.88, 987.77, 1975.53, 3951.07, 7902.13 }),
													};

SoundGenerator::SoundGenerator(double max_amplitude, double hz)
{
	this->max_amplitude = max_amplitude;
	this->hz = hz;
}

SoundGenerator::~SoundGenerator()
{
}

void SoundGenerator::generateAllSound(int startOctave)
{
	int musicMapSize = music_map['c'].size();
	if (startOctave + nombreOctave > musicMapSize) {
		startOctave = musicMapSize - nombreOctave;
	}

	// 12 notes in scale
	std::vector<char> notes = { 'c', 'C', 'd', 'D', 'e', 'f', 'F', 'g', 'G', 'a', 'A', 'b' };

	// On crée 6 ensemble de notes
	for (int i = 0; i < nombreOctave ; i++) {
		
		for (int oneNote = 0 ; oneNote < notes.size() ; oneNote++) {
			// Create file and initialize .wav file headers
			std::string fileName = "Ressources/Sond/";
			// On regarde si le charactères est en majuscule
			if (isupper(notes[oneNote])) {
				fileName = fileName + notes[oneNote] + "&" + std::to_string(i) + ".wav";
			}
			else {
				fileName = fileName + notes[oneNote] + std::to_string(i) + ".wav";
			}
			std::cout << "1 : " + fileName << std::endl;
			SoundMaker S(fileName);
			generate_data(S, music_map[notes[oneNote]][startOctave+i]);
			S.done(); // Final header adjustments and close file
		}
	}
}

// Function that will convert frequency and time duration into .wav file samples
void SoundGenerator::generate_data(SoundMaker& S, double freq, double amount_time) {

	double frequency = freq;
	double seconds = amount_time;

	double chan_1 = 0.0; // channel 1
	double chan_2 = 0.0; // channel 2

	double amplitude = (double) 32760.0;
	int period;
	frequency == 0.0 ? period = -1 : period = (int)(hz / (2.0 * frequency)); // number of samples in a wave length

	double step = max_amplitude / period;

	int samples = hz * seconds;
	int x;
	double value;

	for (int n = 0; n < samples; n++) {

		chan_2 += step;
		// x = n % (2 * period);
		x = n / samples;
		value = sin(((two_pi * n * frequency) / hz));

		// Channel 1 has sine wave
		chan_1 = amplitude * value;

		// Channel 2 will have a half circle wave
		chan_2 = sqrt(pow(2 * 32760.0, 2) * (1.0 - (pow(x - (period), 2) / pow(period, 2)))) - 32760.0;

		if (frequency == 0.0)
			chan_2 = 0.0;

		S.add_sample((int)(chan_1), (int)(chan_2)); // Add sample to .wav file
	}
}
