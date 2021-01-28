/******************************************************************************
 *	PROGRAMMED BY : Utsav Parajuli
 *	ASSIGNMENT #2 : Multi-Dimensional Array - Tic Tac Toe
 *	CLASS         : CS1B
 *	SECTION       : MW: 7:30pm - 9:50pm
 *	DUE DATE	  : 03/11/2020
 ******************************************************************************/


#ifndef AS2_H_
#define AS2_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
using namespace std;

/*****************************************************************************
 * GLOBAL CONSTANTS
 * ---------------------------------------------------------------------------
 * NUM_ROWS : Number of rows for the tic tac toe board
 * NUM_COLS : Number of columns for the tic tac toe board
 ****************************************************************************/

const int NUM_ROWS = 3;
const int NUM_COLS = 3;

/*******************************************************************************
 * FUNCTION PrintHeaderOstream - This function receives an assignment name, type
 * 								 and number that outputs the appropriate class
 * 								 heading. asType is defaulted to lab as there
 * 								 are more labs than than Assignments.
 * 						  		 ==> returns nothing - This will output the
 * 						  							  class header
 ******************************************************************************/
void PrintHeaderOstream(ostream &fout,         // IN/OUT - output file
					    string   asName,       // IN     - assignment Name
				 	    int      asNum,        // IN     - assignment number
					    char     asType);       // IN     - assignment type
									           //          ('L' = Lab,
									           //           'A' = Assignment)


/******************************************************************************
* FUNCTION OutputInstruct -
*    This function outputs instructions to the users. There are no input
*	 or output parameters for this function as it only displays text to
*	 the screen.
*
* 	RETURNS: nothing
* 	-> Displays the instructions to the user
*****************************************************************************/
void OutputInstruct();


/******************************************************************************
* FUNCTION InitBoard -
* 	This function initializes each spot in the board to a space ' '.
*
* 	RETURNS: Board initialized with all spaces
*****************************************************************************/
void InitBoard(char boardAr[][NUM_COLS]); // OUT - tic tac toe board


/******************************************************************************
* FUNCTION DisplayBoard -
* 	This function outputs the tic tac toe board including the tokens
* 	played in the proper format (as described below).
*
* 		1 		2 		3
* 	[1][1] | [1][2] | [1][3]
* 		   |        |
* 	1      |        |
* 	       |        |
* 	--------------------------
* 	[2][1] | [2][2] | [2][3]
* 	       |        |
* 	2      |        |
* 	       |        |
* 	--------------------------
* 	[3][1] | [3][2] | [3][3]
* 	       |        |
* 	3      |        |
* 		   |        |
*
* 	RETURNS: nothing
* 	-> outputs the current state of the board

*****************************************************************************/
void DisplayBoard(const char boardAr[][NUM_COLS]); // IN - tic tac toe board


/******************************************************************************
* FUNCTION GetPlayers -
*  This function prompts the user and gets the input for the players’ names.
*  playerX will always contain the name of the player that is using the X token.
*  playerO will always contain the name of the player that is using the O token.
*
* 	RETURNS: the players names through the variables playerX and playerO.
*****************************************************************************/
void GetPlayers(string& playerX,  // OUT - player X’s name
				string& playerO); // OUT - player O’x name


/******************************************************************************
 * FUNCTION GetAndCheckInp -
 * 	This function prompts the user and gets the play the player wants to choose
 * 	if they want to make a play in the [1][1] box they will enter "1 1". It
 * 	also error checks the user's inputs to see if they entered wrong rows and
 * 	columns and checks if that spot is already taken as well.
 *
 * 	RETURNS: the play the user wants to make
 *****************************************************************************/
void GetAndCheckInp(char boardAr[][NUM_COLS], //IN - the array of the board
					char token, 			  //IN - token of the player
					string playerX,			  //IN - name of playerX
					string playerO);		  //IN - name of playerO


/******************************************************************************
* FUNCTION SwitchToken -
* 	This function switches the active player.
* 	It takes in a parameter representing the current player's token
* 	as a character value (either an X or an O) and returns the opposite.
* 	For example, if this function receives an X it returns an 0. If it
* 	receives and O it returns and X.
*
*	RETURNS: the token opposite of the one in which it receives.
*****************************************************************************/
char SwitchToken(char token); // IN - current player’s token ('X' or 'O')


/******************************************************************************
* FUNCTION CheckWin -
* 	This function checks to see if either player has run. Once it is
* 	possible for a win condition to exist, this should run after each a
* 	player makes a play.
*
*	RETURNS:
*   the character value of the player that won or a value that
* 	indicates a tie.
*****************************************************************************/
char CheckWin(const char boardAr[][NUM_COLS]); // IN - tic tac toe board


/******************************************************************************
* FUNCTION OutputWinner -
* 	This function receives as input a character indicating which player won
* 	or if the game was a tie and outputs an appropriate message. This function
* 	does not return anything as it simply outputs the appropriate message to
* 	the screen.
*
*	 RETURNS: nothing
* 	 ==> Displays the winner’s name
*****************************************************************************/
void OutputWinner(char whoWon, 	  	// IN - represents the winner or a value
									// indicating a tied game.
				  string playerX,   // OUT - player X’s name
				  string playerO);  // OUT - player O’x name

/******************************************************************************
* FUNCTION GetAndCheckComputerPlay -
* 	This function will prompt the user to enter row and column for their play as
* 	"1 1" and it will error check it if it is within the bounds and it's not
* 	taken. It will generate a random row and column for itself
*
*	RETURNS: the play of user and CPU is sent back to the calling function
*			 after it error checks it
*****************************************************************************/
void GetAndCheckInpCPU(char boardAr[][NUM_COLS], //IN - the array of the board
					   char token, 			     //IN - token of the player
					   string playerX,			 //IN - name of playerX
					   string playerO);		     //IN - name of playerO


#endif /* AS2_H_ */
