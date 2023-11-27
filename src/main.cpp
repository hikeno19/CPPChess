#include <stdio.h>
#include "GameLogic.h"

using namespace std;

int main() {
	GameLogic* game = new GameLogic();
	game->PrintBoard();
	return 0;
}