#include "Rook.h"
#include <vector>
#include <string>

// Default Constructor
Rook::Rook(){
	this->SetColor(true);
	this->SetRank(-1);
	this->SetFile(-1);
	this->SetValue(5);
	this->SetName("Rook");
	this->SetSymbol("♖");
}
// Constructor
Rook::Rook(bool color, int rank, int file){
	this->SetColor(color);
	this->SetRank(rank);
	this->SetFile(rank);
	this->SetValue(5);
	this->SetName("Rook"); 
	this->SetSymbol((color) ? "♖" : "♜");
}
// Destructor
Rook::~Rook() {
}

//Getters
vector<string> Piece::GetPossibleMoves(unique_ptr<Piece> board[8][8])
{
	vector<string> possibleMoves;
	return possibleMoves;
}
