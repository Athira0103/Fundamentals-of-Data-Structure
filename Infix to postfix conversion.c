//infix to postfix
#include<stdio.h>
#include<string.h>
int checkpre(char c);
void push(char c);
char pop();
char stack[30];
int top=-1;
main()
{
	char e[30],o[30];
	int p,k,j=0,i=0;
	printf("Enter the infix expression ");
	gets(e);
	int l=strlen(e);
	if( e[l-1]<48 ||  e[l-1]>57 && e[l-1]<65 || e[l-1]>90 && e[l-1]<97 || e[l-1]>122)
	printf("\nInvalid infix expression!!! ");
	else
	{
	while(i<l)
	{
		if(e[i]>=65 && e[i]<=90 || e[i]>=48 && e[i]<=57 || e[i]>=97 && e[i]<=122)
		{
			o[j]= e[i];
			j++;
		}
		else
		{
			p=checkpre(e[i]);
			k=checkpre(stack[top]);
			if(p<=k)
			{
				if(p==0||k==0)
				push(e[i]);
				else if(p==-1)
				{
					o[j]=pop();
				    j++;
				    while(checkpre(stack[top])!=0)
					{
					o[j]=pop();
					j++;
					}
					top--;
			    }			
				else
				{
				while(checkpre(stack[top])>=p)
				{
					o[j]=pop();
					j++;
				}
				push(e[i]);
				}										
			}			
			else
			push(e[i]);			
		}
		i++;		
	}
	while(top!=-1)
		{
			o[j]=stack[top];
			printf("\nPopping : %c",stack[top]);
			j++;
			top--;
		}
	printf("\nThe postfix expression is : ");
	for(int b=0;b<j;b++)
	printf("%c",o[b]);
}
}
int checkpre(char c)
{
	int p;
	if(c=='^')
	p=3;
	else if(c=='*' || c=='/' )
	p=2;
	else if(c=='+' || c=='-' )
	p=1;
	else if(c=='(' || c=='[' || c=='{')
	p=0;
	else
	p=-1;
	return p;
}
void push(char c)
{
	top++;
	stack[top]=c;
	printf("\nPushing : %c",stack[top]);
}
char pop()
{
	printf("\nPopping : %c",stack[top]);
	top--;
	return stack[top+1];
}
