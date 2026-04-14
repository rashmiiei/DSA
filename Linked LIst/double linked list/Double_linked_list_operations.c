#include <stdio.h>
#include <stdlib.h>

//function signatures
int length_list();
void display_list();
void append();
void add_at_specific();
void add_at_begin();
void delete_first();
void delete_last();
void delete_specific();

//Node structure
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

//Function definition to calculate the length of the list
int length_list()
{
    int count = 0;
    struct node * temp;
    temp = root;
    
    while(temp != NULL)
    {
        count++;
        temp = temp->right;
    }
    return count;
}

//Function to display all the elements
void display_list()
{
    struct node * temp;
    temp = root;
    
    if(temp == NULL)
    {
        printf("List is empty \n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->right;
        }
        printf("NULL\n");
    }
}

void append()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the node data : ");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;
    
    if(temp == NULL)
    {
        printf("Memory allocation failed \n");
        return;
    }
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;
        
        while(p->right != NULL)
        {
            p = p->right;
        }
        p->right = temp;
        temp->left = p;
    }
}

void add_at_specific()
{
    struct node *temp, *p;
    int loc, len, i=1;
    
    printf("enter the location to add : ");
    scanf("%d", &loc);
    
    len = length_list();
    
    if(loc > len)
    {
        printf("Invalid option \n");
        printf("List has only %d nodes ", len);
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("enter node data : ");
        scanf("%d", &temp->data);
        temp->left = NULL;
        temp->right = NULL;
        
        p = root;
        while(i < loc-1)
        {
            p = p->right;
            i++;
        }
        //Right side connections needs to be made first or else we will lose the node
        temp->right = p->right;
        p->right->left = temp;
        
        //left side connections
        temp->left = p;
        p->right = temp;
    }
}

void add_at_begin()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("enter node data : ");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;
    
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->right = root;
        root->left = temp;
        root = temp;
    }
}

void delete_first()
{
    struct node *temp;
    int len;
    len = length_list();
    
    temp = root;
    //if there are no nodes present
    if(temp == NULL)
    {
        printf("list is empty \n");
    }
    //if there's only one node present in the list
    else if(len == 1)
    {
        root = NULL;
    }
    //if there are more than one node present
    else
    {
        root = temp->right;
        temp->right = NULL;
        root->left = NULL;
    }
}

void delete_last()
{
    struct node *temp, *prev;
    int len;
    len = length_list();
    temp = root;
    //only one node is present
    if(len == 1)
    {
        root = NULL;
    }
    //more than one node present
    else
    {
        while(temp->right != NULL)
        {
            temp = temp->right;
        }
        prev = temp->left;
        prev->right = NULL;
        temp->left = NULL;
    }
}

void delete_specific()
{
    int loc, i;
    struct node *temp, *next;
    
    printf("enter the location : ");
    scanf("%d", &loc);
    //when there is only one node
    if(loc == 1)
    {
        temp = root;
        
        //single node case
        if(temp->right == NULL)
        {
            root = NULL;
        }
        //More than one nodes
        else
        {
            root = temp->right;
            root->left = NULL;
            temp->right = NULL;
        }
        
    }
    //traverse to loc-1
    temp = root;
    while(i < loc-1 && temp->right != NULL)
    {
        temp = temp->right;
        i++;
    }
    
    next = temp->right;
    if(next->right == NULL)
    {
        temp->right = NULL;
    }
    else
    {
        temp->right = next->right;
        next->right->left = temp;
    }
}

int main() 
{
    int choice, len;
    while(1)
    {
        printf("Double linked list operations : \n");
        printf("1. length of the list \n");
        printf("2. display the list  \n");
        printf("3. append the node  \n");
        printf("4. add after a specific node \n");
        printf("5. add at the beginning \n");
        printf("6. delete the first node \n");
        printf("7. delete the last node \n");
		printf("8. delete node at location \n");
        
        printf("Enter a choice : ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1 : len = length_list();
                     printf("Length of the list is %d", len);
                     break;
                 
            case 2 : display_list();
                     break;
                 
            case 3 : append();
                     break;
             
             
            case 4 : add_at_specific();
                     break;
                 
            case 5 : add_at_begin();
                     break; 

            case 6 : delete_first();
                     break;
                 
            case 7 : delete_last();
                     break;

            case 8 : delete_specific();
                     break;
            
            default : printf("Invalid choice. \n"); 
        }
    }
    
    return 0;
}
