#ifndef KING_H
#define KING_H
#include "Piece.h"
#include <string>
#include <vector>

using namespace std;

class King : public Piece
{
public:
	//Default Constructor
	King();
	//Constructor
	King(bool color, int rank, int file);
	//Destructor
	~King();
	//Overload for Piece method. Returns possible moves from board. 
	vector<string> GetPossibleMoves(Piece*** board);
private:
};
#endif
