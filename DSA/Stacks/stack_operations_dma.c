/* Stack implementation using dynamic memory allocation */
#include <stdio.h>
#include <stdlib.h>

//function signatures
void push();
void pop();
void traverse();

//Node structure
struct node 
{
    int data;
    struct node * link;
};

struct node *top = NULL;

//function definition to push elements onto the stack
void push()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    
    printf("enter node data : ");
    scanf("%d", &temp->data);
    
    temp->link = top;
    top = temp;
}

//function definition to pop elements from the stack
void pop()
{
    struct node *temp;
    if(temp == NULL)
    {
        printf("No elements to pop \n");
    }
    else
    {
        temp = top;
        printf("elements : %d \n", temp->data);
        
        top = top->link;
        temp->link = NULL;
        
        free(temp);
        
    }
}

//function definition to print all the elements in the stack
void traverse()
{
    struct node *temp;
    if(top == NULL)
    {
        printf("Stack empty \n");
    }
    else
    {
        temp = top;
        while(temp != NULL)
        {
            printf("%d \n", temp->data);
            temp = temp->link;
        }
    }
}

int main() 
{
    int choice;
    while(1)
    {
        printf("1. Push/Insert \n");
        printf("2. Pop/delete \n");
        printf("3. Traverse \n");
        printf("4. Quit \n");
        
        printf("enter a choice : ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1 : push();
                     break;
                     
            case 2 : pop();
                     break;
                     
            case 3 : traverse();
                     break;
                     
            case 4 : exit(0);
                     break;
                     
            default : printf("Invalid choice : \n");
                      printf("Please enter 1 - 4 \n");
          
        }
    }

    return 0;
}