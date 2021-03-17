#include<stdio.h>
int ones(int);
int tens(int);
int hund(int);
int thou(int);
int main()
{
	check:
	int c,x;
	printf("Enter 1 To print sum of digits of a number \nEnter 2 to print reverse of a number \nEnter 3 to print average of numbers \nEnter 4 to print a table of traingular numbers \nEnter 5 to print number in words ");
	scanf("%d",&c);
	switch (c)
	{
		case 1:
			{
				int n,s=0,d=0; 
				printf("Enter the number ");
				scanf("%d",&n);
				while(n>0)
				{
					d=n%10;
					s=s+d;
					n=n/10;					
				}
				printf("The sum of the digits of the given number is : %d",s);
				break;
			}
		case 2:
			{				
	   			int n,r=0,d=0; 
				printf("Enter the number ");
				scanf("%d",&n);
				while(n>0)
				{
					d=n%10;
					r=r*10+d;
					n=n/10;
					
				}
				printf("The reverse of the given number is : %d",r);
				break; 
			}
		case 3:
			{
			int n,i,s=0,x;
			float avg;
			printf("Enter the number of inputs ");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				printf("Enter number %d ",i+1);
				scanf("%d",&x);
				s=s+x;
				x=0;
			}
			avg=s/n;
			printf("The average of given numbers is %f",avg);
			break;
			}
		case 4:
			{
			int a,i,j,s=0;
			printf("Enter the number of terms in the table ");
			scanf("%d",&a);
			printf("The table : ");
			for(i=1;i<=a;i++)
			{
			for(j=1;j<=i;j++)
				s=s+j;				
			printf("%d\t",s);
			s=0;	
			}			
			break;
		    }
		case 5:
			{
			int n,t,co=0;
			printf("Enter the number : ");
			scanf("%d",&n);
			if(n==0)
			printf("Zero");
			t=n;
				while(t>0)
				{
					co++;
					t=t/10;
				}
			switch (co)
			{
			
			case 1:
			  ones(n); 
			  break;				
			case 2:
				tens(n);
				break;	
			case 3: 
			   hund(n);
			   break;	
			case 4:
				thou(n);
				break;
			case 5:
				thou(n);
				break;
			default:
			    printf("Can't print more than 5 digits.");	
		   }
			
			break;
		   }
		default :
			printf("Wrong choice ");		
	}
	printf("\nEnter 1 if you want to continue, else print 0 \n");
	scanf("%d",&x);
	if(x==1)
	goto check;
}
int ones(int a)
{
	switch (a)
	{
				    case 1:
						printf("One ");
						break;
					case 2:
						printf("Two ");
						break;
					case 3:
						printf("Three ");
						break;
					case 4:
						printf("Four ");
						break;
					case 5:
						printf("Five ");
						break;
					case 6:
						printf("Six ");
						break;
					case 7:
						printf("Seven ");
						break;
					case 8:
						printf("Eight ");
						break;
					case 9:
						printf("Nine ");
						break;			
	}
}
int tens(int t)
{
	int b,x;
			b=t/10;
			x=t%10;
				switch (b)
				{
					case 1:
						switch(x)
						{
							case 0:
								printf("Ten");
								break;
							case 1:
								printf("Eleven");
								break;
							case 2:
								printf("Twelve");
								break;
							case 3:
								printf("Thirteen");
								break;
							case 4:
								printf("Fourteen");
								break;			
							case 5:
								printf("Fifteen");
								break;
							case 6:
								printf("Sixteen");
								break;
							case 7:
								printf("Seventeen");
								break;
							case 8:
								printf("Eighteen");
								break;
							case 9:
								printf("Nineteen");
								break;				
						}				
					case 2:
						printf("Twenty ");
						ones(x);
						break;
					case 3:
						printf("Thirty ");
					    ones(x);
						break;
					case 4:
						printf("Fourty ");
						ones(x);
						break;
					case 5:
						printf("Fifty ");
						ones(x);
						break;
					case 6:
						printf("Sixty ");
						ones(x);
						break;
					case 7:
						printf("Seventy ");
						ones(x);
						break;
					case 8:
						printf("Eighty ");
						ones(x);
						break;
					case 9:
						printf("Ninety ");
						ones(x);
						break;						
				}
}
int hund(int n)
{
    int h,t;
				h=n/100;
				if(h!=0)
				{
					ones(h);
					printf("hundred ");
				}				
				t=n%100;
				tens(t);
}
int thou(int n)
{
	int th,h;
	th=n/1000;
	if((th/10)==0)
	ones(th);
	else
	tens(th);
	printf("thousand ");
	h=n%1000;
	hund(h);
}


