#include<stdio.h>

//Function to implement the Extended Euclidean Algorithm 
int extendedGCD(int a,int b, int *x,int *y){
	if(b == 0){
		*x=1;
		*y=0;
		return a; //GCD(a,0)=a
	}
 int x1, y1;
    int gcd = extendedGCD(b, a % b, &x1, &y1);

    // Update x and y using recursion results
    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}
int main(){
	int a, b, x, y;
	
	//Input two numbers 
	printf("Enter two numbers:");
	scanf("%d %d",&a,&b);
	
	//Compute GCD and coefficient x,y
	int gcd = extendedGCD(a, b, &x, &y);
	
	//Display results
	printf("GCD of %d and %d is %d\n", a, b, gcd);
	printf("coefficient of x=%d,y=%d\n", x, y);
	printf("Verification: %d * %d + %d * %d = %d\n", a, x, b, y, gcd);
	return 0;
}
