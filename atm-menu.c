#include <stdio.h>

int main() {
	
	int options;
	float balance, debitAmount, creditAmount, updatedBalance;
	
	balance = 0.00;
	
	printf("==== ATM MENU ==== \n\n");
	printf("Welcome. What would you like to do today? \n");
	printf("- 1. Check balance \n- 2. Withdraw \n- 3. Deposit \n- 4. Exit \n");
	
	scanf("%d", &options);
	
	switch(options){
		case 1:
			printf("Your balance is %.2f. \n", balance);
			break;
			
		case 2:
			if(balance == 0){
				printf("Fund account first to proceed with this transaction. \n");
				}
			else if(balance > 0 && balance < debitAmount) {
				printf("Insufficient balance. Your account balance is: %.2f. \n", balance);
				}
			else if(balance > 0 && balance > debitAmount) {
				printf("How much would you like to withdraw? \n");
				printf("Enter debit amount: ");
				scanf("%f", &debitAmount);
				printf("\n");
				
				updatedBalance = balance - debitAmount;
				balance = updatedBalance;
				printf("Transaction successful! Your balance is: %.2f \n", balance);
			}
			else {
				printf("Invalid input. Transaction terminated. \n");
				}
			break;
			
		case 3:
			printf("How much would you like to deposit? \n");
			printf("Enter credit amount: ");
			scanf("%f", &creditAmount);
			printf("\n");
			
			if(creditAmount > 0) {
				updatedBalance = balance + creditAmount;
				balance = updatedBalance;
				
				printf("TRANSACTION SUCCESSFUL! Your new balance is: %.2f \n", balance);
				}
			break;
			
		case 4:
			printf("Have a great day!");
			break;
		
		default:
			printf("Invalid input. Program terminated.");
			break;
		}
	
	return 0;
}
