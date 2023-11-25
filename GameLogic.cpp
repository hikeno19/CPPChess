#include "GameLogic.h"
#include <vector>
#include <string>

using namespace std;

//Constructor
GameLogic::GameLogic() {
    this->board = new Piece * *[8];
    this->currentSide = true;
}
//Destructor
GameLogic::~GameLogic() {

}
//Check Current Game Status
bool GameLogic::CheckGameStatus() {
    if(checkCheck()) {
    }
    return true;
}
bool GameLogic::checkCheck()
{
    return false;
}
// Get's King's position.
vector<int> GameLogic::GetKingPosition(bool color)
{
    size_t i, j;
    size_t increment;
    if (color) {
        i = 0;
        increment++;
    }
    else {
        i = 7;
        increment--;
    }
    for (i; i < 8; i = i + increment) {
        for (j = 0; j < 8; j++) {
            if (dynamic_cast<King*>(this->board[i][j]) != nullptr) {
                return { static_cast<int>(i), static_cast<int>(j) };
            }
        }
    }
    return { -1, -1 };
}

// Get King's Possible Moves
vector<string> GameLogic::GetKingMoves(bool color)
{
    return vector<string>();
}
vector<string> GameLogic::GetMovesFromPosition()
{
    return vector<string>();
}
//Initiate New Game. Where while loop will lie. 
void GameLogic::Initiate() {
    NewBoard();
	GameIsOn = true;
	bool played = true;
	while (GameIsOn) {

	}
}
//New Board
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