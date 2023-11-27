#include "Pawn.h"
#include <vector>
#include <string>

// Default Constructor
Pawn::Pawn() {
	this->SetColor(true);
	this->SetRank(-1);
	this->SetFile(-1);
	this->SetValue(1);
}
// Constructor
Pawn::Pawn(bool color, int rank, int file) {
	this->SetColor(color);
	this->SetRank(rank);
	this->SetFile(rank);
	this->SetValue(1);
}
//Getters
vector<string> Piece::GetPossibleMoves(unique_ptr<Piece> board[8][8])
{
	vector<string> possibleMoves;
	return possibleMoves;
}
// Destructor
Pawn::~Pawn() {
}