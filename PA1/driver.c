/* Kellen Haas
CPSC 1020
Sec. 002
10/07/19
mkhaas@clemson.edu
Dr. Feaster
*/

#include "functions.h"


int main (int argc, char* argv[]) {
	matrixInfo_t* mainMatrix;
	int seconds = 0;
	int minutes = 0;


	mainMatrix = (matrixInfo_t*)malloc(sizeof(matrixInfo_t));

	checkArguments(argc);

	FILE* fileptr = fopen(argv[1], "r");
	readData(fileptr, mainMatrix);

	printMatrix(mainMatrix);
	printDirections(mainMatrix);

	//Start timer
	time_t start = time(NULL);
	readUserInput(mainMatrix);
	//End timer
	time_t end = time(NULL);
	seconds = end - start;

	minutes = seconds / 60;
	seconds = seconds % 60;
	//Print the number of correct unique words
	printf("The amount of time it took you to find %d words was: %d minutes and %d seconds. \n", mainMatrix->numFound, minutes, seconds);
	printf("Do you want to play again??\n Enter y for yes or n for no.\n");

		free1DMemory(mainMatrix);
		free2DMemory(mainMatrix);
	


return 0;

}
