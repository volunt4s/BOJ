#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){

	char inputStr[10000];
	char *ptr, *tmpStr;
	int wordCnt = 0, i,j, tmp, strlength;
	bool isSame = false; // Same Flag

	gets(inputStr);

	// 임의의 공백을 갖지 않기 위한 배열 크기 선정 --> Space 기준 단어 갯수
	strlength = (int)strlen(inputStr);
	for(i=0; i<strlength; i++){
			if(inputStr[i] == ' '){
				wordCnt++;
			}
	}
	wordCnt++;

	char **wordSet = calloc(wordCnt, sizeof(char*));
	int *wordSetCnt = calloc(wordCnt, sizeof(int));

	ptr = strtok (inputStr, " "); // Space 기준 문자열 cut

	wordSet[0] = ptr;
	i = 1;

	while (ptr != NULL) {

		for(j=0; j<i; j++){
				if (strcmp(wordSet[j], ptr) == 0){
					isSame = true;
					wordSetCnt[j]++;
				}
		}

		if(isSame){
			isSame = false;
		}else{
			wordSet[i] = ptr;
			wordSetCnt[i]++;
			i++;
		}

		ptr = strtok(NULL, " ");
	}

	// Bubble Sort
	for(i=0; i<wordCnt; i++){
			for (j=0; j<wordCnt-1; j++){
				if(wordSetCnt[j+1] != 0){
					if(wordSetCnt[j] < wordSetCnt[j+1]){
						tmp = wordSetCnt[j];
						tmpStr = wordSet[j];

						wordSetCnt[j] = wordSetCnt[j+1];
						wordSet[j] = wordSet[j+1];

						wordSetCnt[j+1] = tmp;
						wordSet[j+1] = tmpStr;
					}
				}
			}
	}

	for (i=0; i<wordCnt; i++){
			if(wordSet[i] != NULL)
			printf("%s\n", wordSet[i]);
	}

	// Memory free
	free(wordSet);
	free(wordSetCnt);

	return 0;

}
