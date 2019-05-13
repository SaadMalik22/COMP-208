#include <stdio.h>
#include <math.h>

typedef float (*DfD) (double);
double f(double x) {
	return(12000*pow(x,3))/2;
}
double g(double x) {
	return(50000*x*(x-12.5) - (12000*pow(x,3)/2));
}

double midpoint_int(DfD f, double x0, double x1, int n){
	int i;
	double x, dx, sum=0.0;
	dx= (x1-x0)/ n;


	for(i=0, x = x0 + dx/2; i<n; i++,x += dx)
		sum += f(x)*dx;
	return sum;
}

double bisection (DfD f, double x0, double x1, double tol){
	double middle;
	for(; ;){
		middle = (x0+x1)/2.0;
		if(fabs(middle-x0)<tol)
			return middle;
		else if (f(middle)*f(x0)<0.0)
			x1= middle;
		else
		x0= middle;
	}
}

double d (double e) {
	double inta=midpoint_int(f,0,12.5,1000);
	double intb=midpoint_int(g,12.5,25,1000);
	return ((1/(e*0.0225))*(inta-intb))-0.5;
}

int main() {
	double c;
	c=(bisection(d, 70*pow(10,9) , 250*pow(10,9), 0.001))/pow(10,9);
	printf("The optimal elastic modulus is %f Gpa\n", c);
	return 0;
}
