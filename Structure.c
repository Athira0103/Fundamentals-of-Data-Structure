#include<stdio.h>
#include<string.h>
struct Student
{
	char name[10];
	int prn;
	float avg;
}s[20];
main()
{
	int ch,i=0,j,o,nr,co=0,pn;
	//char n[10];
	printf("Enter \n1 for creating structure records \n2 for inserting structure records \n3 for modifying a structure record \n4 for deleting a structure record \n5 for displaying all structure records");
	check:
	printf("\nEnter your choice ");
	scanf("%d",&ch);
	switch (ch)
	{
		case 1:
		{
			printf("Enter the number of records to be created ");
			scanf("%d",&nr);
			for(i=0;i<nr;i++)
			{
			printf("\nStudent %d:\n",i+1);
			printf("Enter the student name ");
			scanf("%s",s[i].name);
			printf("Enter the student prn ");
			scanf("%d",&s[i].prn);
			printf("Enter the average marks of student ");
			scanf("%f",&s[i].avg);
			printf("The new structure record is created ");
		    }
		    co+=nr;
		    break;
		}
		case 2:
		{
			printf("Enter the number of records to be inserted ");
			scanf("%d",&nr);
			for(i=0;i<nr;i++)
			{
			printf("\nStudent %d:\n",co+i+1);
			printf("Enter the student name ");
			scanf("%s",s[co+i].name);
			printf("Enter the student prn ");
			scanf("%d",&s[co+i].prn);
			printf("Enter the average marks of student ");
			scanf("%f",&s[co+i].avg);
			printf("The structure record is inserted ");
		    }
		    co+=nr;
		    break;	
		}
		case 3:
		{
			int h=0,cho;
			printf("Enter the prn of record to be modified ");
			scanf("%d",&pn);
			for(i=0;i<co;i++)
			{
			if(s[i].prn==pn)
			{
				printf("Enter 1 to modify name\n2 to modify average\n3 to modify both. ");
				scanf("%d",&cho);
				switch(cho)
				{
					case 1:
						{
							printf("Enter the modified name ");
							scanf("%s",s[i].name);
							h++;
							break;
						}
					case 2:
						{
							printf("Enter the modified average ");
							scanf("%f",&s[i].avg);
							h++;
							break;
						}
					case 3:
						{
							printf("Enter the modified name ");
							scanf("%s",s[i].name);
							printf("Enter the modified average ");
							scanf("%f",&s[i].avg);
							break;
							h++;							
						}
					default : 
					printf("Wrong choice ");
				}
			}
		    }
		    if(h==0)
		    printf("No matching record found");
		    else
		    printf("The given record is modified ");
		    break;		    	
		}
		case 4:
		{
			int h=0;
			printf("Enter the prn of record to be deleted ");
			scanf("%d",&pn);
			for(i=0;i<co;i++)
			{
			if(s[i].prn==pn)
			    {
			    for(j=i;j<co-1;j++)
			        {
			            strcpy(s[j].name,s[j+1].name);
			            s[j].avg= s[j+1].avg;
			            s[j].prn = s[j+1].prn;
		            }
		        h++; 
				co--;   
			    printf("The given record is deleted ");
		        }
		    }
		    if(h==0)
		        printf("No matching record found");
			break;
		}
		case 5:
		{
			if(co>0)
			{
			for(j=0;j<co;j++)
			{
				printf("Student %d:\n",(j+1));
				printf("Name : %s\t",s[j].name);
				printf("PRN : %d\t",s[j].prn);
				printf("Average marks : %f\n",s[j].avg);
			}
		    }
		    else
		    printf("Empty");
			break;
		}
		default :
		printf("Wrong choice ");		
	}
	printf("\nIf you want to continue press 1, else 0 ");
	scanf("%d",&o);
	if(o==1)
	goto check;
}
