#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>

using namespace std;

class Piece
{
	public:
		//Constructors
		Piece();
		Piece(bool color, int rank, int file, int points);
		// Virtual Destructor for Polymorphism
		virtual ~Piece() {}
		//Destructor
		~Piece();
		//Getters
		vector<string> GetPossibleMoves(Piece*** board);
		bool GetColor();
		int GetRank();
		int GetFile();
		int GetValue();
		//Setters
		void SetMoves(vector<string>moves);
		void SetColor(bool color);
		void SetRank(int rank);
		void SetFile(int file);
		void SetValue(int value);
		// variables 
		bool color;
		vector<string> moves;
	private:
		int rank;
		int file;
		int value;
};

#endif