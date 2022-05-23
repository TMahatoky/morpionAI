#include <iostream>
#include <limits>
#define SIDE 3 //length of the board
class Jeu {
	private:
		int prof;
	public:
		void setprof(int pr);
		int getprof();
		void start();
		void initialise(char board[][SIDE]); 
		void showBoard(char board[][SIDE]);
		void showInstructions(); 
		void declareWinner(int whoseTurn);
		bool rowCrossed(char board[][SIDE]);  
		bool columnCrossed(char board[][SIDE]);
		bool diagonalCrossed(char board[][SIDE]);
		bool gameOver(char board[][SIDE]);
		int minimax(char board[][SIDE], int depth, bool isAI);
		int bestMove(char board[][SIDE]);
		void play(int whoseTurn);  
};
