#include "piano.h"
#include <SDL.h>

int main(int argc, char *argv[]) {
	piano piano;
	piano.drawPiano();

	while (true) {
		piano.drawPiano();
		piano.soundPiano();
		piano.updatePianoKeys();
	}
	return 0;
}