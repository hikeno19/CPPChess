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

//Getters
vector<string> Piece::GetPossibleMoves(unique_ptr<Piece> board[8][8])
{
	vector<string> possibleMoves;
	return possibleMoves;
}