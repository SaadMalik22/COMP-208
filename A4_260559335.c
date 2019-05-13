// A4_260559335.c.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int RPS(int t, int r) {
	//1 for win, 2 for draw, 3 for lose.
	int decision;
	if(t==0){
		if(r==0) {
			printf("Draw\n");
			decision=2;
        }
        if(r==1) {
			printf("Computer wins with paper\n");
			decision=1;
        }
        if(r==2) {
            printf("Player wins\n");
            decision=3;
            
        }
    }
	
	else if(t==1) {
		if(r==0) {
			printf("Player wins\n");
			decision=3;
		}
		if(r==1) {
			printf("Draw\n");
			decision=2;
		}
		if(r==2) {
			printf("Computer wins with scissor\n");
			decision=1;
		}
	}
	else {
		if(r==0) {
			printf("Computer wins with rock\n");
			decision=1;
		}
		if (r==1) {
			printf("Player wins\n");
			decision=3;
        }
		if (r==2) {
			printf("Draw\n");
			decision=2;
        }
	}
	return decision;
}
// The above function gives the result for each scenario
int main(void) {
   
    int i, j, g, b, a, y, num;
	int val [3][3];
	//The Array is initialized here 
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
            val[i][j]=10;
		}
	}
    
    
   
    srand(time(NULL));
    
    for(y=1; y<30; y++) {
        printf("Would you like to play the game?\n1 for yes, 2 for no.\n");
        scanf("%d", &g);
      
        
        while(g==1) {
			printf("\nGame %d\n", y);
            printf("\n0 for Rock, 1 for Paper, 2 for Scissors.\n");
            scanf("\n%d", &a);
           
            
            num = rand()%100;
            printf("\nThe random number is : %d\n",num);
            float range1= ((1.0*val[a][0])/(val[a][0]+val[a][1]+val[a][2]))*100;
            float range2 = range1 + ((1.0*val[a][1])/(val[a][0]+val[a][1]+val[a][2]))*100;
            float range3 = range2 +((1.0*val[a][2])/(val[a][0]+val[a][1]+val[a][2]))*100;
			// Range is initialized above 
            
            
            
            if(num<=range1){
                b=0;
            }
            else if (num>range1 && num<range2) {
                b=1;
            }
            else if (num>range2) {
                b=2;
            }
            printf("Computer's move is: %d\n",b);
            
			//The above function determines the computers move based on where the random number lies in the given ranges 
            
            if(RPS(a, b)==1) {
                val[a][b]+=6;
               
            }
            if(RPS(a, b)==2 || RPS(a, b)==3 ) {
                val[a][b]-=2;
            }
                
                
        
            printf("The probability of this scenario is: %0.3f\n", ((1.0*val[a][b])/(val[a][0]+val[a][1]+val[a][2]))*100);
			y++;
        }
    }
    
    
    return 0;
}


