#include "Jeu.hpp" 
using namespace std; 

#define COMPUTER 1 
#define HUMAN 2 
// Computer will move with 'O' 
// and human with 'X' 
#define COMPUTERMOVE 'O' 
#define HUMANMOVE 'X' 
void Jeu::setprof(int pr){
	prof = pr;
}
int Jeu::getprof(){
	return prof;
}
// A function to show the current board status 
void Jeu::showBoard(char board[][SIDE]) {  

    cout << "\t\t\t " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "\t\t\t-----------\n"; 
    cout << "\t\t\t " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "\t\t\t-----------\n";   
    cout << "\t\t\t " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;

} 

// A function to show the instructions 
void Jeu::showInstructions() { 
	cout << "\nChoose a cell going from 1 to 9 as below and play\n\n"; 
	 
	cout << "\t\t\t 1 | 2 | 3  \n"; 
    cout << "\t\t\t------------\n"; 
    cout << "\t\t\t 4 | 5 | 6  \n"; 
    cout << "\t\t\t------------\n";  
    cout << "\t\t\t 7 | 8 | 9  \n\n";

} 


// A function to initialise the game 
void Jeu::initialise(char board[][SIDE]) {	
	// Initially the board is empty 
	for (int i=0; i<SIDE; i++) { 
		for (int j=0; j<SIDE; j++) 
			board[i][j] = ' '; 
	} 
} 

// A function to declare the winner of the game 
void Jeu::declareWinner(int whoseTurn) { 
	if (whoseTurn == COMPUTER) 
		cout << "COMPUTER has won" << endl; 
	else
		cout << "HUMAN has won" << endl; 
} 

// A function that returns true if any of the row 
// is crossed with the same player's move 
bool Jeu::rowCrossed(char board[][SIDE]) { 
	for (int i=0; i<SIDE; i++) { 
		if (board[i][0] == board[i][1] && 
			board[i][1] == board[i][2] &&  
			board[i][0] != ' ') 
			return (true);
	} 
	return(false); 
} 

// A function that returns true if any of the column 
// is crossed with the same player's move 
bool Jeu::columnCrossed(char board[][SIDE]) { 
	for (int i=0; i<SIDE; i++) { 
		if (board[0][i] == board[1][i] && 
			board[1][i] == board[2][i] && 
			board[0][i] != ' ') 
			return (true);
	} 
	return(false); 
} 

// A function that returns true if any of the diagonal 
// is crossed with the same player's move 
bool Jeu::diagonalCrossed(char board[][SIDE]) { 
	if (board[0][0] == board[1][1] && 
		board[1][1] == board[2][2] &&
		board[0][0] != ' ') 
		return(true); 
		
	if (board[0][2] == board[1][1] && 
		board[1][1] == board[2][0] && 
		board[0][2] != ' ') 
		return(true);

	return(false); 
} 

// A function that returns true if the game is over 
// else it returns a false 
bool Jeu::gameOver(char board[][SIDE]) { 
	return(rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board) ); 
}

// Function to calculate best score
int Jeu::minimax(char board[][SIDE], int depth, bool isAI){
	int score = 0;
	int bestScore = 0;
	if (gameOver(board) == true){
		if (isAI == true)
			return -1;
		if (isAI == false)
			return +1;
	}
	else{
		if(depth < 9){
			if(isAI == true){
				bestScore = -999;
				for(int i=0; i<SIDE; i++){
					for(int j=0; j<SIDE; j++){
						if (board[i][j] == ' '){
							board[i][j] = COMPUTERMOVE;
							score = minimax(board, depth + 1, false);
							board[i][j] = ' ';
							if(score > bestScore){
								bestScore = score;
							}
						}
					}
				}
				return bestScore;
			}
			else{
				bestScore = 999;
				for (int i = 0; i < SIDE; i++){
					for (int j = 0; j < SIDE; j++){
						if (board[i][j] == ' '){
							board[i][j] = HUMANMOVE;
							score = minimax(board, depth + 1, true);
							board[i][j] = ' ';
							if (score < bestScore){
								bestScore = score;
							}
						}
					}
				}
				return bestScore;
			}
		}
		else{
			return 0;
		}
	}
}

