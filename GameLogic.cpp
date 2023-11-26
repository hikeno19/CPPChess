#include "GameLogic.h"
#include <vector>
#include <string>

using namespace std;

// Constructor
GameLogic::GameLogic() {
    this->board = new Piece * *[8];
    this->currentSide = true;
    this->whiteKingPosition = "-1-1";
    this->blackKingPosition = "-1-1";
}

// Destructor
GameLogic::~GameLogic() {
}

// Checks for checkmate
bool GameLogic::CheckCheckmate() const{
    if(CheckCheck()) {
        if (GetKingPossibleMoves(currentSide).empty()) {
            return true;
        }
    }
    return false;
}

// Checks if the current player is in check. 
bool GameLogic::CheckCheck() const {
    for (size_t i = 0; i < 8; ++i) {
        for (size_t j = 0; j < 8; ++j) {
            if (this->board[i][j] != nullptr && this->board[i][j]->GetColor() != currentSide) {
                vector<string> moves = this->board[i][j]->GetPossibleMoves(this->board);
                auto it = find(moves.begin(), moves.end(), GetKingPosition(currentSide));

                if (it != moves.end()) {
                    return true;  // The king is in check
                }
            }
        }
    }

    return false;  // The king is not in check after checking all pieces
}

// Get's King's position.
string GameLogic::GetKingPosition(bool color) 
{
    return color ? whiteKingPosition : blackKingPosition;
}
 
// Get King's Possible Moves
string** GameLogic::  GetKingPossibleMoves(bool color)
{
    return GetPiecePossibleMoves(GetKingPosition(color));
}

// Gets Possible Moves of Piece on a Position
string** GameLogic::GetPiecePossibleMoves(string position) 
{
    return this->board[position[0] - '0'][position[1] - '0']->GetPossibleMoves(this->board);
}

// Returns all moves that enemy pieces can move to. Enemy based on currentSide boolean. 
string** GameLogic::GetEnemyPossibleMoves()
    vector<string> output;
    size_t i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (this->board[i][j]->GetColor() != currentSide) {
                output.insert(output.end(), this->board[i][j]->GetPossibleMoves(this->board).begin(), this->board[i][j]->GetPossibleMoves(this->board).end());
            }
        }
    }
    return output;
}

// Initiate New Game. Where while loop will lie. 
void GameLogic::Initiate() {
    NewBoard();
	GameIsOn = true;
	bool played = true;
	while (GameIsOn) {

	}
}

// New Board
void GameLogic::NewBoard() {
    // Delete the existing board if it exists
    if (this->board != nullptr) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                delete this->board[i][j];
            }
            delete[] this->board[i];
        }
        delete[] this->board;
    }

    // Create a new board
    this->board = new Piece**[8];

    // Initializes White Pieces onto Board
    this->board[0][0] = new Rook(true, 0, 0);
    this->board[0][1] = new Knight(true, 0, 1);
    this->board[0][2] = new Bishop(true, 0, 2);
    this->board[0][3] = new Queen(true, 0, 3);
    this->board[0][4] = new King(true, 0, 4);
    this->whiteKingPosition = to_string(0) + to_string(4); /* Setting king's initial position to variables */
    this->board[0][5] = new Bishop(true, 0, 5);
    this->board[0][6] = new Knight(true, 0, 6);
    this->board[0][7] = new Rook(true, 0, 7);
    this->board[1][0] = new Pawn(true, 1, 0);
    this->board[1][1] = new Pawn(true, 1, 1);
    this->board[1][2] = new Pawn(true, 1, 2);
    this->board[1][3] = new Pawn(true, 1, 3);
    this->board[1][4] = new Pawn(true, 1, 4);
    this->board[1][5] = new Pawn(true, 1, 5);
    this->board[1][6] = new Pawn(true, 1, 6);
    this->board[1][7] = new Pawn(true, 1, 7);

    // Initializes Black Pieces onto Board
    this->board[7][0] = new Rook(false, 7, 0);
    this->board[7][1] = new Knight(false, 7, 1);
    this->board[7][2] = new Bishop(false, 7, 2);
    this->board[7][3] = new Queen(false, 7, 3);
    this->board[7][4] = new King(false, 7, 4);
    this->blackKingPosition = to_string(7) + to_string(4); /* Setting king's initial position to variables */
    this->board[7][5] = new Bishop(false, 7, 5);
    this->board[7][6] = new Knight(false, 7, 6);
    this->board[7][7] = new Rook(false, 7, 7);
    this->board[6][0] = new Pawn(false, 6, 0);
    this->board[6][1] = new Pawn(false, 6, 1);
    this->board[6][2] = new Pawn(false, 6, 2);
    this->board[6][3] = new Pawn(false, 6, 3);
    this->board[6][4] = new Pawn(false, 6, 4);
    this->board[6][5] = new Pawn(false, 6, 5);
    this->board[6][6] = new Pawn(false, 6, 6);
    this->board[6][7] = new Pawn(false, 6, 7);

    // Set rest of the tiles as nullptr. 
    size_t i, j;
    for (i = 2; i < 6; i++) {
        for (j = 0; j < 8; j++) {
            this->board[i][j] = nullptr;
        }
    }

}