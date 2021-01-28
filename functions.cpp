/******************************************************************************
 *	PROGRAMMED BY : Utsav Parajuli
 *	ASSIGNMENT #2 : Multi-Dimensional Array - Tic Tac Toe
 *	CLASS         : CS1B
 *	SECTION       : MW: 7:30pm - 9:50pm
 *	DUE DATE	  : 03/11/2020
 ******************************************************************************/

#include "as2.h"

/*******************************************************************************
 * ----------------------------------------------------------------------------
 * FUNCTION OutputInstruct
 * ----------------------------------------------------------------------------
 * This function will output instructions to the users that they have to choose
 * from.
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		The following parameters need to have a defined value prior to calling
 * 		the function:
 * 					No pre-defined values
 *
 * POST-CONDITIONS
 * 		This function will output the instructions. No return.
 ******************************************************************************/
void OutputInstruct()
{
	cout << "\nMAIN MENU\n"
		 << "a.  Exit\n"
		 << "b.  Set Player Names\n"
		 << "c.  Play in Two Player Mode\n"
		 << "d.  Play in One Player Mode\n\n";
}

/*******************************************************************************
 * ----------------------------------------------------------------------------
 * FUNCTION InitBoard
 * ----------------------------------------------------------------------------
 * This function will initialize each spot in the board to a blank space ' '.
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		The following parameters need to have a defined value prior to calling
 * 		the function:
 * 					boardAr[][NUM_COLS] : the array for tic tac toe board
 *
 * POST-CONDITIONS
 * 		This function will return:
 * 					boardAr[][]: it initializes all the spots to a blank space
 ******************************************************************************/
void InitBoard(char boardAr[][NUM_COLS])
{
	int rowCnt; //CALC & CALC - count for the rows
	int colCnt; //CALC & CALC - count for the columns

	for (rowCnt = 0; rowCnt < NUM_ROWS; rowCnt++)
	{
		for (colCnt = 0; colCnt < NUM_COLS; colCnt++)
		{
			boardAr[rowCnt][colCnt]=' ';
		}
	}
}

/*******************************************************************************
 * ----------------------------------------------------------------------------
 * FUNCTION DisplayBoard
 * ----------------------------------------------------------------------------
 * This function will output the tic tac toe board with the tokens that players
 * inputed.
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		The following parameters need to have a defined value prior to calling
 * 		the function:
 * 					boardAr[][NUM_COLS] : the array for tic tac toe board
 *
 * POST-CONDITIONS
 * 		This function will return:
 * 					no return it outputs the current state of the board
 ******************************************************************************/

void DisplayBoard(const char boardAr[][NUM_COLS])
{
	int rowCnt; //CALC & CALC - count for the rows in the board
	int colCnt; //CALC & CALC - count for the columns in the board

	cout << endl << endl;
	cout << setw(10) << "1" << setw(8) << "2" << setw(9) << "3\n";

	//PROCESSING - uses a for loop to output the board in a correct tic tac
	// 			   toe format
	for (rowCnt = 0; rowCnt < NUM_ROWS; rowCnt++)
	{
		cout << setw(7) << "[" << rowCnt+1 << "][1] | " << "[" << rowCnt+1;
		cout << "][2] | " << "[" << rowCnt+1 << "][3]" << endl;
		cout << setw(14) << "|" << setw(9) << "|" << endl;

		for (colCnt = 0; colCnt < NUM_COLS; colCnt++)
		{
			switch(colCnt)
			{
			case 0: cout << rowCnt + 1 << setw(9) << boardAr[rowCnt][colCnt];
			 cout << setw(4) << "|";
			 break;

			case 1: cout << setw(4) << boardAr[rowCnt][colCnt];
			 cout << setw(5) << "|";
			 break;

			case 2: cout << setw(4) << boardAr[rowCnt][colCnt] << endl;
			 break;
			default: cout <<"ERROR!\n\n";
			}
		}

		cout << setw(14)<< "|" << setw(10) << "|\n";

		if (rowCnt != 2)
		{
			cout << setw(32) << "--------------------------\n";
		}
	}

	cout << endl << endl;
}

/*******************************************************************************
 * ----------------------------------------------------------------------------
 * FUNCTION GetPlayers
 * ----------------------------------------------------------------------------
 * This function will prompt the user and gets the names of both players.
 * The first player will be allowed to choose what token they would like to use
 * and the player that chose 'X' token will be assigned to playerX and 'O' token
 * for playerO.
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		The following parameters need to have a defined value prior to calling
 * 		the function:
 * 					no predefined values
 *
 * POST-CONDITIONS
 * 		This function will share the data of playerX and playerO back to the
 * 		calling function as it is passed by reference:
 * 					playerX: player with the X token
 * 					playerO: player with the O token
 ******************************************************************************/


