/******************************************************************************
 *	PROGRAMMED BY : Utsav Parajuli
 *	ASSIGNMENT #2 : Multi-Dimensional Array - Tic Tac Toe
 *	CLASS         : CS1B
 *	SECTION       : MW: 7:30pm - 9:50pm
 *	DUE DATE	  : 03/11/2020
 ******************************************************************************/

#include "as2.h"

/******************************************************************************
 * MULTI-DIMENSIONAL ARRAY - TIC TAC TOE
 *-----------------------------------------------------------------------------
 * This program will prompt the user to choose an option to either play a game
 *  of tic tac toe between two users or an user vs the computer. The user will
 *  input rows and columns and the board will be marked with the token they
 *  chose to use.
 *-----------------------------------------------------------------------------
 * INPUT:
 *  This program reads in the inputs:
 *
 *  	option  : Menu option
 *  	playerX : Name of the player with token 'X'
 *  	playerO : Name of the player with token 'O'
 *  	token   : Token the user wants to use
 *
 * OUTPUT:
 *  This program outputs:
 *
 *  	winner  : Token and name of the player that wins the game
 ******************************************************************************/

int main()
{

	/**************************************************************************
	 * CONSTANTS
	 * -----------------------------------------------------------------------
	 *
	 * TOTAL_RUNS: number of plays in the game
	 *************************************************************************/
	const int TOTAL_RUNS = 9;


	char option;						//IN   & CALC - Menu option
	char boardAr[NUM_ROWS][NUM_COLS];	//CALC & CALC - array of the tic tac
										//				toe board
	string playerX;						//IN   & OUT  - Name of the 'X' player
	string playerO;						//IN   & OUT  - Name of the 'Y' player
	char token;							//IN   & CALC - token the user chooses
	int  count;							//CALC & CALC - count for the for loop
	char winner;						//CALC & OUT  - winner of the game
	bool gameOver;						//CALC & CALC - checks if the game
										//				is over or ongoing


	//OUTPUT - Prints the class header into the console
	PrintHeaderOstream(cout, "Multi-Dimensional Array - Tic Tac Toe", 2, 'A');

	//OUTPUT - Outputs instructions for the game
	cout << "************************************************************\n"
		 << "Welcome to Tic Tac Toe! Please read the instructions and"
		 << "\nchoose one of the options from the menu below\n"
		 << "************************************************************";

	cout << "\n\n1. In this program you will be able to play Tic Tac Toe with"
		 << "\n   either another player or the CPU.\n\n";

	cout << "2. To make a move in the board enter your position for play as"
			"\n   \'1 1\' if you want to place your token in that space\n\n";

	cout << "-------------------------------------------------------------\n";

	//Initializations
	gameOver = false;
	option = 'y';
	token  = 'X';

	//To provide a unique value
	srand(time(NULL));

	//Loop that checks if the game is over or if the user wants to exit
	while(!gameOver && option != 'a')
	{
		//Main menu function that is displayed to the console
		OutputInstruct();

		/***********************************************************************
		 * INPUT - The user is prompted the main menu and is able to choose one
		 	       of the options
		 **********************************************************************/
		cout << "Please enter your option: ";
		cin.get(option);
		cin.ignore(1000,'\n');

		//Function that initializes all the spots in the board to a blank space
		InitBoard (boardAr);

		/**********************************************************************
		 * PROCESSING
		 * --------------------------------------------------------------------
		 *
		 * After the user chooses one of the options from the main menu they
		 * will perform tasks according to the user's choice.
		 *
		 * A selection statement will be used to perform the tasks accordingly
		 * - If the user inputs 'a' they will be able to exit the program
		 * - If the user inputs 'b' they will be prompted to enter names of two
		 *   players. The first player will be able to choose what token they
		 *   want to choose and the second player will be assigned the other
		 *   token
		 * - If the user inputs 'c' they will continue the game for 2 player
		 * 	 mode. It will display the game board and the players will be able
		 * 	 to enter what position they would like to play. It will output
		 * 	 the name of the winner of the game and will return to the main menu
		 * 	 if the game is tied
		 * - If the user inputs 'd' they will be able to play with the CPU and
		 * 	 it will act in the same fashion but the computer will generate
		 * 	 random places to insert their play. It will return to the main menu
		 * 	 once the game ends
		 **********************************************************************/
		switch(toupper(option))
		{
		case 'B':
			//Function GetPlayers will get names of the players and assign them
			// to either playerX or playerO depending on what token they chose
			GetPlayers (playerX, playerO);
		break;

		case 'C':
			/******************************************************************
			 * PROCESSING
			 * ----------------------------------------------------------------
			 * The 2 player mode will run 9 times or until either of the player
			 * wins or if the game is tied it will return to the main menu.
			 *****************************************************************/

			cout << "You are now playing TWO PLAYER MODE!\n\n";

			for (count = 0; count < TOTAL_RUNS; count++)
			{
				//Initialization
				winner = 'C';

				//loop that continues to run until all the blank spaces are
				//filled or one of the user wins the game
				while (winner == 'C')
				{
					//Function that displays the board of tic tac toe
					//system("clear"); // clears the screen
					DisplayBoard (boardAr);

					//Function that receives plays of both players and error
					//checks it as well
					GetAndCheckInp (boardAr, token, playerX, playerO);

					//Checks if any of the player has won and returns token of
					//the winner or checks if the game is still continuing or
					//checks if the game is tied
					winner = CheckWin (boardAr);

					/**********************************************************
					 * OUTPUT
					 * --------------------------------------------------------
					 * This program will output the name of the player that wins
					 * and exits the program if there is a winner
					 *
					 * If there is no winner and the game ended in a tie the
					 * program will return to the main menu for the user to play
					 * again.
					 **********************************************************/
					if (winner == 'X' || winner == 'O')
					{
						//Function that outputs the winner to the console
						OutputWinner (winner, playerX, playerO);

						count = 10;

						gameOver = true;

					}
					else if(winner == 'T')
					{
						OutputWinner (winner, playerX, playerO);

						count = 10;
					}
					else
					{
						token = SwitchToken (token);
					}//end of selection

				}//end of while

			}//end of for
		break;

		case 'D':
			cout << "You are now playing VS THE COMPUTER\n\n";

			for (count = 0; count < TOTAL_RUNS; count++)
			{
				//Initialization
				winner = 'C';

				//loop that continues to run until all the blank spaces are
				//filled or one of the user wins the game
				while (winner == 'C')
				{
					//Function that displays the board of tic tac toe
					//system("clear");
					DisplayBoard (boardAr);

					//Function that receives plays of user and error
					//checks it as well as randomly generates a play for CPU
					GetAndCheckInpCPU (boardAr, token, playerX, playerO);

					//Checks if any of the player has won and returns token of
					//the winner or checks if the game is still continuing or
					//checks if the game is tied
					winner = CheckWin (boardAr);

					/**********************************************************
					 * OUTPUT
					 * --------------------------------------------------------
					 * This program will output the name of the player that wins
					 * and exits the program if there is a winner
					 *
					 * If there is no winner and the game ended in a tie the
					 * program will return to the main menu for the user to play
					 * again.
					 **********************************************************/
					if (winner == 'X' || winner == 'O')
					{
						//Function that outputs the winner to the console
						OutputWinner (winner, playerX, playerO);

						count = 10;

						gameOver = true;

					}
					else if(winner == 'T')
					{
						OutputWinner (winner, playerX, playerO);

						count = 10;
					}
					else
					{
						token = SwitchToken (token);
					}//end of selection

				}//end of while

			}//end of for
		break;


		}//end of switch statement

	}//end of the primary while loop

	return 0;

}//end of the program

