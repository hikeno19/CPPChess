#include "Piece.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Knight.h"
#include <string>
#include <vector>

using namespace std;

class GameLogic
{
	public:
		GameLogic();
		void NewBoard();
		void Initiate();
		bool CheckGameStatus();
		bool checkCheck();
		vector<int> GetKingPosition(bool color);
		vector<string> GetKingMoves(bool color);
		vector<string> GetMovesFromPosition();

		Piece*** board;
		bool GameIsOn;
		bool currentSide;
		int moveCount;

	private:
};

