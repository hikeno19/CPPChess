#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Piece
{
	public:
		//Constructors
		Piece();
		Piece(bool color, int rank, int file, int points);
		// Virtual Destructor for Polymorphism
		virtual ~Piece();
		//Getters
		virtual vector<string> GetPossibleMoves(unique_ptr<Piece> board[8][8]);
		bool GetColor() const;
		int GetRank() const;
		int GetFile() const;
		int GetValue() const;
		string GetSymbol() const;
		string SetName() const;
		//Setters
		void SetColor(bool color);
		void SetRank(int rank);
		void SetFile(int file);
		void SetValue(int value);
		void SetName(string name);
		void SetSymbol(string symbol);
		string ToString();

	private:
		// variables 
		bool color;
		int rank;
		int file;
		int value;
		string name;
		string symbol;
};

#endif