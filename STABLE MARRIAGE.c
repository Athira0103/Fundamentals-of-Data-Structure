#include<stdio.h>
main()
{
	int n;
	printf(" Enter the number of guys and girls ");
	scanf("%d",&n);
	char B[n][n],mo[n][2],wo[n][2];
	int G[n][n];
	int check=0,t,l,c=0;	
	printf(" Girls are denoted using alphabets (Capital letters - A,B,C..etc) and guys using numbers(1,2,3..etc) \n");
	printf("\n Enter the preference of boys in choosing girls \n\n");
	for(int i=0;i<n;i++)
	{
		printf(" Boy %d: ",i+1);
		for(int j=0;j<n;j++)
		scanf(" %c",&B[i][j]);
	}
	fflush(stdin);
	printf("\n Enter the preference of girls in choosing boys \n\n");
	for(int i=0;i<n;i++)
	{
		printf(" Girl %c: ",(i+65));
		for(int j=0;j<n;j++)
		scanf("%d",&G[i][j]);
	}
	for(int i=0;i<n;i++)
	{
		mo[i][0]=i+1;
		int w=i;
		l=0;		
		check1:
		check=0;
		for(int j=0;j<n;j++)
		{
			if(mo[j][1]==B[w][l])
			{
				t=j;
				check=1;
			    break;
			}			
		}
		if(check==1)
		{
			int a = (int) B[w][l];
			int i1,j1;
			a-=65;
			for(int k=0;k<n;k++)
			{
				if(G[a][k]==(w+1))
				i1=k;
				else if(G[a][k]==(t+1))
				j1=k;
			}
			if(j1>i1)
			{
				mo[w][1]=B[w][l];
				mo[t][1]=0;
				w=t;
				l=1;
				goto check1;
							
			}
			else 
			{
				mo[t][1]=B[w][l];
				mo[w][1]=0;
				l++;
				goto check1;
			}			
		}
		else
		mo[w][1]=B[w][l];
	}
	
	printf("\n The preference when boys choose is \n");
	for(int q=0;q<n;q++)
	{
		printf("\n %d  :  %c",mo[q][0],mo[q][1]);
	}
	for(int i=0;i<n;i++)
	{
		wo[i][0]=(char)(i+65);
		int w=i;
		l=0;		
		check2:
		check=0;
		for(int j=0;j<n;j++)
		{
			if(wo[j][1]==G[w][l])
			{
				t=j;
				check=1;
			    break;
			}			
		}
		if(check==1)
		{
			int a = G[w][l];
			int i1,j1;
			a--;
			for(int k=0;k<n;k++)
			{
				if(B[a][k]==(char)(w+65))
				i1=k;
				else if(B[a][k]==(char)(t+65))
				j1=k;
			}
			if(j1>i1)
			{
				wo[w][1]=G[w][l];
				wo[t][1]=0;
				w=t;
				l=1;
				goto check2;
							
			}
			else 
			{
				wo[t][1]=G[w][l];
				wo[w][1]=0;
				l++;
				goto check2;
			}			
		}
		else
		wo[w][1]=G[w][l];
	}
	printf("\n\n The preference when girls choose is \n");
	for(int q=0;q<n;q++)
	{
		printf("\n %c  :  %d",wo[q][0],wo[q][1]);
	}
	for(int q=0;q<n;q++)
	{
		if(mo[q][0]==wo[q][1] && mo[q][1]==wo[q][0])
		continue;
		else 
		{
			c=1;
			break;
		}		
	}
	if(c==1)
	printf("\n\n The marriage is not stable!!");
	else 
	printf("\n\n The marriage is stable!!");
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

