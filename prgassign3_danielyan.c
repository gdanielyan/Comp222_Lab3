/*
 * Georgiy Danielyan
 * Comp 222 - Computer Organization
 * Program for error correction 
 * Hamming Code Error Detection and Correction
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/**************************
	Gloable Variables
**************************/
char *hamCode = NULL;
int maxLengthHamCode;
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
			free(hamCode);
			exit(0);
			break;
		default:
			printf("Invalid selection\n\n");

			//Clear the input stream in case of extraneous inputs.
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
	printf("\nEnter the maximum hamLength: ");
	scanf("%d", &maxLengthHamCode);

	printf("\nEnter the parity (0 = even, 1 = odd): ");
	scanf("%d", &parity);

	hamCode = (char *)malloc(sizeof(char)*maxLengthHamCode);
}

void checkHammingCode(){

	// /*- turn on bold */
	printf("%c[1m",ESC);
	/* Declare local variables */
	int pBit;
	int error = 0;
	int hamLength;

	printf("\nEnter the Hamming code: ");
	scanf( "%s", hamCode );
	hamLength = strlen(hamCode);
	if( hamLength > maxLengthHamCode ){
		printf("\n*** Invalid Entry - Exceeds Maximum Code Length of %d\n\n", maxLengthHamCode);
	}
	else{
		/* Checking Hamming code for errors */
		int a, b, c, count = 0;
		/* Check for each parity bit */
		for( a = 1; a < hamLength; a = a*2){
			pBit = parity;
			for( b = a; b <= hamLength ; b = c + a ){
				for( c = b; count != a && c <= hamLength ; c++ ){
					pBit = pBit^(hamCode[hamLength-c]-'0');
					count++;
				} // c loop
				count = 0;
			} // b loop
			error += (pBit * a);
		} // a loop

		if( error == 0 )
			printf("\n***There is no bit error.\n");
		else{
			printf("\n***There was an error in bit: %d", error);
			hamCode[hamLength-error] = ( hamCode[hamLength-error]  == '0' ? '1' : '0' ); 
			printf("\n***The corrected Hamming code is: %s\n", hamCode); 
		}
	}

	/* turn off bold */
	printf("%c[0m",ESC);
}

