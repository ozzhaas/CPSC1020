/* Kellen Haas
CPSC 1020
Sec. 002
10/07/19
mkhaas@clemson.edu
Dr. Feaster
*/

#include "functions.h"


void readData(FILE* fp, matrixInfo_t* matrix) {	
//	fp = fopen("data.txt", "r");

	fscanf(fp, "%d %d", &matrix->rows, &matrix->cols);
	allocateLetters(matrix);
	readLetters(fp, matrix);

	fscanf(fp, "%d", &matrix->numWords);
	allocateWords(matrix);

	readWords(fp, matrix);
	fclose(fp);
}



void printDirections(matrixInfo_t* dirMatrix) {
	
	printf("Considering the above matrix of characters. This matrix has at 12 words in it. Your job is to find as many of these as possible. The letter for each word must touch. In other words, the letters should be side-by-side or diagonal of each other.\n\n");
	printf("Type each word then press enter. When you are finished type \"quit\"\n");


}


void printMatrix(matrixInfo_t* realMatrix) {
	int num = 0;
	//char buffer;

	
	printf("+");
	for (int j = 0; j < realMatrix->cols; j++){
		printf("-----+");
	}		
	printf("\n");


	for (int i = 0; i < (realMatrix->rows); i++) {
		printf("|");	
			//scanf("%c", &buffer);
		for (int k = 0; k < (realMatrix->cols); k++) {
			printf("  %c  |", realMatrix->letters[num]);
			num++;
		}
		printf("\n");
		printf("+");
		for (int j = 0; j < realMatrix->cols; j++){
			printf("-----+");
		}		
		printf("\n");
	}

}


int readUserInput(matrixInfo_t* word_matrix) {
	char* string = (char*)malloc(word_matrix->rows * word_matrix->cols * sizeof(char));

	scanf("%s", string);	

	
	while ((strcmp(string, "quit") != 0) && (strcmp(string, "Quit") != 0)) {
		if (checkWords(string, word_matrix) == 0) {
			if ((checkFoundWords(string, word_matrix) == 0) || (word_matrix->numFound == 0)) {
				strcpy(word_matrix->foundWords[word_matrix->numFound], string);
				word_matrix->numFound++;
				printf("\nYay! You found a new word!\nKeep guessing until you think you've found them all!\n");
			}
			else {
				printf("\nYou already guessed that word!\n");
			}
		}
		else {
			printf("\nThat word is not a correct option.\n");
		}

		printf("\n");
		printMatrix(word_matrix);
		scanf("%s", string);
	}
return (0);
}


int checkWords(char* ch, matrixInfo_t* word_check) {

	for (int i = 0; i < word_check->numWords; i++){
		if (strcmp(ch, word_check->words[i]) == 0){
			return 0;
		}
	}

	return -1;
}

int checkFoundWords(char* character, matrixInfo_t* check) {


	for (int i = 0; i < check->numWords; i++) {
		if (strcmp (character, check->foundWords[i]) == 0) {
			return -1;
		}
	}


	return 0;
}





void allocateLetters(matrixInfo_t* allo_letters) {
	
	allo_letters->letters = (char*)malloc(allo_letters->rows * allo_letters->cols * sizeof(char));
	allo_letters->numFound = 0;

}


void allocateWords(matrixInfo_t* allo_words) {
	
	allo_words->words = (char**)malloc(allo_words->numWords * sizeof(char*));
	for (int i = 0; i < allo_words->numWords; i++) {
		allo_words->words[i] = (char*)malloc(allo_words->rows * allo_words->cols * sizeof(char));
	}
	
	allo_words->foundWords = (char**)malloc(allo_words->numWords * sizeof(char*));
	for (int j = 0; j < allo_words->numWords; j++) {
		allo_words->foundWords[j] = (char*)malloc(allo_words->rows * allo_words->cols * sizeof(char));
	}

}


void readLetters(FILE* fp, matrixInfo_t* readLetMatrix) {

	char* buffer = (char*)malloc(sizeof(char));

		fscanf(fp, "%c", buffer);
	for (int i = 0; i < (readLetMatrix->rows * readLetMatrix->cols); i++){
		fscanf(fp, "%c ", &readLetMatrix->letters[i]);


	}

}



void readWords(FILE* fp, matrixInfo_t* readWordMatrix) {


	for (int i = 0; i < readWordMatrix->numWords; i++) {
		fscanf(fp, "%s", readWordMatrix->words[i]);

	}
	
}


void checkArguments(int args) {
	if (args != 2) {
		printf("Error: Incorrect number of command line arguments\n");
	}

}


void free1DMemory(matrixInfo_t* free1DMatrix) {
	free(free1DMatrix->letters);


}



void free2DMemory(matrixInfo_t* free2DMatrix) {

	for (int i = 0; i < free2DMatrix->numWords; i++){
		free(free2DMatrix->words[i]);
	}
	free(free2DMatrix->words);
}





