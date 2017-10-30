#include <stdio.h>

int main(){

	int count, i;
	int number = 0;

	scanf("%d", &count);
	getchar();

	char numberSet[count];
	
	// 1, %c 사용X --> 버퍼 초기화 필요X
	//scanf("%s", numberSet);
	
	// 2, %c 사용 --> scanf 한 글자씩 받을 때마다 \n 버퍼 발생 --> getchar()로 남아있는 버퍼 받아 초기화
	int j;
	for(j=0; j<count; j++){
		scanf("%c", &numberSet[j]);
		getchar();
	}

	for(i=0; i<count; i++){
		number += (numberSet[i] - '0');
	}
	
	printf("%d", number);

	return 0;
}
