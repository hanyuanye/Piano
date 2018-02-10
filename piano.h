#pragma once
#include <SDL.h>
#include <Windows.h>
#include <iostream>

using namespace std;

class piano {
private:
	bool whiteKeys[7];
	bool blackKeys[5];
	bool shift;
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	piano();
	void drawPiano();
	void soundPiano();
	void updatePianoKeys();
	void handleKey(SDL_KeyboardEvent *key, bool play);
};
