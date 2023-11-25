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
		bool CheckCheckmate() const;
		bool checkCheck() const;
	    string GetKingPosition(bool color) const;
		vector<string> GetKingPossibleMoves(bool color) const;
		vector<string> GetPiecePossibleMoves(string position) const;
		vector<string> GetEnemyPossibleMoves() const;

		//variables
		Piece*** board;
		bool GameIsOn;
		bool currentSide;
		string position; 
		int moveCount;
		string blackKingPosition;
		string whiteKingPosition;
	private:
};

