#include "Queen.h"
#include <vector>
#include <string>

//Default Constructor
Queen::Queen() {
	this->SetColor(true);
	this->SetRank(-1);
	this->SetFile(-1);
	this->SetValue(9);
}
Queen::Queen(bool color, int rank, int file) {
	this->SetColor(color);
	this->SetRank(rank);
	this->SetFile(rank);
	this->SetValue(9);
}
//Destructor
Queen::~Queen() {

}
// Get Possible Moves 
//Getters
vector<string> Piece::GetPossibleMoves(unique_ptr<Piece> board[8][8])
{
	vector<string> possibleMoves;
	return possibleMoves;
}