#include <iostream>
#include <vector>
#include <random>
#include <SFML/Audio.hpp>
#include <fstream> // For loading WAV files

using namespace std;

// Define a note structure
struct Note {
  int pitch; // MIDI pitch value (e.g., 60 for C4)
  int duration; // Length of the note (in milliseconds)
  sf::SoundBuffer buffer; // Sound buffer for the note (loaded from a WAV file)
};

// Function to load a sound buffer from a WAV file
bool loadSoundBuffer(sf::SoundBuffer& buffer, const string& filename) {
  ifstream stream(filename, ios::binary);
  if (!stream.is_open()) {
    cerr << "Error: Could not open file " << filename << endl;
    return false;
  }

  stream.seekg(0, ios::end);
  size_t fileSize = stream.tellg();
  stream.seekg(0, ios::beg);

  char* data = new char[fileSize];
  stream.read(data, fileSize);
  stream.close();

  if (!buffer.loadFromMemory(data, fileSize)) {
    delete[] data;
    cerr << "Error: Could not load sound buffer from " << filename << endl;
    return false;
  }

  delete[] data;
  return true;
}

// Function to generate a random melody with a major scale
vector<Note> generateMelody(int rootNote, int scaleType, int numNotes, int minDuration, int maxDuration) {
  vector<Note> melody;

  // Validate scale type (currently only major scale supported)
  if (scaleType != 0) {
    cout << "Warning: Only major scale (scaleType=0) is currently supported." << endl;
  }

  // Major scale intervals relative to the root note
  vector<int> majorScale = {0, 2, 4, 5, 7, 9, 11};

  // Generate random notes within the major scale
  for (int i = 0; i < numNotes; i++) {
    int randomScaleIndex = rand() % majorScale.size();
    int pitch = rootNote + majorScale[randomScaleIndex];

    // Generate random duration within specified range
    int duration = minDuration + (rand() % (maxDuration - minDuration + 1));

    melody.push_back({pitch, duration});
  }

  return melody;
}

// Function to play a melody using SFML
void playMelody(const vector<Note>& melody) {
  // Create a sound
  sf::Sound sound;

  for (const Note& note : melody) {
    sound.setBuffer(note.buffer);
    sound.play();
    sf::sleep(sf::milliseconds(note.duration));
  }
}

int main() {
  // Set random seed for melody generation (placeholder)
  random_device rd;
  mt19937 gen(rd);

  // User input for melody parameters (optional)
  int rootNote = 60; // C4 (can be adjusted by the user)
  int scaleType = 0; // Major scale (can be chosen by the user)
  int numNotes = 16;
  int minDuration = 250;
  int maxDuration = 500;

  // Load instrument sound buffer (replace with your instrument filename)
  string instrumentFilename = "instruments/your_instrument.wav";
  sf::SoundBuffer buffer;
  if (!loadSoundBuffer(buffer, instrumentFilename)) {
    return 1;
  }

  // Generate a melody
  vector<Note> melody = generateMelody(rootNote, scaleType, numNotes, minDuration, maxDuration);

  // Assign the sound buffer to each note in the melody
  for (Note& note : melody) {
    note.buffer = buffer;
  }

  // Play the generated melody
  playMelody(melody);

  return 0;
}
