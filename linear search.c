#include<stdio.h>
void search(int a[],int,int);
main()
{
	int i,n,m;
	char c;
	check:
	printf("Enter the numbers of elements in the array ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	check1:
	printf("Enter the number to be searched ");
	scanf("%d",&m);
	search(a,m,n);
	printf("\nDo you want to search for another element in the same array? (y/n) ");
	scanf(" %c",&c);
	if(c=='y')
	goto check1;
	printf("\nDo you want to search for an element in a new array? (y/n) ");
	scanf(" %c",&c);
	if(c=='y')
	goto check;	
}
void search(int a[],int n,int l)
{
	int check=0;
	for(int i=0;i<l;i++)
	{
		if(a[i]==n)
		{
			check++;
			printf("The element is found at position %d\n",i+1);
		}
	}
	if(check==0)
	printf("The element not found\n ");
}
