#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculating weekly pay

// globals
const char* codestr = "Please enter the employee pay code (-1 to end employee input): ";
const char* fname = "Enter employee last name: ";	
const char* totalPaycheck = "%s's total paycheck is $%.2f\n\n";
int c = 0; // counter for array
int len = 0; // length of array
typedef struct {
	int paycode;
	char* name;
	float total;
} Employee;
Employee *payroll;


// functions
int respHrs(int h);
void promptCode();
int addToArray (Employee item);
int main(){

	int paycode;
	
	// const size_t BUFFER = 18; // buffer for parsing float/int
	// const size_t BUF_CODE = 1; // buffer for paycode - always 1

	// parse values for arithmetic in switch
	int hours;
	float wage;
	float sales;
	float total;
	int quantity;
	float price;
	
	promptCode();
	scanf("%d", &paycode);

	while(paycode!=-1){
		// Check user input and respond
		switch(paycode){
			Employee emp;
			case 1: // manager
				// Set employees pay code
				emp.paycode=paycode;
				
				// Prompt for user First name
				printf(fname);
				scanf("%s", &emp.name);

				// Manager specific: Get weekly salary
				printf("How much is their weekly salary? (X.XX): ");
				scanf("%f", &emp.total);

				// Display paycheck to user
				printf(totalPaycheck,&emp.name,emp.total);

				// Add Employee to array
				c=addToArray(emp);
				break;
			case 2: // hourly
				// Set employees pay code
				emp.paycode=paycode;
				
				// Prompt for user First name
				printf(fname);
				scanf("%s", &emp.name);

				// Get hours worked 
				printf("Enter the number of hours worked (integer): ");
				scanf("%d", &hours);
				
				// Get hourly wage
				printf("Enter hourly wage (X.XX):");
				scanf("%f", &wage);
			
				// Calculate total and display to user
				emp.total=wage*respHrs(hours);
				printf(totalPaycheck,&emp.name,emp.total);

				// Add Employee to array
				c=addToArray(emp);
				break;
			case 3: // commission
				// Set employees pay code
				emp.paycode=paycode;
				
				// Prompt for user First name
				printf(fname);
				scanf("%s", &emp.name);

				// Get total sales 
				printf("Enter total sales (X.XX):");
				scanf("%f", &sales);
				
				// Calculate total and display to user
				emp.total=sales+250.00;
				printf(totalPaycheck,&emp.name,emp.total);

				// Add Employee to array
				c=addToArray(emp);
				break;
			case 4: // pieceworker
				// Set employees pay code
				emp.paycode=paycode;
				
				// Prompt for user First name
				printf(fname);
				scanf("%s", &emp.name);

				// Pieceworker: Get items sold
				printf("Enter number of items sold (integer): ");
				scanf("%d",&quantity);

				// Pieceworker: Get items selling price
				printf("Enter the price of the item (X.XX): ");
				scanf("%f",&price);

				// Calculate total and display to user
				emp.total=quantity*price;
				printf(totalPaycheck,&emp.name,emp.total);

				// Add Employee to array
				c=addToArray(emp);
				break;
			case 5: // test case
				printf("Successfully parsed paycode as %d\n",paycode);
				break;
			default:
				printf("Value \"%d\" does not relate to any action\n",paycode);
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

int addToArray (Employee item){
	if(c == len)
	{ 
		if (len == 0)
			len = 3; // Start off with 3 refs
		else
			len *= 2; // Double the number 

		void *tmp = realloc(payroll, (len * sizeof(Employee)));
		if (!tmp)
		{
			fprintf(stderr, "ERROR: Couldn't realloc memory!\n");
			return(-1);
		}

		// Things are looking good so far
		payroll = (Employee*)tmp;
	}

	payroll[c] = item;
	c++;

	return c;
}
