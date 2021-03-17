#include<stdio.h>
int main()
{
	int arr[50];
	int i,c,a,k;
	printf("Enter the number of elements in the array ");
	scanf("%d",&a);
	printf("Enter the numbers : ");
	for(i=0;i<a;i++)
	{
		scanf("%d",&arr[i]);		
	}
	check:
	printf("Enter \n1 for Insertion at a position in the array \n2 for Insertion at beginning \n3 for Insertion at end \n4 for Delete by position \n5 for Delete by the first occurrence of element");
    printf("\n6 for Search by position \n7 for Search by element(present or not) \n8 for revert the array (in place) ");
    scanf("%d",&c);
    switch(c)
    {
    	case 1:
    	{
    		int n,x;
    		printf("Enter the position in which you need to input the number ");
    		scanf("%d",&n);
    		n--;
    		for(i=a;i>=n;i--)
    		{
    			arr[i]=arr[i-1];
			}
			printf("Enter the number to be input ");
			scanf("%d",&arr[n]);
			printf("The new array is : ");
			for (i=0;i<=a;i++)
				printf("%d\t",arr[i]);
			a++;	
			break;	  			
		}
		case 2:
		{
			for(i=a;i>=0;i--)
    		{
    			arr[i]=arr[i-1];
			}
			printf("Enter the number to be input ");
			scanf("%d",&arr[0]);
			printf("The new array is : ");
			for (i=0;i<=a;i++)
				printf("%d\t",arr[i]);
			a++;	
			break;	  			
			
		}
		case 3:
		{
			printf("Enter the number to be input ");
			scanf("%d",&arr[a]);
			printf("The new array is : ");
			for (i=0;i<=a;i++)
				printf("%d\t",arr[i]);
			a++;	
			break;	  			
			
		}
		case 4:
		{
			int n;
			printf("Enter the position in which you need to delete the number ");
			scanf("%d",&n);
			if(n<=a)
			{
			for(i=n-1;i<a;i++)
    		{
    			arr[i]=arr[i+1];
			}
			printf("The new array is \n");
			for (i=0;i<a-1;i++)
				printf("%d\t",arr[i]);
			a--;
     		}
     		else 
     		printf("There is no element in the given position ");
			break;
			
		}
		case 5:
		{
			int j,n,i;
			printf("Enter the number to be deleted ");
			scanf("%d",&n);
			for(i=0;i<a;i++)
			{
				if(arr[i]==n)
				break;								
			}
			if(i==a)
			printf("The number is not present in the array ");
			else
			{
				printf("The new array is : ");
				for(j=i;j<a;j++)
				arr[j]=arr[j+1];
				for (i=0;i<a-1;i++)
				printf("%d\t",arr[i]);
		
    		}	
    		a--;
    		break;
		}
		case 6:
		{
			int n;
			printf("Enter the position in the array to be searched ");
			scanf("%d",&n);
			if(n<=a)
			printf("The number present in the given position is : %d",arr[n-1]);
			else
			printf("There is no number present in the given position. ");
			break;
		}
		case 7:
		{
			int i,n,c=0;
			printf("Enter the element to be searched ");
			scanf("%d",&n);
			for(i=0;i<a;i++)
			{
				if(arr[i]==n)
				{
					printf("The number is present at position : %d\n",i+1);
					c++;
				}
			}
			if(c==0)
			printf("The given number is not present in the array");
			break;
		}
		case 8:
		{
			int i,t,n;
			n=(a-2)/2;
			for(i=0;i<=n;i++)
			{
				t=arr[i];
				arr[i]=arr[a-1-i];
				arr[a-1-i]=t;
			}
			printf("The new array is : ");
			for (i=0;i<a;i++)
			printf("%d\t",arr[i]);
			break;
		}	
	}
	printf("\n Press 1 if you want to continue, else print 0 \n");
	scanf("%d",&k);
	if(k==1)
	goto check;
}
