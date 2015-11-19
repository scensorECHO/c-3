#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculating weekly pay

// functions
int respHrs(int h);
void promptCode();

// globals
const char* codestr = "Please enter the employee pay code (-1 to end employee input): ";

int main(){

	int paycode;
	int payroll [] = {0,0,0,0};
	int c = 0; // counter for list
	int f = 0; // counter for fields in list
	int len = 10; // size of array - starts at 10

	// standard strings
	const char* fname = "Enter employee last name: ";
	const char* totalPaycheck = "%s's total paycheck is $%s\n\n";
	
	const size_t BUFFER = 18; // buffer for parsing float/int
	const size_t BUF_CODE = 1; // buffer for paycode - always 1

	// parse values for arithmetic in switch
	int hours;
	float wage;
	float sales;
	float total;
	int quantity;
	float price;
	
	// 3d array contains strings > list of info > list of lists
	char emp[len][5][24];// = (char*) malloc(5*len*sizeof(char)*24);
	memset( emp, 0, 5*len*sizeof(char)*24);

	promptCode();
	scanf("%d", &paycode);

	/* I'm setting up my program to hold a 2D array of strings
	 * (char[][][]) in order to hold given values for each 
	 * inputted employee. 
	 * Following data structure schema: 
	 * manager:   	{type, name, salary}
	 * hourly:    	{type, name, hours, wage, total}
	 * commission:	{type, name, sales, total}
	 * pieceworker:	{type, name, produced, price, total}
	 */

	while(paycode!=-1){
		f=0; // reset field counter
		
		// Test if array limit reached and increase size by 10
		if(len<=(c+1)){
			len+=10;
			//emp = realloc(emp, 5*len*sizeof(char)*24);
			char tempE[len][5][24];// = malloc(emp,5*len*sizeof(char)*24);
			memset(tempE,0,5*len*sizeof(char)*24);
			for(int x=0; x<c; x++){
				for(int r=0; r<5; r++){
					for(int s=0; s<strlen(emp[r][x]); s++){
						tempE[r][x][s]=emp[r][x][s];
					}
				}
			}
			memset(emp,0,5*len*sizeof(char)*24);
			//emp = tempE;
			for(int x=0; x<c; x++){
				for(int r=0; r<5; r++){
					for(int s=0; s<strlen(emp[r][x]); s++){
						emp[r][x][s]=tempE[r][x][s];
					}
				}
			}
		}

		// Check user input and respond
		switch(paycode){
			case 1: // manager
				// Set employees pay code
				snprintf(emp[c][f++],BUF_CODE,"%d",paycode);
				
				// Prompt for user First name
				printf(fname);
				scanf("%s", &emp[c][f++]);

				// Manager specific: Get weekly salary
				printf("How much is their weekly salary? (X.XX): ");
				scanf("%s", &emp[c][f]);

				// Display paycheck to user
				printf(totalPaycheck,emp[c][1],emp[c][2]);
				c++;
				break;
			case 2: // hourly
				// Set employees pay code
				snprintf(emp[c][f++],BUF_CODE,"%d",paycode);
				
				// Prompt for user First name
				printf(fname);
				scanf("%s", &emp[c][f++]);

				// Get hours worked 
				printf("Enter the number of hours worked (integer): ");
				scanf("%d", hours);
				snprintf(emp[c][f++],BUFFER,"%d",hours);
				
				// Get hourly wage
				printf("Enter hourly wage (X.XX):");
				scanf("%f", &wage);
				snprintf(emp[c][f++],BUFFER,"%.2f",wage);
			
				// Calculate total and display to user
				snprintf(emp[c][f],BUFFER,"%.2f",wage*respHrs(hours));
				printf(totalPaycheck,emp[c][1],emp[c][4]);
				c++;
				break;
			case 3: // commission
				// Set employees pay code
				snprintf(emp[c][f++],BUF_CODE,"%d",paycode);
				
				// Prompt for user First name
				printf(fname);
				scanf("%s", &emp[c][f++]);

				// Get total sales 
				printf("Enter total sales (X.XX):");
				scanf("%f", &sales);
				snprintf(emp[c][f++],BUFFER,"%.2f",sales);
				
				// Calculate total and display to user
				snprintf(emp[c][f],BUFFER,"%.2f",sales+250.00);
				printf(totalPaycheck,emp[c][1],emp[c][3]);
				c++;
				break;
			case 4: // pieceworker
				// Set employees pay code
				snprintf(emp[c][f++],BUF_CODE,"%d",paycode);
				
				// Prompt for user First name
				printf(fname);
				scanf("%s", &emp[c][f++]);

				// Pieceworker: Get items sold
				printf("Enter number of items sold (integer): ");
				scanf("%d",&quantity);
				snprintf(emp[c][f++],BUFFER,"%d",quantity);

				// Pieceworker: Get items selling price
				printf("Enter the price of the item (X.XX): ");
				scanf("%f",&price);
				snprintf(emp[c][f++],BUFFER,"%.2f",price);

				// Calculate total and display to user
				snprintf(emp[c][f],BUFFER,"%.2f",quantity*price);
				printf(totalPaycheck,emp[c][1],emp[c][4]);
				c++;
				break;
			case 5:
				printf("Successfully parsed paycode as %d\n",paycode);
				break;
			default:
				printf("Value \"%s\"does not relate to any action\n",paycode);
				break;
		}
		promptCode();
		scanf("%d", &paycode);
	}
} 

// calculates the total hours in terms of their paycheck
// overtime hours are recalculated and adjusted to 
// "time and a half" here
int respHrs(int h){
	if(h>40){
		return (int)(((h-40)*1.5)+40);
	} else {
		return h;
	}
}

void promptCode(){
	printf(codestr);
}
