#include <stdio.h>

int main(){
	// Calculate the average score of all students in a class.

	int num;
	double sum = 0;

	printf("How many students are there?\n");
	scanf("%d", &num);
	printf("What are their scores?\n");

	// We programmers count from zero!
	for (int i = 0; i < num; i++){
		int score;
		scanf("%d", &score);
		sum += score;
	}

	double average = sum / num;
	if (average == 60){
        printf("Good!\n");
    }
	else if (average > 60){
        printf("Excellent!\n");
    }
	else{
        printf("Bad!\n");
    }
		
	printf("Average score is %.2f.\n", average);

	return 0;
}
