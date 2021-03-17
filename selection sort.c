#include<stdio.h>
int selection_sort(int arr[],int n,int ch);
int ad=0;
main()
{
	int n,ch;
	char c;
	check:
	printf("Enter the size of the array ");
	scanf("%d",&n);
	int t[n],a[n];
	printf("Enter the array elements ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		t[i]=a[i];
	}
	printf("What is the order to sort the array? \nEnter \n1.Ascending order \n2.Descending order ");
	scanf("%d",&ch);
	check1:
	if(ad==1)
	{
		for(int i=0;i<n;i++)
		a[i]=t[i];			
	}
	printf("\nOriginal : ");
	for(int i=0;i<n;i++)
	printf("%d\t",a[i]);
	printf("\n");
	ad=selection_sort(a,n,ch);
	if(ch==1 && ad==1)
	{
		printf("\n\nDo you want to sort the same array in descending order? (y/n) ");
		scanf(" %c",&c);
		if(c=='y')
		{
			ch=2;
			goto check1;
		}
	}
	else if(ch==2 && ad==1)
	{
		printf("\n\nDo you want to sort the same array in ascending order? (y/n) ");
		scanf(" %c",&c);
		if(c=='y')
		{
			ch=1;
			goto check1;
		}
	}
	printf("\nDo you want to sort another array? (y/n) ");
	scanf(" %c",&c);
	if(c=='y')
	{
		ad=0;
		goto check;
	}	
}
int selection_sort(int arr[],int n,int ch)
{
	for(int i=0;i<n;i++)
	{
		int temp=i;
		for(int j=i;j<n;j++)
		{
			switch(ch)
			{
				case 1:
				{
					if(arr[temp]>arr[j])
					temp=j;
					break;
				}
				case 2:
			    {
				    if(arr[temp]<arr[j])
				    temp=j;
				    break;
				}						
			}
		}
		int t=arr[i];
		arr[i]=arr[temp];
		arr[temp]=t;
		printf("\nPass %d: ",i+1);
		for(int k=0;k<n;k++)
		printf("%d\t",arr[k]);
	}
	printf("\n\nFinal : ");
	for(int l=0;l<n;l++)
	printf("%d\t",arr[l]);
	ad++;
	return ad;
}
