#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
#include <string>
#include <vector>


using namespace std;

class Bishop : public Piece
{
	public:
		//Constructors
		Bishop();
		Bishop(bool color, int rank, int file);
		//Destructor
		~Bishop();
		//Overload for Piece method. Returns possible moves from board. 
		vector<string> GetPossibleMoves(Piece*** board);
	private:
};

#endif