#include<stdio.h>

/*This is the function which goes through the lower and upper bound and determines the prime numbers in the range*/

int prime (int b) {
int i;

for (i=2; i<b; i++){
	if (b%i==0) {
		return 0;
	}
}
return 1;
}

/*This was an alternate function to determine prime numbers*/
/*
	int prime ()int b){
	int i;
		int counter1 = 0;
		for(i=2;i<b;i++){
			if (b%i==0){
				couter1++;
				}

			}
		if (counter1>0){
			return 0;
			}
		else{
			return 1;
			}

	}
*/





int main () {

int low, high, count;
count=0;

	//low= 60;
	//high=300;

/*This part of the program accepts inputs and outputs any error messages if need be*/

printf("Enter lower limit:\n\n");
scanf("%d", &low);
printf("Enter upper limit:\n");
scanf("%d", &high);
low++;

	if (low>=high) {
		printf("Error! Lower limit greater than or equal to the Upper limit.\n");
		printf("Enter lower limit:\n\n");
		scanf("%d", &low);
		printf("Enter upper limit:\n");
		scanf("%d", &high);
		low++;
		return 0;
	}

	if(low<=0 || high<=0) {
		printf("Error! Please input positive integers.\n");
		printf("Enter lower limit:\n\n");
		scanf("%d", &low);
		printf("Enter upper limit:\n");
		scanf("%d", &high);
		low++;
		return 0;
	}

/*This part of the program determines which of the prime numbers in the range are twin primes*/

	while (low<=high-1) {
	if ((prime(low-1) && prime(low+1))) {
		printf("%d", low-1);
		printf("	%d \n", low+1);
		count++;
	}
	low++;
}


/*
if (min%6==0){

min=min+6;

}

else {
	min++;
}
}
*/
printf("count: %d \n",count);
return 0;
}





