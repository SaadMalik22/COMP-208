#include<stdio.h>

#include<math.h>





int sumsquaredigits (int number, int *size, int *a) {
    a[*size] = number;
    (*size)++;
    int counter=0;
    while(1){
        counter++;
        if(counter>999)
            break;
        int sum=0;
        while(1){
            if(number==0)
                break;
            int digit = number%10;
            number/=10;
            sum+= digit*digit;
        }
        a[*size]=sum;
        (*size)++;
        if(sum==1)
            return 1;
        number = sum;
    }
    return 0;
}
//The above function takes the sum of the square digits of the number entered afterwards it stores the numbers in the array

void printSequence(int *a, int size){
    int i;
    for(i=0; i<size; i++){
        printf("%d \n", a[i]);
    }
}
//The above function prints the numbers on the screen

/*printf("%d", sum)
 int search (int a[]; int sum; size=1000) {
 int i, a[]={sumsquaredigits(n)};
 for(i=0; i<1000; i++) {
 if (a[i]==sumsquaredigits(int n)) {
 return 0;
 }
 }
 return 1;
 }*/


int main() {

	int a[1000]={0};
	int size=0;
    int number;
    scanf("%d", &number);
    if (sumsquaredigits(number, &size, a)) {
        printf("It is a happy number\n");
        printSequence(a, size);
    }
    else {
        printf("It is not a happy number\n");
    }
    return 0;
}
// In the above function the array is declared and input is accepted