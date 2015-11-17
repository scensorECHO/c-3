//a
for(x=100;x>=1;++x){
	printf( "%d\n", x);
}

//b
switch ( value % 2 ) {
	case 0:
		puts( "Even integer");
		break;
	case 1:
		puts( "Odd integer");
		break;
}

//c
scanf("%d %c", &intVal, &charVal); // to accomodate for "100 A"
printf("Integer: %d\nCharacter: %c\n", intVal, charVal);

//d
for ( x=0.000001; x<=0.0001; x+=0.000001){
	printf("%f\n",x);
}

//e
for(x=999;x>=1;x-=2){
	printf("%d\n",x);
}

//f 
unsigned int counter = 2;
do{
	if( counter%2 == 0 ){
		printf( "%u\n",counter);
	}
} while( counter < 100);

//g
for( x=100; x<=150; ++x){
	total+=x;
}