#include "Knight.h"
#include <vector>
#include <string>

//Default Constructor
Knight::Knight() {
	this->SetColor(true);
	this->SetRank(-1);
	this->SetFile(-1);
	this->SetValue(3);
}
Knight::Knight(bool color, int rank, int file) {
	this->SetColor(color);
	this->SetRank(rank);
	this->SetFile(rank);
	this->SetValue(3);
}
//Destructor
Knight::~Knight() {

}

vector<string> Knight::GetPossibleMoves(Piece*** board)
{
	return vector<string>();
}
