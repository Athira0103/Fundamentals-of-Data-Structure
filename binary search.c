#include<stdio.h>
void ibs(int a[],int n,int m,int c);
int bsr(int a[],int front,int end,int m,int c);
main()
{
	int n,a[50],i,m,ch,cho;
	char o;
	bool quit = false;	
	while(!quit)
	{
	printf("Enter the number of elements in the array ");
	scanf("%d",&n);
	printf("What is the order of entering elements?\nEnter\n1.Ascending order\n2.Descending order ");
	scanf("%d",&ch);	
	switch(ch)
	{
		case 1:
			{
				printf("Enter the array elements in ascending order ");
				for(i=0;i<n;i++)
				scanf("%d",&a[i]);
				check1:
				printf("Enter the element to be searched ");
				scanf("%d",&m);
				printf("\nEnter: 1 for iterative binary search, 2 for recursive binary search ");
				scanf("%d",&cho);
				switch(cho)
				{
					case 1:
						{
							ibs(a,n,m,ch);
							break;						
						}
					case 2:
						{
							int check = bsr(a,0,n-1,m,ch);
				            if(check==0)
							printf("\nElement not found");
							break;
						}
					default:
					printf("Wrong choice");					
				}
				printf("\nDo you want to continue searching in the same array? (y/n) ");
				scanf("%c",&o);
				if(o=='y')
				goto check1;
			break;
	        }
	    case 2:
	    	{
	    		printf("Enter the array elements in descending order ");
				for(i=0;i<n;i++)
				scanf("%d",&a[i]);
				check2:
				printf("Enter the element to be searched ");
				scanf("%d",&m);
				printf("\nEnter: 1 for iterative binary search, 2 for recursive binary search ");
				scanf("%d",&cho);
				switch(cho)
				{
					case 1:
						{
							ibs(a,n,m,ch);
							break;						
						}
					case 2:
						{
							int check = bsr(a,0,n-1,m,ch);
				            if(check==0)
							printf("\nElement not found");
							break;
						}
					default:
					printf("Wrong choice");
				}
				printf("\nDo you want to continue searching in the same array? (y/n) ");
				scanf("%c",&o);
				if(o=='y')
				goto check2;
			break;
			}
		default:
			printf("Wrong choice ");				
	}
	printf("\nDo you want to continue searching for a different array? (y/n) ");
	scanf("%c",&o);
	if(o=='n')
	quit = true;
    }
}
void ibs(int a[],int n,int m,int c)
{
	int check=0,front = 0,end = n-1,mid;
	while(front<=end)
	{
		mid = (end+front)/2;
	    if(m>a[mid])
	    {
	    	if(c==1)
	    	front = mid+1;
	    	else if(c==2)
	    	end=mid-1;
		}		    
	    else if(a[mid]==m)
	    {
		    printf("\nThe element is found at position %d",mid+1);
		    check++;
		    break;		
	    }
	    else
	    {
	    	if(c==1)
	    	end = mid-1;
	    	else if(c==2)
	    	front=mid+1;
		}
	        
    }
	if(check==0)
	printf("\nThe element not found");
}
int bsr(int a[],int front,int end,int m,int c) 
{
	int check=0;
	if(front>end)
	    return check;
    int mid = (front+end)/2;
    if(a[mid]==m)
    {
    	printf("\nThe element is found at position : %d",mid+1);
    	check++;
    	return check;
    }       
    else if(m<a[mid])
    {
    	if(c==1)
    	bsr(a,front,mid-1,m,c);
    	else if(c==2)
    	bsr(a,mid+1,end,m,c);
	}        
    else
    {
    	if(c==1)
    	bsr(a,mid+1,end,m,c);
    	else if(c==2)
    	bsr(a,front,mid-1,m,c);
	}
        
}

