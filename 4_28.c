// Calculating weekly pay

int respHrs(int h);
int main(){

	int paycode;
	int payroll [] = {0,0,0,0};
	int counter = 0;

	printf("Please enter the employee pay code: ");
	scanf("%d", &paycode);

	while(paycode!=-1){
		switch(paycode){
			case 1: // manager
				float salary;
				printf("How much is your weekly salary? (X.XX)");
				scanf("%f", &salary);

			case 2: // hourly
			case 3: // commission
			case 4: // pieceworker
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