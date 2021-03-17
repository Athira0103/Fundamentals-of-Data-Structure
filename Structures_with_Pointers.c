#include<stdio.h>
#include<string.h>
struct student
{
	char name[10];
	int prn;
	float percent;
};
int co=0,i;
void create(struct student *p);
void insert(struct student *p);
void modify(struct student *p);
void del(struct student *p);
void display(struct student *p);
main()
{
	int ch,j,o;
	struct student s[50];
	printf("...................PROGRAM TO IMPLEMENT STRUCTURES WITH POINTERS................... \n");
	printf("Enter \n1 for creating structure records \n2 for inserting structure records \n3 for modifying a structure record \n4 for deleting a structure record \n5 for displaying all structure records");
	check:
	printf("\nEnter your choice ");
	scanf("%d",&ch);
	switch (ch)
	{
		case 1:
		{
			create(s);
			break;
		}
		case 2:
		{
			insert(s);
		    break;
		}
		case 3:
		{
			modify(s);
			break;
		}
		case 4:
		{
			del(s);
			break;
		}
		case 5:
		{
			display(s);
			break;				
		}
		default :
		printf("Wrong choice ");		
	}
	printf("\nIf you wanna continue press 1, else 0 \n");
	scanf("%d",&o);
	if(o==1)
	goto check;
}
void create(struct student *p)
{
	int nr;
	printf("Enter the number of records to be created ");
	scanf("%d",&nr);
	for(i=0;i<nr;i++)
		{
			printf("Student %d \n",co+1);
			printf("Enter the student name ");
			scanf("%s",p->name);
			printf("Enter the student prn ");
			scanf("%d",&p->prn);
			printf("Enter the percentage of student ");
			scanf("%f",&p->percent);
			printf("The new structure record is created\n");
			p++;
			co++;
		}
}
void insert(struct student *p)
{
	int nr;
	printf("Enter the number of records to be inserted ");
	scanf("%d",&nr);
	for(i=0;i<nr;i++)
		{
			printf("Student %d \n",co+1);
			printf("Enter the student name ");
			scanf("%s",(p+co)->name);
			printf("Enter the student prn ");
			scanf("%d",&(p+co)->prn);
			printf("Enter the percentage of student ");
			scanf("%f",&(p+co)->percent);
			printf("The structure record is inserted\n");
			co++;
		}
}
void modify(struct student *p)
{
	int n,cho;
	int che=0;
	printf("Enter the prn of structure record to be modified ");
	scanf("%d",&n);
	for(i=0;i<co;i++)
	{
		if((p+i)->prn==n)
	    {
	    	printf("Enter 1 to modify name\n2 to modify average\n3 to modify both name and average. ");
				scanf("%d",&cho);
				switch(cho)
				{
					case 1:
						{
							printf("Enter the modified name ");
							scanf("%s",(p+i)->name);
							che++;
							break;
						}
					case 2:
						{
							printf("Enter the modified average ");
							scanf("%f",&(p+i)->percent);
							che++;
							break;
						}
					case 3:
						{
							printf("Enter the modified name ");
							scanf("%s",(p+i)->name);
							printf("Enter the modified average ");
							scanf("%f",&(p+i)->percent);
							che++;
							break;
						}
					default : 
					printf("Wrong choice ");
				}
		}
	}
	if(che!=0)
	    printf("The record has been modified ");
	else
	    printf("No record exists ");
}
void del(struct student *p)
{
	int n;
	int che=0;
	printf("Enter the prn of structure record to be deleted ");
	fflush(stdin);
	scanf("%d",&n);
	for(i=0;i<co;i++)
	{
		if((p+i)->prn==n)
		{
			while(i<co)
			{
				p[i]=p[i+1];
				i++;
			}
			printf("The given record is deleted ");
			che++;
			co--;
		}
	}
	if(che==0)
	printf("No matching record found");	
}
void display(struct student *p)
{
	printf("\n");
	for(i=0;i<co;i++)
	{
		printf("Student %d:\n",i+1);
		printf("Name : %s\t",(p+i)->name);
		printf("PRN : %d\t",(p+i)->prn);
		printf("Percent : %f\t",(p+i)->percent);
		printf("\n");
	}	
}
	

