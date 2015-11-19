#include <stdio.h>

// Calculating weekly pay

int respHrs(int h);
int main(){

	int paycode;
	int payroll [] = {0,0,0,0};
	int c = 0; // counter for list
	int f = 0; // counter for fields in list
	
	char*** employees;
	// 3d array contains strings, list of info, and list of lists

	printf("Please enter the employee pay code: ");
	scanf("%c", &paycode);

	/* I'm setting up my program to hold a 2D array of strings
	 * (char[][][] or char***) in order to hold given values for
	 * each inputted employee. 
	 * manager:   	{type, name, salary}
	 * hourly:    	{type, name, hours, wage, total}
	 * commission:	{type, name, sales, total}
	 * pieceworker:	{type, name, produced, price, total}
	 */

	while(paycode!=-1){
		f=0; // reset field counter
		switch(paycode){
			case 1: // manager
				employees[c][f++]=paycode;
				printf("Enter your full name: ");
				scanf("%s", &employees[c][f++]);
				printf("How much is your weekly salary? (X.XX): ");
				scanf("%s", &employees[c][f]);
				
			case 2: // hourly
				employees[c][f++]=paycode;
				printf("Enter your full name: ");
				scanf("%s", &employees[c][f++]);
				printf("Enter the number of hours you worked (integer): ");
				scanf("%s", &employees[c][f++]);
				printf("Enter your hourly wage: (X.XX)");
				scanf("%s", &employees[c][f++]);

			case 3: // commission
				employees[c][f++]=paycode;
				printf("Enter your full name: ");
				scanf("%s", &employees[c][f++]);
				printf("Enter your total sales: ");
				scanf("%s", &employees[c][f++]);


			case 4: // pieceworker
				employees[c][f++]=paycode;
				printf("Enter your full name: ");
				scanf("%s", &employees[c][f++]);
				
		}
	}
} 

// calculates the total hours in terms of their paycheck
// overtime hours are recalculated and adjusted to 
// "time and a half" here
int respHrs(int h){
	if(h>40){
		return (((h-40)*1.5)+40);
	} else {
		return h;
	}
}
