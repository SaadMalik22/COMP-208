#include <stdio.h>
#include <math.h>
/*#define W=50000;
#define Y=12000;
#define L=25m;
#define E =72pow(10,9);
*/
typedef double (*DfD) (double);

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

/*double midpoint_int(DfDf, double x0, double x1, int n){
	int i, n;
	double x , x0, x1, dx, sum=0.0;
	dx= (x1-x0)/ n;
	for(i=0, x = x0 + dx/2; i<n; i++,x += dx)
		sum += g(x)*dx;
	return sum;
}
*/
int main () {
	double x,y,z;
	x= midpoint_int(f,0,12.5,1000);
  //printf ("integral from 0 - 12.5= %f\n", x);
	y=midpoint_int(g,12.5,25,1000);
  //printf ("integral from 12.5 - 25= %f\n", y);
	z= ((6.172839506*pow(10,-10))*(y - x));
	printf ("The wing deflection is %f m\n", z);
	return 0;
}
