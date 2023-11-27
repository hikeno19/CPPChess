#include "Board.h"
#include <string>
#include <vector>

using namespace std;

class GameLogic
{
	public:
		GameLogic();
		~GameLogic();

		void Initiate();
		vector<string> PromptMove();
		string GetCurrentPlayer();
		string GetOppositePlayer();


	private:
		// Board instance 
		Board* board;

		//variables
		bool GameIsOn;
		bool currentSide;
		string position;
		int moveCount;
};

