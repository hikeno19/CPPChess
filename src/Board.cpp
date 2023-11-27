#include "Board.h"
#include <vector>
#include <string>
#include <iostream>

// constructor
Board::Board() {
    this->whiteKingPosition = "-1-1";
    this->blackKingPosition = "-1-1";
}

// destructor
Board::~Board() {

}

void Board::NewBoard() {
    // Create a new board
    for (size_t i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            this->board[i][j] = nullptr;
        }
    }

    // Initializes White Pieces onto Board
    this->board[0][0] = make_unique<Rook>(true, 0, 0);
    this->board[0][1] = make_unique<Knight>(true, 0, 1);
    this->board[0][2] = make_unique<Bishop>(true, 0, 2);
    this->board[0][3] = make_unique<Queen>(true, 0, 3);
    this->board[0][4] = make_unique<King>(true, 0, 4);
    this->whiteKingPosition = to_string(0) + to_string(4); /* Setting king's initial position to variables */
    this->board[0][5] = make_unique<Bishop>(true, 0, 5);
    this->board[0][6] = make_unique<Knight>(true, 0, 6);
    this->board[0][7] = make_unique<Rook>(true, 0, 7);
    this->board[1][0] = make_unique<Pawn>(true, 1, 0);
    this->board[1][1] = make_unique<Pawn>(true, 1, 1);
    this->board[1][2] = make_unique<Pawn>(true, 1, 2);
    this->board[1][3] = make_unique<Pawn>(true, 1, 3);
    this->board[1][4] = make_unique<Pawn>(true, 1, 4);
    this->board[1][5] = make_unique<Pawn>(true, 1, 5);
    this->board[1][6] = make_unique<Pawn>(true, 1, 6);
    this->board[1][7] = make_unique<Pawn>(true, 1, 7);

    // Initializes Black Pieces onto Board
    this->board[7][0] = make_unique<Rook>(false, 7, 0);
    this->board[7][1] = make_unique<Knight>(false, 7, 1);
    this->board[7][2] = make_unique<Bishop>(false, 7, 2);
    this->board[7][3] = make_unique<Queen>(false, 7, 3);
    this->board[7][4] = make_unique<King>(false, 7, 4);
    this->blackKingPosition = to_string(7) + to_string(4); /* Setting king's initial position to variables */
    this->board[7][5] = make_unique<Bishop>(false, 7, 5);
    this->board[7][6] = make_unique<Knight>(false, 7, 6);
    this->board[7][7] = make_unique<Rook>(false, 7, 7);
    this->board[6][0] = make_unique<Pawn>(false, 6, 0);
    this->board[6][1] = make_unique<Pawn>(false, 6, 1);
    this->board[6][2] = make_unique<Pawn>(false, 6, 2);
    this->board[6][3] = make_unique<Pawn>(false, 6, 3);
    this->board[6][4] = make_unique<Pawn>(false, 6, 4);
    this->board[6][5] = make_unique<Pawn>(false, 6, 5);
    this->board[6][6] = make_unique<Pawn>(false, 6, 6);
    this->board[6][7] = make_unique<Pawn>(false, 6, 7);
}

// Get's King's position.
string Board::GetKingPosition(bool color)
{
    return color ? whiteKingPosition : blackKingPosition;
}

// Get King's Possible Moves
vector<string> Board::GetKingPossibleMoves(bool color)
{
    return GetPiecePossibleMoves(GetKingPosition(color));
}

// Gets Possible Moves of Piece on a Position
vector<string> Board::GetPiecePossibleMoves(string position)
{
    return this->board[position[0] - '0'][position[1] - '0']->GetPossibleMoves(this->board);
}

// Checks for checkmate
bool Board::CheckCheckmate(bool currentSide) {
    if (CheckCheck(currentSide)) {
        if (GetKingPossibleMoves(currentSide).empty()) {
            return true;
        }
    }
    return false;
}

// Checks if the current player is in check. 
bool Board::CheckCheck(bool currentSide) {
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

// Make Move.
bool Board::MakeMove(vector<int> move)
{
    this->board[move[2]][move[3]] = std::move(this->board[move[0]][move[1]]);
    this->board[move[0]][move[1]] = std::move(nullptr);
    return true;
}

// Returns all moves that enemy pieces can move to. Enemy based on currentSide boolean. 
vector<string> Board::GetEnemyPossibleMoves(bool currentSide) {
    vector<string> output;
    size_t i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (GetColorOfPosition(static_cast<int>(i), static_cast<int>(j)) != currentSide) {
                output.insert(output.end(), this->board[i][j]->GetPossibleMoves(this->board).begin(), this->board[i][j]->GetPossibleMoves(this->board).end());
            }
        }
    }
    return output;
}

// Gets pointer to Piece at Position.
Piece* Board::GetPieceAt(int rank, int file)
{
    return this->board[rank][file].get();
}

// Checks if position is occupied, null or not.
bool Board::isOccupied(int rank, int file) {
    if (this->board[rank][file] != nullptr) {
        return true;
    }
    else {
        return false;
    }
}

// Checks the color of the piece on position.
bool Board::GetColorOfPosition(int rank, int file) {
    return this->board[rank][file]->GetColor();
}

// Checks if the number is in range of the board.
bool Board::inRange(int n) {
    if (n >= 0 && n <= 7) {
        return true;
    }
    return false;
}

// Checks if the coordinate is in range of the board.
bool Board::inRangeCoordinates(int x, int y) {
    if (inRange(x) && inRange(y)) {
        return true;
    }
    return false;
}

// Get Board
Board* Board::GetBoard() {
    // Create a new Board object and initialize it with the current state
    Board* newBoard = new Board();

    // Copy the state of the pieces to the new board
    for (size_t i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (this->board[i][j] != nullptr) {
                newBoard->board[i][j] = std::make_unique<Piece>(*this->board[i][j]);
            }
        }
    }

    // Copy other board state variables if needed

    return newBoard;
}

// Tests Pawn's Move
bool Board::TestPawnMove(int srank, int sfile, int erank, int efile, bool currentSide)
{
    Board* boardState = GetBoard();
    if (inRangeCoordinates(srank, sfile) && inRangeCoordinates(erank, efile)) {
        if (isOccupied(srank, sfile) && GetColorOfPosition(erank, efile) != currentSide) {
            boardState->MakeMove({srank, sfile, erank, efile});
            if (!boardState->CheckCheck(currentSide)) {
                return true;
            }
        }
    }
    return false;
}

// Tests Move. 
bool Board::TestMove(int srank, int sfile, int erank, int efile, bool currentSide)
{
    Board* boardState = GetBoard();
    if (inRangeCoordinates(srank, sfile) && inRangeCoordinates(erank, efile)) {
        if (!isOccupied(erank, efile)) {
            boardState->MakeMove({ srank, sfile, erank, efile });
            if (!boardState->CheckCheck(currentSide)) {
                return true;
            }
        }
        else if (this->GetColorOfPosition(erank, efile) != currentSide) {
            if (!boardState->CheckCheck(currentSide)) {
                return true;
            }
        }
    }
    return false;
}

// Print Board
void Board::PrintBoard() {
    cout << "Board:" << endl;
    for (int i = 7; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            if (this->board[i][j] != nullptr) {
                cout << this->board[i][j]->ToString() << " ";
            }
        }
        cout << endl;
    }
}