//number gusing game

#include<stdio.h>
int main()
{
	
	int number = 50;
   printf("|----------------------------------------|\n");
   printf("|Let's Start the Number Guuessing Game   |\n");
   printf("|Created by Nilesh Raut                  |\n");
   printf("|----------------------------------------|\n");

	do{
	printf("|====================|\n");
	printf("|Enter Guess A number|\n");
	printf("|====================|\n");
	
	scanf("%d", &number);
	
	if(number==50){
		printf("Correct Guess \n Congratulations you guess correct number.\n Keep it up\n");
		printf("Thank's for playing this game");
	}
	else{printf("Wrong Guess \n Try Again\n");
	}
}while(number!=50);

	
	return 0;
}
