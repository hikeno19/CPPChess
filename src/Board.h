#include "Piece.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Knight.h"
#include <string>
#include <vector>

class Board
{
	public:
		// constructor
		Board();
		// virtual destructor
		virtual ~Board();

		void NewBoard();
		string GetKingPosition(bool color);
		vector<string> GetKingPossibleMoves(bool color);
		vector<string> GetPiecePossibleMoves(string position);
		bool CheckCheckmate(bool currentSide);
		bool CheckCheck(bool currentSide);
		bool MakeMove(vector<int> move);
		vector<string> GetEnemyPossibleMoves(bool currentSide);

		Piece* GetPieceAt(int rank, int file);

		bool isOccupied(int rank, int file);

		bool GetColorOfPosition(int rank, int file);

		bool inRange(int n);

		bool inRangeCoordinates(int x, int y);

		Board* GetBoard();

		bool TestPawnMove(int srank, int sfile, int erank, int efile, bool currentSide);

		bool TestMove(int srank, int sfile, int erank, int efile, bool currentSide);

		void PrintBoard();

	private:
		unique_ptr<Piece> board[8][8];
		string blackKingPosition;
		string whiteKingPosition;
};

