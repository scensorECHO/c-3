#include <stdio.h>

void prInst();
void prProd();
void prQuan();
void prInve();
void prErro(int error);
int main(){

	int userinput;
	int quantity;
	unsigned int c;
	char* days[7];
	days[0]="MON";
	days[1]="TUE";
	days[2]="WED";
	days[3]="THU";
	days[4]="FRI";
	days[5]="SAT";
	days[6]="SUN";
	int inv [] = {0,0,0,0,0};

	// Show instructions
	prInst();

	// Loop days of the week
	for(c=0; c<7;c++){
		printf("%s:\n",days[c]);
		prProd();
		scanf("%d",&userinput);
		while(userinput!=-1){
			switch(userinput){
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
					prQuan();
					scanf("%d",&quantity);
					inv[userinput-1]+=quantity;
					// this allows for rollback of inventory 
					//if values entered incorrectly
					break;
				default:
					if(userinput==-2){
						return 1; // exited early
					} else {
						prError(1);
					}
			}
			prProd();
			scanf("%d",&userinput);
		}
	}
	return 0; // success	
}

void prInst(){
	printf("Welcome to the Advanced Inventory Daily Supervisor:");
	printf("Instructions:\n");
	printf("Enter the product number\n-1 to move to the next day\n-2 to quit\n\n");
}

void prProd(){
	printf("Enter the product number ( 1-5 )\n");
}

void prQuan(){
	printf("Enter the quantity\n");
}

void prInve(){
	unsigned int x;
	for( x=0; x<5; x++){
		printf("Product %d: Quantity %3d\n",x,inv[x]);
	}
}

void prErro(int error){
	switch(error){
		case 1:
			printf("The entered value is not valid\n");
			break;
		case 0:
		default:
			printf("Error encountered\n");
			break;
	}
}