// calculator project by Nilesh Raut

#include<stdio.h>
	char operator;
	double num1, num2;
	int main()
	{
	
	printf("===================================\n Welcome to Calculator Program\n Created by Nilesh Raut\n ===================================\n");
	
	printf("Enter an operator (+, -, *, /): ");
	scanf("%c", &operator);
	
	printf("Enter two numbers : ");
	scanf("%lf %lf", &num1, &num2);
	switch(operator){
		case '+' : 
			printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
			break;
			
			
		case '-' : 
			printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
			break;
			
		case '*' : 
			printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
			break;
			
			
		case '/' : 
			if(num2!=0.0){
			printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
		}
			else{
			printf("Error! Division by zero is not allowed. \n");
		}
			break;
			
		default: 
		printf("Error! Operator is not correct.\n Please Enter a valid Operator.\n");
	}
		
		return 0;	
			
	}
	
