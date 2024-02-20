#include<stdio.h>
void main()
{
	// Arithematic operator
	int a,b;
	printf("enter the value of a :");
	scanf("%d",&a);
	printf("enter the value of b :");
	scanf("%d",&b);
	printf("Addition = %d\n",a+b);
	printf("Substraction = %d\n",a-b);
	printf("Multiplication = %d\n",a*b);
	printf("Divide = %d\n",a/b);
	printf("Modulo = %d\n\n",a%b);
	
	
	// Assignment operator
	printf("a = %d\n",a);
	printf("b = %d\n",b);
	a+=b;
	printf("a+b = %d\n",a);
	a=b;
	printf("a=b = %d\n\n",a);
	
	
	// Relational operator
	printf("a = %d\n",a);
	printf("b = %d\n",b);
	if (a<b)
	{
		printf("a is less than b\n\n");
	}
	else if (a==b)
	{
		printf("a is equal to b\n\n");
	}
	else
	{
		printf("a is greater than b\n\n");
	}
	
	
	//logical operator
	printf("a = %d\n",a);
	printf("b = %d\n",b);
	if (a>b && a<b) 
	{
		printf("Both condition is have to True\n\n");
	}
	if (a<=b || a!=b) 
	{
		printf("only one condition is True\n\n ");
	}
	else
	{
		printf("If condition is True then answer is False\n\n");
	}
	
	
	// Bitwise operator
	printf("a = %d\n",a);
	printf("b = %d\n",b);
	printf("Bitwise AND operator = %d\n",(a&b));
	printf("Bitwise OR operator = %d\n",(a|b));
	printf("Bitwise XOR operator = %d\n",(a^b));
	printf("Bitwise Left_Shift operator = %d\n",(a<<2));
	printf("Bitwise Right_Shift operator = %d\n\n",(a>>2));	
	
	
	// Conditional operator
	int x=5,y=10;
	printf("x = %d\n",x);
	printf("y = %d\n",y);
	(a>b? printf("a is greater than b") : printf("b is greater than a\n\n"));
	
	
	//Increament/Decreament operator
	printf("x = %d\n",x);
	printf("y = %d\n",y);
	x++;
	y--;
	printf("Increament = %d\n",x);
	printf("Decreament = %d\n\n",y);
	
	
	// Special operators
	int *p,q=100;
	p=&q;
	printf("pointer p = %d\n",*p);
	
	//sizeof operator
	int m;
	float n;
	char c;
	double d;
	printf("Size of integer a = %d\n",sizeof(m));
	printf("Size of float b = %d\n",sizeof(n));
	printf("Size of character c = %d\n",sizeof(c));
	printf("Size of double d = %d\n",sizeof(d));
}