void GetPlayers(string &playerX, string &playerO)
{
	char token;		//IN & CALC - token of the player
	string name1;	//IN & CALC - name of player 1
	string name2;	//IN & CALC - name of player 2

	//Prompts the user to input the first name
	cout << "\nPlease enter the first player's name: ";
	getline(cin, name1);

	cout << "\nWhat token would you like to choose (enter \'X\' or \'O\')? ";
	cin.get(token);
	cin.ignore(1000,'\n');

	if(toupper(token) == 'X')
	{
		playerX = name1;
		cout << name1 << "! Your token is X!\n";
	}
	else if(toupper(token) == 'O')
	{
		playerO = name1;
		cout << name1 << "! Your token is O!\n";
	}

	//Prompts the user for the name of the second player
	cout << "\nPlease enter the second player's name: ";
	getline(cin, name2);

	if(toupper(token) == 'X')
	{
		playerO = name2;
		cout << name2 << "! Your token is O!\n";
	}
	else if(toupper(token) == 'O')
	{
		playerX = name2;
		cout << name2 << "! Your token is X!\n";
	}
}

/*******************************************************************************
 * ----------------------------------------------------------------------------
 * FUNCTION GetAndCheckInp
 * ----------------------------------------------------------------------------
 * This function will prompt the user to enter the play which will be in the
 * format as on the board. If they want to make a play in spot "[1][1]" they
 * will enter "1 1". It will error check it if the user inputed invalid row or
 * column. It will also check if either of the spots have be taken already.
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		The following parameters need to have a defined value prior to calling
 * 		the function:
 * 					boardAr[][] : array for the rows and colums of tic tac toe
 * 					token       : token of the player
 * 					playerX     : player with token X
 * 					playerY     : player with token Y
 *
 * POST-CONDITIONS
 * 		This function will assign the token to the display board if it is in
 * 		bound and has not been taken already. It will not return anything it
 * 		will only put the token in the proper space in the display board.
 ******************************************************************************/

void GetAndCheckInp (char boardAr[][NUM_COLS], char token, string playerX,
					 string playerO)
{
	int row;	//IN & CALC   - row the user wants to play on
	int col;	//IN & CALC   - column the user wants to play on
	bool valid; //CALC & CALC - checks if the user input is valid

	valid = false;

	/**************************************************************************
	 * PROCESSING - This do while loop will error check if the user inputs are
	 * 				valid. If not valid it will display the error on screen
	 * 				for the user or else it will assign the token to proper
	 * 				space
	 **************************************************************************/
	do
	{
		if (token == 'X')
		{
			cout << endl << playerX << "\'s turn! What is your play?: ";
			cin  >> row >> col;

			row--;
			col--;

			if (row > NUM_ROWS - 1 || row < 0)
			{
				cout << "Invalid row - Please try again!\n";
			}
			else if (col > NUM_COLS - 1 || col < 0)
			{
				cout << "Invalid col - Please try again!\n";
			}
			else if (boardAr[row][col] != ' ')
			{
				cout << "That spot is taken already - try again!\n";
			}
			else
			{
				valid = true;
			}
		}
		else
		{
			cout << endl << playerO << "\'s turn! What is your play?: ";
			cin  >> row >> col;

			row--;
			col--;

			if (row > NUM_ROWS - 1 || row < 0)
			{
				cout << "Invalid row - Please try again!\n";
			}
			else if (col > NUM_COLS - 1 || col < 0)
			{
				cout << "Invalid col - Please try again!\n";
			}
			else if (boardAr[row][col] != ' ')
			{
				cout << "That spot is taken already - try again!\n";
			}
			else
			{
				valid = true;
			}
		}

	}
	while(!valid);

	boardAr[row][col] = token;

	cin.ignore(1000,'\n');
}

/*******************************************************************************
 * ----------------------------------------------------------------------------
 * FUNCTION SwitchToken
 * ----------------------------------------------------------------------------
 * This function will switch the active player. If playerX is playing it will
 * switch to playerO and vice versa.
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		The following parameters need to have a defined value prior to calling
 * 		the function:
 * 					token : Token of the active player
 *
 * POST-CONDITIONS
 * 		This function will return:
 * 					token : Token of the active player after it's been switched
 ******************************************************************************/

char SwitchToken (char token)
{
	if (token == 'X')
	{
		token = 'O';
	}
	else
	{
		token = 'X';
	}
	return token;
}

/*******************************************************************************
 * ----------------------------------------------------------------------------
 * FUNCTION CheckWin
 * ----------------------------------------------------------------------------
 * This function will check to see if either player has run. It will run after
 * every time after the player makes a play. It will check for any possible win
 * condition or tie or indicates if the game can still be continued.
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		The following parameters need to have a defined value prior to calling
 * 		the function:
 * 					boardAr[][NUM_COLS] : array for the rows and cols of tic tac
 * 										  toe board
 *
 * POST-CONDITIONS
 * 		This function will return:
 * 					value : The value of the player that won or indication that
 * 							says if it's a tie or continue playjng
 ******************************************************************************/
