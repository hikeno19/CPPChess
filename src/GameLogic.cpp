#include "GameLogic.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>

using namespace std;

// Constructor
GameLogic::GameLogic() {
    this->board = new Board();
    this->currentSide = true;
    this->moveCount = 0;
    this->GameIsOn = false;
}

// Destructor
GameLogic::~GameLogic() {
}

// Initiate New Game. Where while loop will lie. 
void GameLogic::Initiate() {
	this->GameIsOn = true;
    board->NewBoard();
	while (this->GameIsOn) {
        vector<string> move = PromptMove();
        if (move.empty()) {
            cout << "Checkmate! " << GetOppositePlayer() << " Wins!" << endl;
            this->GameIsOn = false;
            break;
        }
        if (board->MakeMove(move)) {
            moveCount++;
            currentSide = !currentSide;
        }
	}
}

// Get Current Player
string GameLogic::GetCurrentPlayer() {
    return currentSide ? "White" : "Black";
}

string GameLogic::GetOppositePlayer() {
    return  currentSide ? "Black" : "White";
}

// Prompts User For Move
vector<string> GameLogic::PromptMove() {
    cout << "Current Player: " << GetCurrentPlayer() << endl;
    if (board->CheckCheckmate(currentSide)) {
        cout << "Checkmate!" << endl;
        return {};
    }
    if (board->CheckCheck(currentSide)) {
        cout << "In Check!" << endl;
    }
    cout << "Enter Piece Location:";
    string start, end;
    cin >> start;
    cout << "Enter Move Location:";
    cin >> end;
    return { start, end };
}
