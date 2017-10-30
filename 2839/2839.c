#include <stdio.h>
#include <stdbool.h>

bool isOverValue (int x, int y, int input);
int chkSolution (int x, int y, int input);

int main(){
	
	int x, y; // 3x + 5y = n
	
	int input; // for input value
	
	int solutionSet[10] = {0,}, minValue, i=0; // identifier i

	scanf("%d", &input);

	for (x=0; x<=1333; x++){

		if (isOverValue(x, y, input)){
			break;
		}
		for(y=0; y<=1000; y++){
			
			if (chkSolution(x, y, input) != -1){
				solutionSet[i] = chkSolution(x, y, input);
			}else{
				if (isOverValue(x, y, input)) break;
			}
		}
	}
	
	printf("solutionSet[0] is %d\n", solutionSet[0]);

	if(solutionSet[0] != 0){
		minValue = solutionSet[0];
		for(i=1; i<10; i++){
			if(minValue > solutionSet[i] && solutionSet[i] != 0) minValue = solutionSet[i];	
		}
	}else{
		printf("-1\n");
		return 0;
	}
	
	printf("%d\n", minValue);

	return 0;
}

bool isOverValue(int x, int y, int input){
	
	if (((3*x) + (5*y)) > input){
		printf("isOverVale is true, x = %d, y = %d, 3x+5y = %d\n", x, y, (3*x)+(5*y));
		return true;
	}
	return false;
}

int chkSolution(int x, int y, int input){

	if (((3*x) + (5*y)) == input){
		printf("has solved, x = %d, y = %d, x+y = %d \n", x, y, x+y);
		return x+y;
	}
	
	return -1;
}
