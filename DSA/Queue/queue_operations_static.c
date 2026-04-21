#include <stdio.h>

#define CAPACITY 5

void insert()
{
	if (CAPACITY == REAR)
	{
		printf("Queue is full \n");
	}
	else
	{
		int element;
		printf("enter the element : ");
		scanf("%d", &element);
		
		queue[rear] = element;
		rear++;
	}
}

void traverse()
{
	if(front == rear)
	{
		printf("Queue is empty \n");
	}
	else
	{
		int i;
		printf("Queue elements : ");
		for(i=front; i<rear; i++)
		{
			printf("%d\n", queue[i]);
		}
	}
}

void delete()
{
	if(front == rear)
	{
		printf("Queue is empty \n");
	}
	else
	{
		int i;
		printf("deleted  element : %d \n", queue[front]);
		for(i=0; i<rear; i++)
		{
			queue[i] = queue[i+1];
		}
		rear--;
	}
}

int main()
{
	while(1)
	{
		printf("To perform operations : ");
		printf("1. Insert element \n");
		printf("2. Delete element \n");
		printf("3. Traverse element \n");
		printf("4. exit \n");
		
		printf("enter the choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1 : insert();
					 break;
					 
			case 2 : delete();
					 break;
			
			case 3 : traverse();
					 break;
			
			case 4 : exit(0);
			
			default : printf("Invalid choice!! \n");
					  printf("Please enter 1 to 4 \n");
					  
		}
	}
	return 0;
}
		
	