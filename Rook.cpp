#include "Rook.h"
#include <vector>
#include <string>

// Default Constructor
Rook::Rook(){
	this->SetColor(true);
	this->SetRank(-1);
	this->SetFile(-1);
	this->SetValue(5);
}
// Constructor
Rook::Rook(bool color, int rank, int file){
	this->SetColor(color);
	this->SetRank(rank);
	this->SetFile(rank);
	this->SetValue(5);
}
// Destructor
Rook::~Rook() {
}

vector<string> Rook::GetPossibleMoves(Piece*** board)
{
	return vector<string>();
}
