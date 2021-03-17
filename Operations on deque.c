#include<stdio.h>
void print(int arr[],int,int,int);
main()
{
	int n,ch,front=-1,rear =-1,o;
	printf("Enter the size of the queue ");
	scanf("%d",&n);
	int arr[n];
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
				if(front == -1 && rear ==-1)
				{
				front = n-1;
			    }
			    else if(front == 0)
			    front = n-1;
				else 
				front--;
				printf("Enter the element to be inserted ");
				scanf("%d",&arr[front]);
				print(arr,front,rear,n);
				}
				else
				printf("The queue is full ");
				break;
			}
		case 2:
		    {
		    if(!((front==0 && rear == n-1)|| (front==rear+1)))
				{
				if(rear == n-1 )
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
				print(arr,front,rear,n);
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
					front = 0;
					print(arr,front,rear,n);
				}				
				else
				{
					front++;
					print(arr,front,rear,n);
				}				
			    break;
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
					rear=n-1;
				    print(arr,front,rear,n);
				}
				else if(rear==-1)
				{
					rear = n-2;
				    print(arr,front,rear,n);
				}				
				else
				{
					rear--;
				    print(arr,front,rear,n);
				}				
			}
			else
			printf("The queue is empty ");
			break;
		}
		case 5:
			{
				print(arr,front,rear,n);
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
void print(int arr[],int front, int rear, int n)
{
	if(front!=-1)
		{
		    printf("The modified queue is: ");
			for(int i = front;i!=rear;)	
			{
				printf("%d\t",arr[i]);
				i++;					
				if(i==n && rear ==-1)
				break;
				else if(i==n)
				i=0;
			}
			if(rear !=-1 )
			printf("%d",arr[rear]);
		}
	else 
		printf("The queue is empty");
}
