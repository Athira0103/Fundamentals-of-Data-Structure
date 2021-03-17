#include<stdio.h>
int sparse(int ch);
int sparseadd();	
	int i,j,c,r,ch,r2,c2,k,n,o,m,u,t=0;
int main()
{
	check:
	int a[10][10], b[10][10], d[10][10];
	printf("Enter \n1 for matrix adition \n2 for matrix subtraction \n3 for matrix multiplication \n4 for finding greatest nember from each row \n5 for addition of major diagonal elements \n6 for sparse matrix representation \n7 for addiition of 2 sparse matrix \n8 for transpose of a sparse matrix ");
	printf("\nEnter your choice ");
	scanf("%d",&ch);
	if(ch>=1 && ch<5)
	{
	printf("Enter the number of rows and columns in the matrix ");
	scanf("%d %d",&r,&c);
	printf("Enter the matrix elements ");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		scanf("%d",&a[i][j]);
	}
	}
	switch (ch)
	{
		case 1:
			{
				printf("Enter the rows and columns of second matrix ");
				scanf("%d %d",&r2,&c2);
				if(r==r2 && c==c2)
				{
					printf("Enter the second matrix elements ");
					for(i=0;i<r2;i++)
					{
					for(j=0;j<c2;j++)
					scanf("%d",&b[i][j]);
					}
					for(i=0;i<r;i++)
					{
						for(j=0;j<c;j++)
						d[i][j]=a[i][j]+b[i][j];
					}
					printf("The resultant matrix is ");
					for(i=0;i<r;i++)
					{
						printf("\n");
						for(j=0;j<c;j++)
						printf("%d \t",d[i][j]);
					}
				}
				else
				printf("The addition of unequal matrices is not possible");
				break;
			}
		case 2:
		    {
		    	printf("Enter the rows and columns of second matrix ");
				scanf("%d %d",&r2,&c2);
				if(r==r2 && c==c2)
				{
					printf("Enter the second matrix elements ");
					for(i=0;i<r2;i++)
					{
					for(j=0;j<c2;j++)
					scanf("%d",&b[i][j]);
					}
					for(i=0;i<r;i++)
					{
						for(j=0;j<c;j++)
						d[i][j]=a[i][j]-b[i][j];
					}
					printf("The resultant matrix is ");
					for(i=0;i<r;i++)
					{
						printf("\n");
						for(j=0;j<c;j++)
						printf("%d \t",d[i][j]);
					}
				}
				else
				printf("The subtraction of unequal matrices is not possible");
		    	break;			
			}
		case 3:
		{
			printf("Enter the rows and columns of second matrix ");
			scanf("%d %d",&r2,&c2);
			if(c==r2)
			{
				printf("Enter the second matrix elements ");
				for(i=0;i<r2;i++)
				{
				for(j=0;j<c2;j++)
				scanf("%d",&b[i][j]);
				}
				for(i=0;i<r;i++) 
				{
				for(j=0;j<c2;j++) 
				{
					d[i][j]=0;
				    for(k=0;k<c;k++) 
					d[i][j]+=a[i][k]*b[k][j];
				}
				}
				printf("The resultant matrix is ");
				for(i=0;i<r;i++)
				{
					printf("\n");
					for(j=0;j<c2;j++)
					printf("%d\t",d[i][j]);						
				}
			}
			else
			printf("The multiplication of given matrices is not possible");		    	
			break;
		}
		case 4:
		{
		for(i=0;i<r;i++)
			{
				int max=a[i][0];
				for(j=0;j<c;j++)
				{
					if(a[i][j]>max)
					max=a[i][j];
				}
				printf("The maximum value in row %d is: %d \n",i+1,max);
			}
			break;
		}
		case 5:
		{
			printf("Enter the number of rows and columns in the matrix ");
	        scanf("%d %d",&r,&c);
			int s=0;
			if(r==c)
			{
			printf("\nEnter the elements ");
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					printf("Element [%d][%d] ",i,j);
					scanf("%d",&a[i][j]);
					if(j==i)
					s+=a[i][j];
				}
			}
			printf("The sum of major diagonal elememts are: %d",s);
		    }
		    else 
		    printf("There is no major diagonal for the given matrix ");
			break;
		}
		case 6:
		{
			sparse(ch);
			break;
		}
		case 7:
		{
		    sparseadd();
			break;
		}
		case 8:
		{
		    sparse(ch);
			break;
		}	
		default :
		printf("Wrong choice");
	}
	printf("\nPress 1 if you want to continue, else enter 0 \n");
	scanf("%d",&o);
	if(o==1)
	goto check;
}
int sparse(int ch)
{
	int a[10][10],b[10][10];
	int t=0,k=0;
	printf("Enter the number of rows and columns in the regular matrix ");
	scanf("%d %d",&r,&c);
	printf("Enter the regular matrix elements ");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
		scanf("%d",&a[i][j]);
		if(a[i][j]!=0)
		t++;
	     }
	}
	if(t<((r*c)+1)/2){
	for(i=0;i<r;i++)
		{
		for(j=0;j<c;j++)
			{
				if(a[i][j]!=0)
				{
					b[k][0]=i;
					b[k][1]=j;
					b[k][2]=a[i][j];
					k++;
				}
		    }
		}
	printf("\nThe sparse matrix representation is :");
	for(i=0;i<k;i++)
		{
			printf("\n");
			for(j=0;j<3;j++)
			printf("%d \t",b[i][j]);
		}
		if(ch==8)
		{
			for(i=0;i<k;i++)
			{
			int t=b[i][0];						
			b[i][0]=b[i][1];
			b[i][1]=t;
			}
			printf("\nThe transpose of the given sparse matrix is ");
		for(i=0;i<k-1;i++)
		{
			for(j=0;j<k-1-i;j++)
			{
			if((b[j][0]>b[j+1][0])||((b[j][0]==b[j+1][0])&&(b[j][1]>b[j+1][1])))
			{
			for(u=0;u<3;u++)
			 {
			 int t=b[j][u];
			 b[j][u]=b[j+1][u];
			 b[j+1][u]=t;
			 }
			}
			}			
		}
		for(i=0;i<k;i++)
			{
			printf("\n");
			for(j=0;j<3;j++)
			printf("%d \t",b[i][j]);
			} 
		}		
	}
	else
	printf("The given matrix is not sparse.");
}
int sparseadd()
{
    int ad[20][3],b[10][10],d[10][10];
    printf("\nEnter the number of rows in first sparse matrix ");
	scanf("%d",&r);
	printf("\nEnter the elements of first sparse matrix ");
	for(i=0;i<r;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\nEnter the element [%d][%d] ");
			scanf("%d",&b[i][j]);
		}
		
	}
	
	printf("\nEnter the number of rows of second sparse matrix ");
	scanf("%d",&r2);
	printf("\nEnter the elements of the second sparse matrix ");
	for(i=0;i<r2;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\nEnter the element [%d][%d] ");
			scanf("%d",&d[i][j]);
		}
		
	}
    
	for(i=0;i<r;i++)
	{
		int count = 0;
		for(j=0;j<r2;j++)
		{
		    if((b[i][0]==d[j][0])&&(b[i][1]==d[j][1]))
				{
				    ad[i][0]=b[i][0];
				    ad[i][1]=b[i][1];
				    ad[i][2]=b[i][2]+d[j][2];
				    d[j][2]=0;
				    count=1;
				    break;
				}
		}
		if (count!=1)
			{
				ad[i][0]=b[i][0];
			    ad[i][1]=b[i][1];
			    ad[i][2]=b[i][2];
			}				
	}
	int q=0;
	for(i=0;i<r2;i++)
	{
		if(d[i][2]!=0)
		{
			m=r+q;
			ad[m][0]=d[i][0];
		    ad[m][1]=d[i][1];
		    ad[m][2]=d[i][2];
		    q++;
		}
	}			
	printf("\nThe sum of 2 sparse matrix is ");
	for(i=0;i<m;i++)
	{
	    for(j=0;j<m-i;j++)
		{
		    if((ad[j][0]>ad[j+1][0])||((ad[j][0]==ad[j+1][0])&&(ad[j][1]>ad[j+1][1])))
			{
			for(u=0;u<3;u++)
			 {
			 t=ad[j][u];
			 ad[j][u]=ad[j+1][u];
			 ad[j+1][u]=t;
			 }
			}
		}			
	}
	for(i=0;i<=m;i++)
		{
		printf("\n");
		for(j=0;j<3;j++)
		printf("%d \t",ad[i][j]);			
	    }						
}

	
	

