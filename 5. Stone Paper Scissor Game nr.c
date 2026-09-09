//Stone Paper Scissor Game Created by Nilesh Raut
#include<stdio.h>
int main()
{
	int player_choice , computer_choice;
	char play_again;
	int step = 0;
	printf("Welcome to Game Created by Nilesh Raut");
	do{
		printf("\n_____________________________");
		printf("\nStone Paper Scissor Game\n");
		printf("-----------------------------\n"); 
		printf("1. Stone\n""2. Paper\n""3. Scissor\n");
		
		printf("Enter your Choice 1/2/3 \n");
		scanf("%d", &player_choice);
		
		step++;
		computer_choice = (step % 3) +1;
		
		printf("Your Choice : %d\n", player_choice);
		printf("Computer Choice : %d\n", computer_choice);
		
		
		if(player_choice == computer_choice){
			printf("Result : It's a Draw\n");
		}
		else if((player_choice == 1 && computer_choice == 3) || 
		         (player_choice == 2 && computer_choice == 1) || 
		         (player_choice == 3 && computer_choice == 2)) {
			printf("Result : You Win \n");
		}
		else {
			printf("Result : Computer Win \n");
		}
		
		printf("\nplay again (y/n)");
		scanf(" %c", &play_again); 
			
	} while(play_again =='y'|| play_again == 'Y');
			
	return 0;
}
