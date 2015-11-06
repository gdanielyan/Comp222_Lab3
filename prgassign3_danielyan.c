/*
 * Georgiy Danielyan
 * Comp 222 - Computer Organization
 * Program for error correction 
 * Hamming Code Method
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/**************************
	Gloable Variables
**************************/
int maxLengthHamCode;
char *hamCode = NULL;
int parity;

char ESC = 27; //Used for bold printing of messages

/**************************
	Function Prototypes
**************************/
void displayMenu();
void enterParameters();
void checkHammingCode();

/**************************
		Main Method
**************************/
int main(){
/* print out menu, prompt for choice, and call appropriate procedure until user quits */
	int choice;
	do{
		choice = 0;
		displayMenu();
		scanf("%d", &choice);
		switch(choice){
		case 1: 
			enterParameters();
			break;
		case 2: 
			checkHammingCode();
			break;
		case 3:
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

/**************************
	Function Definitions
**************************/
void displayMenu(){
	printf("\nGeorgiy Danielyan\n");
	printf("Error detection/correction:\n");
	printf("---------------------------\n");
	printf("1) Enter Parameters\n");
	printf("2) Check Hamming Code\n");
	printf("3) Quit Program\n\n");
	printf("Enter selection: ");
}

void enterParameters(){
	printf("\nEnter the maximum length: ");
	scanf("%d", &maxLengthHamCode);
	printf("\nEnter the parity (0 = even, 1 = odd): ");
	scanf("%d", &parity);
}

void checkHammingCode(){
	// printf("\nEnter the Hamming code: ");
	// scanf("%s", hamCode);

	// printf("%c[1m",ESC);  /*- turn on bold */

	// if(strlen(hamCode) > maxLengthHamCode){
	// 	printf("*** Invalid Entry - Exceeds Maximum Code Length of 12\n\n");
	// }
	// else{

	// }

	// printf("%c[0m",ESC); /* turn off bold */
}