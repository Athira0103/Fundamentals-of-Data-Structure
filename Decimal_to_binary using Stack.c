//decimal to binary using stack
#include<stdio.h>
int stack[50],n,top=-1;
void push(int x);
void pop();
main()
{
	int x;
	printf("Enter the decimal number to be converted to binary. ");
	scanf("%d",&n);	
	while(n>0)
	{
	x=n%2;    
	n=n/2;
	push(x);
	}
	printf("\nThe binary number is : ");
	while(top!=-1)	
	pop();
}
void push(int x)
{
	top++;
	stack[top]=x;
}
void pop()
{
    printf("%d",stack[top]);
	top--;	
}
