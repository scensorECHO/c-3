#include <stdio.h>
#include <stdlib.h>

// Calculating weekly pay

int respHrs(int h);
void promptCode();
int main(){

	int paycode;
	int payroll [] = {0,0,0,0};
	int c = 0; // counter for list
	int f = 0; // counter for fields in list

	// standard strings
	const char* fname = "Enter full name: ";
	const size_t BUFFER = 18; // quadrillion + 3 spaces for decimal

	char*** emp;
	// 3d array contains strings, list of info, and list of lists

	promptCode();
	scanf("%s", &paycode);

	/* I'm setting up my program to hold a 2D array of strings
	 * (char[][][] or char***) in order to hold given values for
	 * each inputted employee. 
	 * Following data structure schema: 
	 * manager:   	{type, name, salary}
	 * hourly:    	{type, name, hours, wage, total}
	 * commission:	{type, name, sales, total}
	 * pieceworker:	{type, name, produced, price, total}
	 */

	while(paycode!='-1'){
		f=0; // reset field counter
		switch(paycode){
			case '1': // manager
				emp[c][f++]=paycode;
				printf(fname);
				scanf("%s", &emp[c][f++]);
				printf("How much is their weekly salary? (X.XX): ");
				scanf("%s", &emp[c][f]);
				printf("%s's total paycheck is %s\n\n",emp[c][1],emp[c][2]);
				c++;
			case '2': // hourly
				int hours;
				float wage;
				emp[c][f++]=paycode;
				printf(fname);
				scanf("%s", &emp[c][f++]);
				printf("Enter the number of hours worked (integer): ");
				scanf("%d", hours);
				snprintf(&emp[c][f++],BUFFER,"%d",hours);
				printf("Enter hourly wage (X.XX):");
				scanf("%f", &wage);
				snprintf(&emp[c][f++],BUFFER,"%.2f",wage)
				//emp[c][f]= atof(emp[c])*respHrs(strtol(emp[c][2]));
				snprintf(emp[c][f],BUFFER,"%.2f",wage*respHrs(hours));
				c++;
			case '3': // commission
				float sales;
				float total;
				emp[c][f++]=paycode;
				printf(fname);
				scanf("%s", &emp[c][f++]);
				printf("Enter total sales (X.XX):");
				scanf("%f", &sales);
				snprintf(emp[c][f++],BUFFER,"%.2f",sales);
				snprintf(emp[c][f],BUFFER,"%.2f",sales+250.00);
				printf("Total amount paid to %s: %s",emp[c][1],emp[c][3]);
				c++;
			case '4': // pieceworker
				int quantity;
				float price;
				emp[c][f++]=paycode;
				printf(fname);
				scanf("%s", &emp[c][f++]);
				printf("Enter number of items sold (integer): ");
				scanf("%d",&quantity);
				snprintf(emp[c][f++],BUFFER,"%d",quantity);
				printf("Enter the price of the item (X.XX): ");
				scanf("%f",&price);
				snprintf(emp[c][f++],BUFFER,"%.2f",price);
				snprintf(emp[c][f],BUFFER,"%.2f",quantity*price);
				printf("Total amount paid to %s: %s",emp[c][1],emp[c][4]);
				c++;

			default:
				printf("Value \"%s\"does not relate to any action\n",paycode);
		}
		promptCode();
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

void promptCode(){
	printf("Please enter the employee pay code (-1 to end employee input): ");
}
