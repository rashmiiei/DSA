#include <stdio.h>
#include <stdlib.h>

//function signatures
void add_end();
void add_begin();
void print_list();
int length_list();
void delete_first();
void delete_end();
void delete_any();


//node structure
struct node
{
    int data;
    struct node *link;
};

struct node *root;

void add_end()
{
    struct node *temp, *p;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("enter node data : ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    p =  root;
    while(p->link != NULL)
    {
        p = p->link;
    }
    
    p->link = temp;
}

void add_after()
{
	struct node *temp, *p;
	int loc, len, i=1;
	
    printf("enter the location : ");
	scanf("%d", &loc);
	
	len = length_list();
	
	if(loc > len)
	{
		printf("Invalid location \n");
		printf("currently list is having %d nodes", len);
	}
	else
	{
		p = root;
		while(i < loc)
		{
			p = p->link;
			i++;
		}
		temp = (struct node*)malloc(sizeof(struct node));
		printf("enter node data : ");
		scanf("%d", &temp->data);
		temp->link = NULL;
		
		temp->link = p->link;
		p->link = temp;
	}	
	
}

void add_begin()
{
    struct node *temp, *p;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("enter node data : ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    
    if(root == NULL)
    {
        root = temp;
    }
	else
	{
		temp->link = root;
		root = temp;
	}
    
}

//function to delete the first node
void delete_first()
{
	struct node *temp;
	
	//edge case in case the list is empty
	if(root == NULL)
	{
	    printf("list is empty \n");
	}
	//condition in case if there is a first node present
	else
	{
		temp = root;
		root = temp->link;
		temp->link = NULL;
		free(temp);
	}
}

//function to delelet the last node
void delete_end()
{
	struct node *p, *q;
	p = root;
	
	//edge case : if no nodes are present
	if(root == NULL)
	{
	    printf("list is empty \n");
	}
	//edge case: if only one node is present
	else if(root->link == NULL)
	{
	    free(root);
	    root = NULL;
	}
	//if more than one nodes are present
	else 
	{
	    while (p->link->link != NULL)
	    {
		    p = p->link;
		}	    
	    q = p->link;
	    p->link = NULL;
	    free(q);
	}
}

//Function to delete any node
void delete_any()
{
	int i=1, loc;
	printf("enter the location to delete : ");
	scanf("%d", &loc);
	
	struct node *p, *q;
	p = root;
	while(i<loc-1)
	{
		p = p->link;
		i++;
	}
	q = p->link;
	p->link = q->link;
	q->link = NULL;
	free(q);
}
void print_list()
{
    struct node *temp;
    temp = root;
    
    if(temp == NULL)
    {
        printf("List is empty \n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->link;
        }
    }
    printf("\n");
}

int length_list()
{
    int count = 0;
    struct node *temp;
    temp = root;
    
    if(temp == NULL)
    {
        printf("List is empty \n");
    }
    else
    {
        while(temp != NULL)
        {
            count++;
            temp = temp->link;
        }
    }
    return count;
}

int main()
{
    int choice, len;
    while(1)
    {
        printf("1. add at end \n");
        printf("2. add at after\n");
        printf("3. add at begin \n");
        printf("4. delete first node \n");
        printf("5. delete last node \n");
        printf("6. delete specific node \n");
        printf("7. display all elements \n");
        printf("8. length of the list \n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: add_end();
                    break;

            case 2: add_after();
                    break;

            case 3: add_begin();
                    break;

            case 4: delete_first();
                    break;

            case 5: delete_end();
                    break;

            case 6: delete_any();
                    break;

            case 7: print_list();
                    break;

            case 8: len = length_list();
                    printf("length is %d \n", len);
                    break;

            default: printf("Invalid option. \n");
                     printf("Enter 1 to 8 \n");

        }
        
    }
    return 0;
}

