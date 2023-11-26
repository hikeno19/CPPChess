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
		~GameLogic();
		void NewBoard();
		void Initiate();
		bool CheckCheckmate() const;
		bool CheckCheck() const;
		void MakeMove();
	    string GetKingPosition(bool color) const;
		string** GetKingPossibleMoves(bool color);
		string** GetPiecePossibleMoves(string position);
		string** GetEnemyPossibleMoves();

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

