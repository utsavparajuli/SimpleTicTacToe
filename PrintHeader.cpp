/******************************************************************************
 *	PROGRAMMED BY : Utsav Parajuli
 *	ASSIGNMENT #2 : Multi-Dimensional Array - Tic Tac Toe
 *	CLASS         : CS1B
 *	SECTION       : MW: 7:30pm - 9:50pm
 *	DUE DATE	  : 03/10/2020
 ******************************************************************************/

#include "as2.h"

/*******************************************************************************
 * FUNCTION PrintHeaderOstream
 *
 * -----------------------------------------------------------------------------
 *  This function receives an assignment name, type and number then outputs
 *  the appropriate header to the output file - returns nothing.
 * -----------------------------------------------------------------------------
 *
 * PRE-CONDITIONS
 * 	The following parameters need to have a defined value prior to calling
 * 	to calling the function:
 * 						   asName : Assignment Name
 * 						   asNum  : Assignment Number
 * 						   asType : Assignment Type ==> THIS SHOULD CONTAIN:
 * 						   								'L' for Labs
 * 						   								'A' for Assignments
 *
 * POST-CONDITIONS
 * 	This function will output the class heading to the output file
 ******************************************************************************/
void PrintHeaderOstream(ostream &fout,         // IN/OUT - output file
					    string   asName,       // IN     - assignment Name
				 	    int      asNum,        // IN     - assignment number
					    char     asType)       // IN     - assignment type
									           //          ('L' = Lab,
									           //           'A' = Assignment)
{
	 fout << left;
	 fout << "*********************************************************\n";
	 fout << "* PROGRAMMED BY : Utsav Parajuli\n";
     fout << "* " << setw(14) << "CLASS"
   	      << ": CS1B - MW 7:30pm - 9:50pm\n";
     fout << "* ";

     //PROCESSING - This will adjust setws and format appropriately
     //             based on if this is a lab 'L' or assignment 'A'
     if(toupper(asType) == 'L')
     {
    	 fout << "LAB #" << setw(9);
     }
     else
     {
    	 fout << "ASSIGNMENT #";
     }
     fout << asNum << " : " << asName << endl;
	 fout << "*********************************************************\n\n";
	 fout << right;
}
