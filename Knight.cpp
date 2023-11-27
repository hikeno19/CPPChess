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

//Getters
vector<string> Piece::GetPossibleMoves(unique_ptr<Piece> board[8][8])
{
	vector<string> possibleMoves;
	return possibleMoves;
}
