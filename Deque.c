//Write a program to implement following operations on Deque: 1. Insert at front 2. Insert at rear 3. Delete from front 4. Delete from rear.
#include<stdio.h>
main()
{
	int n,ch,front=-1,rear =-1,o,i;
	printf("Enter the size of the queue ");
	scanf("%d",&n);
	static int arr[10];
	printf("Enter \n1. Insert at front end of queue \n2. Insert at rear end of queue \n3. Delete from front end of queue \n4. Delete from rear end of queue \n5. Display the deque ");
	check:
	printf("\nEnter your choice ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			{
				if(!((front==0 && rear == n-1)|| (front==rear+1)))
				{
				if(front == -1)
				{
				front = 0;
				rear = 0;
			    }
			    else if(front == 0)
			    front = n-1;
				else 
				front--;
				printf("Enter the element to be inserted ");
				scanf("%d",&arr[front]);
				printf("The element is inserted at the front end.");
				}
				else
				printf("The queue is full ");
				break;
			}
		case 2:
		    {
		    if(!((front==0 && rear == n-1)|| (front==rear+1)))
				{
				if(rear == n-1)
				rear = 0;
				else if(rear==-1 && front ==-1)
				{
					rear++;
					front++;
				}
				else
				rear++;
				printf("Enter the element to be inserted ");
				scanf("%d",&arr[rear]);
				printf("The element is inserted at the rear end.");
				}
			else
			printf("The queue is full ");
			break;		    	
			}
		case 3:
		{
			if(front!=-1)
			{
				if(front==rear)
				{
					front = -1;
					rear = -1;
					printf("The queue is now empty ");
					break;
				}
				else if(front==n-1)
				{
					arr[front]=0;
					front = 0;
				}				
				else
				{
					arr[front]=0;
				    front++;
			    }
			    printf("The element is deleted from front end.");
			}
			else
			printf("The queue is empty ");
			break;
		}
		case 4:
		{
			if(front!=-1)
			{
				if(front==rear)
				{
					front = -1;
					rear = -1;
					printf("The queue is now empty ");
					break;
				}
				else if(rear==0)
				{
					arr[rear]=0;
					rear=n-1;
				}
				else
				{
					arr[rear]=0;
					rear--;
				}
			    printf("The element is  deleted from rear end.");
			}
			else
			printf("The queue is empty ");
			break;
		}
		case 5:
			{
				if(front!=-1)
				{
					printf("The queue is :");
				    for(i=0;i<n;i++)
				    printf("\t%d",arr[i]);
				    printf("\nThe front is at position : %d",front);
				    printf("\nThe rear is at position : %d",rear);
				}
			    else 
			        printf("The queue is empty");
				break;	
			}
			default:
				printf("Wrong choice ");
			}
	printf("\nEnter 1 if you want to continue, else 0 ");
	scanf("%d",&o);
	if(o==1)
	goto check;
}

