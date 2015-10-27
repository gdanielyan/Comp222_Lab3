#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* declare global vars */
/* define hamming string as a dynamic array of characters */ 

/***************************************************************/
void PROCEDURE TO SET PARAMETERS FOR HAMMING CODE()
{
/* prompt for maximum hamming code length and for even/odd parity */
/* allocate memory for hamming string based on maximum length and size of a character element*/
  return;
}

/***************************************************************/
void PROCEDURE TO CHECK A HAMMING CODE FOR AN ERROR()
{
/* declare local vars */
/* prompt for hamming code as a "string"*/
/* OUTER LOOP: for each parity bit in the Hamming code*/
{ /* BEGIN OF OUTER LOOP */
	/* initialize appropriate local variables */
   	/* MIDDLE LOOP: for each starting bit of a sequence */
        	/* INNER LOOP: for each bit to be checked, check value and update parity information for current parity bit*/
	/* update parity checking by including result for parity bit checked in total */
} /* END OF OUTER LOOP

/* report error in hamming code based on result from parity bits or report no error if none */
/* correct hamming code by flipping error bit (if necessary)*/
  return;
}

/***************************************************************/

void displayMenu(){
	printf("1) Enter Parameters\n");
	printf("2) Check Hamming Code\n");
	printf("4) Quit Program\n");
}

int main(){
/* print out menu, prompt for choice, and call appropriate procedure until user quits */
	int choice;
	do{
		choice = 0;
		displayMenu();
		scanf("%d", &choice);
		switch(choice){
			case 1: 
				break;
			case 2: 
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Invalid selection\n\n");
				//Clear the input stream in case of error inputs
				while ((choice = getchar()) != '\n' && choice != EOF);
				break;	
		}
	}while(choice != 4);
	return 0;
}
