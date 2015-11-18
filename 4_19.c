#include <stdio.h>

void prInst();
void prProd();
void prQuan();
void prInve(int* i);
void prErro(int error);
int showTotal(int* i,float* c);

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
	float cost [] = {2.98,4.50,9.98,4.49,6.87};
	
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
				case -2:
					return showTotal(inv,cost); // exited early
				default:
					prErro(1);
			}
			prProd();
			scanf("%d",&userinput);
		}
	}
	return showTotal(inv,cost);	
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

void prInve(int* i){
	unsigned int x;
	for( x=0; x<5; x++){
		printf("Product %d: Quantity %3d\n",x,i[x]);
	}
}

// display total quantity sold for the 5 products
int showTotal(int* i, float* c){
	unsigned int p;
	for( p=0; p<5; p++){
		printf("Product %2d:%3d\tTotal Cost: $%.2f\n",p+1,i[p],i[p]*c[p]);
	}
	return 0;
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