//paranthesis check
#include<stdio.h>
void push(char c);
char pop();
int top=-1;
char stack[20];
main()
{
    char p[20];	
	int i=0,check=0;
	char a;
	printf("Enter the paranthesis order to be checked ");
	while(i<20)
	{
		char x;
		scanf("%c",&x);
		if(x!='\n' && x!=' ')
		{
			p[i]=x;
			i++;
		}
		else
		break;		
	}
	i--;
	if(i%2==0)
	printf("Paranthesis are not well formed. ");
	else
	{
		for(int j=0;j<=i;j++)
		{
			if(p[j]=='('|| p[j]=='{'|| p[j]=='[')
			push(p[j]);
			if( p[j]==')'|| p[j]=='}' || p[j]==']' )
			{
				a=pop();
				if( a=='(' && p[j]!= ')' || a=='{' && p[j]!= '}' || a=='[' && p[j]!= ']')
				{
					check=1;
					printf("Paranthesis are not well formed. ");
					break;
				}				
			}
		}
		if(check==0)
		printf("Paranthesis are well formed. ");
	}
}
void push(char c)
{
	top++;
	stack[top]=c;
}
char pop()
{
	top--;
	return stack[top+1];
}
