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

	mainMatrix = (matrixInfo_t*)malloc(sizeof(matrixInfo_t));

	checkArguments(argc);

	FILE* fileptr = fopen(argv[1], "r");
	readData(fileptr, mainMatrix);
	printMatrix(mainMatrix);
	printDirections(mainMatrix);

	//Start a timer
	readUserInput(mainMatrix);
	//End timer
	//Print the number of correct unique words
	printf("The amount of time it took you to find %d words was: \n", mainMatrix->numFound);

	free1DMemory(mainMatrix);
	free2DMemory(mainMatrix);
	





return 0;

}
