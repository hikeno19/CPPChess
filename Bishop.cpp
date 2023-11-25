#include "Bishop.h"

//Default Constructor
Bishop::Bishop() {
	this->SetColor(true);
	this->SetRank(-1);
	this->SetFile(-1);
	this->SetValue(3);
}
Bishop::Bishop(bool color, int rank, int file) {
	this->SetColor(color);
	this->SetRank(rank);
	this->SetFile(rank);
	this->SetValue(3);
}
//Destructor
Bishop::~Bishop() {

}

vector<string> Bishop::GetPossibleMoves(Piece*** board)
{
	return vector<string>();
}
