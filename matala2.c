#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define cSIZE 4
#define rSIZE 4

int count = 0;

void main(){
   

    char mat [rSIZE][cSIZE] =	{ {'C','A','R','T'} ,
    							{'E','T','A','K'} ,
    							{'E','S','M','E'} ,
    							{'L','L','P','N'} };
    
    findWord(mat);
    printf("\nNumber of words is = %d\n", count);
   
}

bool isWord(char* s){

		return (!strcmp(s,"CAT") |
			!strcmp(s,"CATS") |
			!strcmp(s,"TRAM") |
			!strcmp(s,"TRAMS") |
			!strcmp(s,"TAME") |
			!strcmp(s,"CAR") |
			!strcmp(s,"CARS") |
			!strcmp(s,"RAT") |
			!strcmp(s,"TRACE") |
			!strcmp(s,"RATS") |
			!strcmp(s,"RAMP") |
			!strcmp(s,"ART") |
			!strcmp(s,"CART") |
			!strcmp(s,"STAMP") |
			!strcmp(s,"TAKEN") |
			!strcmp(s,"MEN") |
			!strcmp(s,"MAKE") |
			!strcmp(s,"TAKE") |
			!strcmp(s,"ATE") |
			!strcmp(s,"SELL") |
			!strcmp(s,"STEEL") |
			!strcmp(s,"ME")|
			!strcmp(s,"RAKE") );

}

void findWord(char mat [rSIZE][cSIZE]){
	
	int i;
	int j;
	int temp [rSIZE][cSIZE] = {{0}};
	char words [16] = "" ;
	for(i = 0; i < rSIZE; i++){
		for(j = 0; j < cSIZE; j++){
			vaildWord(mat, temp ,i ,j ,words);
		}
	}
}

void vaildWord(char mat [rSIZE][cSIZE], int temp [rSIZE][cSIZE], int i, int j, char *words ){
	temp[i][j] = 1;
	int wLength = strlen(words);
	words[wLength] = mat[i][j];
	
	if (isWord(words)){
		printf("\n%s ",words);
		count++;
		
	}
	
	if ((i-1) >= 0 && !temp[i-1][j]){
		vaildWord(mat, temp, (i-1), j, words);
	}
	
	if ((i+1) < cSIZE && !temp[i+1][j]){
		vaildWord(mat, temp, (i+1),j , words);
	}
		
	if ((j-1) >= 0 && !temp[i][j-1]){
		vaildWord(mat, temp, i, (j-1) , words);
	}
	
	if ((j+1) < rSIZE && !temp[i][j+1]){
		vaildWord(mat, temp, i, (j+1), words);
	}
	
	words[wLength] = '\0';
	temp[i][j] = 0;
	
}




