#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
#include <string>
#include <vector>

using namespace std;

class Queen : public Piece
{
public:
	//Constructors
	Queen();
	Queen(bool color, int rank, int file);
	//Destructor
	~Queen();
	//Overload for Piece method. Returns possible moves from board. 
	vector<string> GetPossibleMoves(Piece*** board);
private:
};

#endif