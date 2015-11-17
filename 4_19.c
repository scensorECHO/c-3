#include <stdio.h>

void prInst();
void prProd();
void prQuan();
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
	int inv [5];

	prInst();
	prProd();
	scanf("%d",&userinput);
	for(c=0; c<7;c++){
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
					break;
				default:


			}
		}
	}	
}

void prInst(){
	printf("Welcome to the Advanced Inventory Daily Supervisor:");
	printf("Instructions:\n");
	printf("Enter the product number as requested, -1 to move to the next day, or -2 to quit\n\n");
}

void prProd(){
	printf("Enter the product number\n");
}

void prQuan(){
	printf("Enter the quantity\n");
}

void prErro(int error){
	switch(error){
		case 0:
			printf("");
			break;
		default:
			printf("Error encountered");
			break;
	}
}

