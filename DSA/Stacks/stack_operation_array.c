/* Stack operation using array */

#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5 //preprocessor directive

int stack[CAPACITY], top = -1; //global variables

//function signatures
void push(int);
void pop(void);
int peek(void);
void traverse(void);
int isFull(void);
int isEmpty(void);

//Function definition to push the element
void push(int element)
{
    if(isFull())
    {
        printf("Stack overflow \n");
    }
    else
    {
        top++;
        stack[top] = element;
        printf("%d pushed onto the stack \n", element);
    }
}

//Function definition to pop/delete the element
void pop()
{
    if(isEmpty())
    {
        printf("Stack underflow \n");
    }
    else
    {
        int element = stack[top];
        top--;
        printf("%d pushed out of the stack \n", element);
    }
}

//function definition to see the peek element
int peek()
{
    if(isEmpty())
    {
        return 0;
    }
    else
    {
        printf(" peek element is %d \n", stack[top]);
    }
}

//function definition to print all the elements
void traverse()
{
    int i;
    if(isEmpty())
    {
        printf("No element \n");
    }
    else
    {
        printf("stack elements are : ");
        for(i=0; i<=top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
//Function defeinition to check whether stack is full or not
int isFull()
{
    if(top == CAPACITY-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
  
//Function definition to check whether stack is empty or not
int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



int main()
{
    int choice, data;
    while(1)
    {
        printf("1. Push \n");
        printf("2. Pop \n");
        printf("3. Peek \n");
        printf("4. Traverse \n");
        printf("5. Quit \n");
        
        printf("Enter your choice : ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1 : printf("enter the data to be pushed : ");
                     scanf("%d", &data);
                     push(data);
                     break;
                     
            case 2 : pop();
                     break;
                     
            case 3 : peek();
                     break;
                     
            case 4 : traverse();
                     break;
                     
            case 5 : exit(0);
                     break;
                     
            default : printf("Invalid input \n");
            
            
        }
    }
    
    return 0;
}