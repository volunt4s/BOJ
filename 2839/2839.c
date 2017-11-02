#include <stdio.h>
#include <stdbool.h>

bool isOverValue (int x, int y, int input);
int chkSolution (int x, int y, int input);

int main(){
	
	int x, y; // 3x + 5y = n
	
	int input; // for input value
	
	int solutionSet[1000] = {0,}, minValue, i=0, j; // identifier i, j

	scanf("%d", &input);

	for (x=0; x<=1333; x++){
		
		for(y=0; y<=1000; y++){
			
			if (chkSolution(x, y, input) != -1){
				solutionSet[i] = x+y;
				i++;
	
			}else if (isOverValue(x, y, input)){
				y = 0;
				break;
			}	
		}
		if (isOverValue(x,y,input)) break;
	}

	if(solutionSet[0] != 0){
		minValue = solutionSet[0];
		for(j=1; j<i; j++){
			if(minValue > solutionSet[j] && solutionSet[j] != 0) minValue = solutionSet[j];	
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
		return true;
	}
	return false;
}

int chkSolution(int x, int y, int input){

	if (((3*x) + (5*y)) == input){
		return x+y;
	}
	
	return -1;
}
