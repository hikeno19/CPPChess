#include "Piece.h"
#include <vector>
#include <string>
 
//Default Constructor
Piece::Piece() {
	this->color = true;
	this->moves = vector<string>();
	this->value = 0;
}
//Constructor
Piece::Piece(bool color, int rank, int file, int point) {
	this->color = color;
	this->rank = rank;
	this->file = file;
	this->value = point;
	this->moves = vector<string>();
}
//Destructor
Piece::~Piece() {
}
//Getters
vector<string> Piece::GetPossibleMoves(Piece*** board)
{
	return vector<string>();
}
bool Piece::GetColor() {
	return this->color;
}
int Piece::GetRank() {
	return this->rank;
}
int Piece::GetFile() {
	return this->file;
}
int Piece::GetValue() {
	return this->value;
}
//Setters
void Piece::SetMoves(vector<string>moves) {
	this->moves = moves;
}
void Piece::SetColor(bool color) {
	this->color = color;
}
void Piece::SetRank(int rank) {
	this->rank = rank;
}
void Piece::SetFile(int file) {
	this->file = file;
}
void Piece::SetValue(int value) {
	this->value = value;
}
