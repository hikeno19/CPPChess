#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include <string>
#include <vector>


using namespace std;

class Knight : public Piece
{
	public:
		//Constructors
		Knight();
		Knight(bool color, int rank, int file);
		//Destructor
		~Knight();
		//Overload for Piece method. Returns possible moves from board. 
		vector<string> GetPossibleMoves(Piece*** board);
	private:
};

#endif