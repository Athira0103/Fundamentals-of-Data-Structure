#include<stdio.h>
int stack[50],n=50,top=-1;
void push();
void pop();
void display();
main()
{
	int ch;
	bool quit = false;
	while(!quit)
	{
		printf("\nChoose your stack operation.Enter: \n1.Push \n2.Pop \n3.Display \n4.Quit. ");
	    scanf("%d",&ch);
	    switch (ch)
	    {
		    case 1:
			    {
			    	push();			    	
				    break;
			    }
		    case 2:
			    {
			    	pop();			    	
				    break;
			    }
		    case 3:
			    {
			    	display();			    	
				    break;
			    }
			case 4:
				{
					quit=true;
					break;
				}
		    default:
			    printf("Wrong choice ");
	    }
	}
	
}
void push()
{
int x;
if(top==n-1)
printf("\nStack Overflow!!!! \n");
else
{
printf("\nEnter the value to be pushed. ");
scanf("%d",&x);
top++;
stack[top]=x;
printf("Top value : %d\n",stack[top]);
}
}
void pop()
{
	if(top==-1)
	printf("\nStack Underflow!!!!! \n ");
	else 
	{
		printf("\nThe element being popped : %d\n",stack[top]);
		top--;
		if(top==-1)
		printf("The stack is now empty. \n");
		else
		printf("Top value : %d\n",stack[top]);
	}
}
void display()
{
	if(top==-1)
	printf("\nEmpty Stack \n");
	else
	{
		printf("\nThe stack elements are : ");
		for(int i=0;i<=top;i++)
		printf("\t%d",stack[i]);
		printf("\n");
		printf("Top value : %d\n",stack[top]);
	}
	
}
