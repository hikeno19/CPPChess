#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include <string>
#include <vector>

using namespace std;

class Pawn : public Piece
{
	public:
		//Constructors
		Pawn();
		Pawn(bool color, int rank, int file);
		//Destructor
		~Pawn();

		//Overload for Piece method. Returns possible moves from board. 
		vector<string> GetPossibleMoves(Piece *** board);
	private:
};

#endif