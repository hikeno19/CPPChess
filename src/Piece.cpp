#include "Piece.h"
#include <vector>
#include <string>
 
//Default Constructor
Piece::Piece() {
	this->color = true;
	this->value = 0;
	this->rank = -1;
	this->file = -1;
	this->name = "Piece";
	this->symbol = "";
}
//Constructor
Piece::Piece(bool color, int rank, int file, int point) {
	this->color = color;
	this->rank = rank;
	this->file = file;
	this->value = point;
}
//Destructor
Piece::~Piece() {
}
//Getters
vector<string> Piece::GetPossibleMoves(unique_ptr<Piece> board[8][8])
{
	vector<string> possibleMoves;
	return possibleMoves;
}
bool Piece::GetColor() const{
	return this->color;
}
int Piece::GetRank() const{
	return this->rank;
}
int Piece::GetFile() const{
	return this->file;
}
int Piece::GetValue() const{
	return this->value;
}
string Piece::GetSymbol() const {
	return this->symbol;
}
//Setters
string Piece::SetName() const {
	return this->name;
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
void Piece::SetName(string name) {
	this->name = name;
}
void Piece::SetSymbol(string symbol) {
	this->symbol = symbol;
}
// To String
string Piece::ToString() {
	return "[" + symbol + "]";
}
