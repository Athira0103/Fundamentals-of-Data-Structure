#include<stdio.h>

void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
	
}

int partition(int a[],int p,int r)
{
    int x,i,j;
    x=a[r];
    i=p-1;
    for(j=p;j<=r-1;j++)
    {
        if(a[j]<=x)
        {
            
            i=i+1;
            swap(&a[i],&a[j]);
            
        }
    }
    
    swap(&a[i+1],&a[r]);
    return(i+1);
}

void quicksort(int a[10],int p,int r,int n)
{
    int q;
    if(p<r)
    {
    	printf("\nPass:");
        q=partition(a,p,r);
        display(a,n);
        quicksort(a,p,q-1,n);
        quicksort(a,q+1,r,n);
    }
}

int main()
{
	int a[10],n,i;
    printf("How many elements you want in your array?");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Original array:");
    display(a,n);
    quicksort(a,0,n-1,n);
    printf("\nArray after sorting:");
    display(a,n);
    return 0;
    
}
	
