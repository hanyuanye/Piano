#include "piano.h"


const int xWhiteKey = 125;
const int yWhiteKey = 200;
const int widthWhiteKey = 60;
const int heightWhiteKey = 160;
const int xBlackKey = 170;
const int yBlackKey = 200;
const int widthBlackKey = 30;
const int heightBlackKey = 80;
int frequenciesWhiteKey[] = { 262, 294, 330, 350, 392, 440, 494, 523, 587, 659, 698, 783, 880, 988 };
int frequenciesBlackKey[] = { 277, 311, 370, 415, 466, 554, 622, 740, 831, 932 };

piano::piano() {
	window = SDL_CreateWindow
	(
		".", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_SHOWN
	);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 0, 153, 76, 0);

	SDL_RenderClear(renderer);

	for (int i = 0; i < 7; ++i) {
		whiteKeys[i] = false;
	}
	for (int i = 0; i < 5; ++i) {
		blackKeys[i] = false;
	}
}
void piano::drawPiano() {


	for (int i = 0; i < 7; ++i) {
		SDL_Rect r;
		r.x = widthWhiteKey * i + xWhiteKey;
		r.y = yWhiteKey;
		r.w = widthWhiteKey;
		r.h = heightWhiteKey;

		if (whiteKeys[i]) {
			SDL_SetRenderDrawColor(renderer, 150, 150, 150, 0);
		}
		else {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		}
		SDL_RenderFillRect(renderer, &r);
	}

	for (int i = 0; i < 5; ++i) {
		SDL_Rect r;
		r.x = widthWhiteKey * i + xBlackKey;
		if (i > 0) {
			r.x += widthWhiteKey;
		}
		r.y = yBlackKey;
		r.w = widthBlackKey;
		r.h = heightBlackKey;

		
		if (blackKeys[i]) {
			SDL_SetRenderDrawColor(renderer, 0, 128, 255, 0);
		}

		else {
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		}
		SDL_RenderFillRect(renderer, &r);
	}
	SDL_RenderPresent(renderer);
//	updatePianoKeys();
}

void piano::soundPiano() {
	for (int i = 0; i < 7; i++) {
		if (whiteKeys[i]) {
			if (shift) {
				Beep(frequenciesWhiteKey[i + 7], 250);
			}
			else {
				Beep(frequenciesWhiteKey[i], 250);
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		if (blackKeys[i]) {
			if (shift) {
				Beep(frequenciesBlackKey[i + 5], 250);
			}
			else {
				Beep(frequenciesBlackKey[i], 250);
			}
		}
	}
}

void piano::updatePianoKeys() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			
		case SDL_KEYDOWN:
			handleKey(&event.key, true);
			break;
		case SDL_KEYUP:
			handleKey(&event.key, false);
			break;
		default:
			break;
		}
	}
}

void piano::handleKey(SDL_KeyboardEvent *key, bool state) {
	cout << key->keysym.scancode << endl;
	switch (key->keysym.scancode) {
		//whitekeys
	case 4:
		whiteKeys[0] = state;
		break;
	case 22:
		whiteKeys[1] = state;
		break;
	case 7:
		whiteKeys[2] = state;
		break;
	case 9:
		whiteKeys[3] = state;
		break;
	case 10:
		whiteKeys[4] = state;
		break;
	case 11:
		whiteKeys[5] = state;
		break;
	case 13:
		whiteKeys[6] = state;
		break;
		//blackkeys
	case 26:
		blackKeys[0] = state;
		break;
	case 8:
		blackKeys[1] = state;
		break;
	case 21:	
		blackKeys[2] = state;
		break;
	case 23:
		blackKeys[3] = state;
		break;
	case 28:
		blackKeys[4] = state;
		break;
	case 225:
		shift = state;
		break;
	default:
		break;
	}
}