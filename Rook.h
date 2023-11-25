#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"
#include <string>
#include <vector>

using namespace std;

class Rook : public Piece
{
public:
	//Constructors
	Rook();
	Rook(bool color, int rank, int file);
	//Destructor
	~Rook();
	//Overload for Piece method. Returns possible moves from board. 
	vector<string> GetPossibleMoves(Piece*** board);
private:
};
#endif
