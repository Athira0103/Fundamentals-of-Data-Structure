#include<stdio.h>
int ones(int);
int tens(int);
int hund(int);
int thou(int);
int main()
{
		int n,t,co=0;
			printf("Enter the number : ");
			scanf("%d",&n);
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
		   }
					
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
				ones(h);
				printf("hundred ");
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

