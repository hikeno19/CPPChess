#include "Queen.h"
#include <vector>
#include <string>

//Default Constructor
Queen::Queen() {
	this->SetColor(true);
	this->SetRank(-1);
	this->SetFile(-1);
	this->SetValue(9);
	this->SetName("Queen");
	this->SetSymbol("♕");
}
Queen::Queen(bool color, int rank, int file) {
	this->SetColor(color);
	this->SetRank(rank);
	this->SetFile(rank);
	this->SetValue(9);
	this->SetName("Queen");
	this->SetSymbol((color) ? "♕" : "♛");
}
//Destructor
Queen::~Queen() {

}

// Get Possible Moves 
vector<string> Piece::GetPossibleMoves(unique_ptr<Piece> board[8][8])
{
	vector<string> possibleMoves;
	return possibleMoves;
}