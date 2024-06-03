# CMixer: Procedural Music Generation in C++

This project explores procedural music generation using C++ and the SFML library.

## What is CMixer?

CMixer allows you to create and play melodies based on user-defined parameters and musical concepts.

## Features

- Generate melodies based on scales (major, minor) and chords (future enhancement)
- Integrate user input for melody parameters (root note, scale type, number of notes)
- Play generated melodies using sound samples (WAV files)
- (Optional) Implement rhythm generation with different time signatures and note values (future enhancement)
- (Optional) Allow selection of instrument types and create harmony (future enhancement)
- (Optional) Provide user interface for control and interaction (future enhancement)

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++)
- SFML library ([Download SFML](https://www.sfml-dev.org/download.php))
- WAV files for instrument sounds (place them in an "instruments" folder within the project directory)

### Compile and Run

1. Compile the code using your C++ compiler with SFML libraries linked:
    ```bash
    g++ -o CMixer CMixer.cpp -lsfml-audio -lsfml-graphics
    ```
2. Run the executable (CMixer).

## Current Functionality

- The program generates a melody based on default parameters (C4 major scale, 16 notes, random durations).
- You can modify the code to experiment with different scales, number of notes, and potentially integrate rhythm generation (commented sections).

## Future Enhancements

- Implement rhythm generation for more complex musical structures.
- Generate multiple melodies for harmony and assign them to different instruments using separate sound libraries.
- Create a user interface for parameter control, instrument selection, and saving/loading presets.
- Explore advanced techniques like Markov chains, chord progressions, and evolutionary algorithms for more sophisticated music generation.