char CheckWin (const char boardAr[][NUM_COLS])
{
	char value;		//CALC & OUT  - indication of the winner, tie or continuity
	int  index;		//CALC & CALC - count for the for loop
	int  row;		//CALC & CALC - rows of the board
	int  col;		//CALC & CALC - columns of the baord

	//checks diagonals of the two dimensional array for any win condition
	if (boardAr [0][0] == boardAr [1][1] && boardAr [1][1] == boardAr [2][2])
	{
		return boardAr[0][0];
	}

	else if (boardAr [0][2] == boardAr [1][1] && boardAr [1][1] ==
			 boardAr [2][0])
	{
		return boardAr[0][2];
	}
	//checks the rows and columns for any win condition
	for (index = 0; index < NUM_ROWS; index++)
	{
		if (boardAr[index][0] == boardAr[index][1] && boardAr[index][0] ==
			boardAr[index][2])
		{
			return boardAr[index][0];
		}

		else if(boardAr[0][index] == boardAr[1][index] && boardAr[0][index] ==
				boardAr[2][index])
		{
			return boardAr[0][index];
		}
	}

	//checks if the game is still going to be played on
	for (row = 0;  row < NUM_ROWS; row++)
	{
		for (col = 0; col < NUM_COLS; col++)
		{
			if(boardAr[row][col] == ' ')
			{
				value = 'C';
				return value;
			}
		}
	}

	//if none of the previous segments work the value will indicate the game
	//ended in a tie
	value = 'T';
	return value;
}

/*******************************************************************************
 * ----------------------------------------------------------------------------
 * FUNCTION OutputWinner
 * ----------------------------------------------------------------------------
 * This function will output the winner of the game or outputs an appropriate
 * message if it ended in a tie.
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		The following parameters need to have a defined value prior to calling
 * 		the function:
 * 					whoWon - the character or value of the player that won the
 * 							 game or value that says it's a tie
 *
 * POST-CONDITIONS
 * 		This function will return:
 * 					no return value
 * 					Outputs the winner
 ******************************************************************************/
void OutputWinner(char whoWon, string playerX, string playerO)
{
	//Checks to see who won the game or if it ended in a tie
	switch(whoWon)
	{
	case 'X' :
		cout << endl << playerX << " won the game.\n";
		break;

	case 'O' :
		cout << endl << playerO << " won the game.\n";
		break;

	case 'T' :
		cout << endl << "This game was tied.\n";
	}
}

/*******************************************************************************
 * ----------------------------------------------------------------------------
 * FUNCTION GetAndCheckInpCPU
 * ----------------------------------------------------------------------------
 * This function will prompt the user to enter the play which will be in the
 * format as on the board. If they want to make a play in spot "[1][1]" they
 * will enter "1 1". It will error check it if the user inputed invalid row or
 * column. It will also check if either of the spots have be taken already. The
 * CPU will randomly generate a number for row and column and it will be error
 * checked as well. The user will always have the token X and the computer will
 * have the token O.
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		The following parameters need to have a defined value prior to calling
 * 		the function:
 * 					boardAr[][] : array for the rows and colums of tic tac toe
 * 					token       : token of the player
 * 					playerX     : player with token X
 * 					playerY     : player with token Y
 *
 * POST-CONDITIONS
 * 		This function will assign the token to the display board if it is in
 * 		bound and has not been taken already. It will not return anything it
 * 		will only put the token in the proper space in the display board.
 ******************************************************************************/
void GetAndCheckInpCPU(char boardAr[][NUM_COLS], char token, string playerX,
					   string playerO)
{

		int  row;			//IN & CALC   - row the user wants to play on
		int  col;			//IN & CALC   - column the user wants to play on
		bool valid; 		//CALC & CALC - checks if the user input is valid
		int  computerPlayR; //CALC & CALC - row the computer chooses
		int  computerPlayC; //CALC & CALC - column the computer chooses

		valid = false;

	/**************************************************************************
	 * PROCESSING - This do while loop will error check if the user inputs are
	 * 				valid. If not valid it will display the error on screen
	 *				for the user or else it will assign the token to proper
	 * 				space
	 *************************************************************************/
		do
		{
			computerPlayR = rand() % 3 + 1;
			computerPlayC = rand() % 3 + 1;

			if (token == 'X')
			{
				cout << endl << playerX << "\'s turn! What is your play?: ";
				cin  >> row >> col;

				row--;
				col--;

				if (row > NUM_ROWS - 1 || row < 0)
				{
					cout << "Invalid row - Please try again!\n";
				}
				else if (col > NUM_COLS - 1 || col < 0)
				{
					cout << "Invalid col - Please try again!\n";
				}
				else if (boardAr[row][col] != ' ')
				{
					cout << "That spot is taken already - try again!\n";
				}
				else
				{
					valid = true;
				}
			}
			else
			{
				cout << "\nComputer\'s turn! Computer\'s play? <press enter> ";
				row = computerPlayR;
				col = computerPlayC;

				row--;
				col--;

				if (row > NUM_ROWS - 1 || row < 0)
				{
					cout << "Invalid row - Please try again!\n";
				}
				else if (col > NUM_COLS - 1 || col < 0)
				{
					cout << "Invalid col - Please try again!\n";
				}
				else if (boardAr[row][col] != ' ')
				{
					cout << "That spot is taken already - try again!\n";
				}
				else
				{
					valid = true;
				}
			}

		}
		while(!valid);

		boardAr[row][col] = token;

		cin.ignore(1000,'\n');
}
