/*Generate all RO phone numbers */
#include<stdio.h>

int step[100];

int solution(int k){
	int sum = 0;

	for (int i = 0; i <= k; i++){
		sum ++;
		if (sum <= 8 && step[i] == 8)
			return 1;
	}
	return 0;
}

int valid(int k){

	int sum = 0;
	int contor = 0;

	for (int i = 1; i <= k; i++){
		sum ++;
	}
	for (int i = 1; i <= k; i++){
		if (step[i] == 0){
			contor++;
		}
		if ((sum + step[i] <= 8) && (contor < 3)){
			return 1;
	    }
	}
	return 0;
}

void print(int k){

	printf("07");
	for (int i = 0; i <= k; i++){
		printf("%d", step[i]);
	}
	printf(";");
	printf("\n");

}

void backtrack(int k){

	for (int i = 0; i < 9; i++){
		step[k] = i;
		if (valid(k)){
			if (solution(k)){
				print(k);
			}
			else backtrack(k + 1);
		}
		step[k] = -1;
	}
}

int main(void){

	backtrack(1);

	return 0;
}