// Function to calculate best move
int Jeu::bestMove(char board[][SIDE]){
	int x = -1, y = -1;
	int score = 0, bestScore = -999;
	for (int i = 0; i < SIDE; i++){
		for (int j = 0; j < SIDE; j++){
			if (board[i][j] == ' '){
				board[i][j] = COMPUTERMOVE;
				score = minimax(board, getprof() +1, false);
				board[i][j] = ' ';
				if(score > bestScore){
					bestScore = score;
					x = i;
					y = j;
				}
			}
		}
	}
	return x*3+y;
}

// A function to play Morpion
void Jeu::play(int whoseTurn) { 
	char board[SIDE][SIDE]; 
	int moveIndex = 0, x = 0, y = 0;

	initialise(board);
	showInstructions(); 
	
	// Keep playing till the game is over or it is a draw 
	while (gameOver(board) == false && moveIndex != SIDE*SIDE) { 
		int n;
		if (whoseTurn == COMPUTER) {
			n = bestMove(board);
			x = n / SIDE;
			y = n % SIDE;
			board[x][y] = COMPUTERMOVE; 
			cout << "COMPUTER has put a "<< COMPUTERMOVE << " in cell " << n+1 << "\n\n";
			showBoard(board);
			moveIndex ++; 
			whoseTurn = HUMAN;
		} 
		
		else if (whoseTurn == HUMAN) {
			cout << "You can insert in the following positions : ";
			for(int i=0; i<SIDE; i++)
				for (int j = 0; j < SIDE; j++)
					if (board[i][j] == ' ')
						cout << (i * 3 + j) + 1 <<" ";
			back:
			cout << "\n\nThen enter the position " << endl;
			cin >> n;
			if (cin.fail()) {
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        		cout << "Bad input, please only enter numbers" << "\n" << endl;
        		goto back;
			}
			n--;
			x = n / SIDE;
			y = n % SIDE; 
			if(board[x][y] == ' ' && n<9 && n>=0){
				board[x][y] = HUMANMOVE; 
				cout << "\nHUMAN has put a " << HUMANMOVE << " in cell " << n+1 << "\n\n"; 
				showBoard(board); 
				moveIndex ++; 
				whoseTurn = COMPUTER;
			}
			else if(board[x][y] != ' ' && n<9 && n>=0){
				cout << "\nPosition is occupied, select any one place from the available places\n\n";
			}
			else if(n<0 || n>8){
				cout << "Invalid position" << endl;
			}
		} 
	} 

	// If the game has drawn 
	if (gameOver(board) == false && moveIndex == SIDE * SIDE) 
		cout << "It's a draw" << endl; 
	else{ 
		// Toggling the user to declare the actual winner 
		if (whoseTurn == COMPUTER) 
			whoseTurn = HUMAN; 
		else if (whoseTurn == HUMAN) 
			whoseTurn = COMPUTER; 
		
		declareWinner(whoseTurn); 
	} 
} 

void Jeu::start() { 
	cout << "\n-------------------------------------------------------------------\n\n";
	cout << "\t\t\t Morpion \n"; 
	cout << "\n-------------------------------------------------------------------\n\n";
	string cont="n";
	while(cont=="n"){
		string choice;
		repeat:
	 	cout << "Do you want to start first?(y/n) : ";
	 	cin >> choice;

		if(choice=="n")
			play(COMPUTER);
		else if(choice=="y")
			play(HUMAN);
		else{
			cout << "Invalid choice" << endl;
			if(cin.fail()){
				cout << "test" << endl;
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        		cout << "Bad input, please only enter either y or n" << "\n" << endl;
				goto repeat;
			}
			else{
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				goto repeat;
			}
		}
        up :
		cout << "\nDo you want to quit(y/n) : ";
       	cin >> cont;
			if(cont =="y")
				break;
			else if (cont!="y"&& cont!="n"){  
			    if(cin.fail()){
        			cin.clear();
        			cin.ignore(numeric_limits<streamsize>::max(), '\n');
        			cout << "Bad input, please only enter either y or n" << "\n" << endl;
        			goto up;
    		    }
				else{
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					goto up;
				}
	        } 
	}
} 
