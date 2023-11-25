#include "King.h"
#include <vector>
#include <string>

//Default Constructor
King::King() {
	this->SetColor(true);
	this->SetRank(-1);
	this->SetFile(-1);
	this->SetValue(-1);
}
King::King(bool color, int rank, int file) {
	this->SetColor(color);
	this->SetRank(rank);
	this->SetFile(rank);
	this->SetValue(-1);
}
//Destructor
King::~King() {

}

vector<string> King::GetPossibleMoves(Piece*** board)
{
	return vector<string>();
}
