#include <stdio.h>
#include <stdlib.h>
#include "wordmachine.h"

int main(){
	startWord();
	while (!endWord){
		printf("%s\n", currentWord.contents);
		advWord();
	}
	return 0;
}
