/* #include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start;

void display(struct node *temp)
{

    if (temp != NULL)
    {
        printf("Linklist is : ");
        while (temp != NULL)
        {
            printf("%d-> ", temp->data);
            temp = temp->next;
        }
    }
    else
    {
        printf("List is empty");
    }
}

void create(struct node *temp)
{

    struct node *start;
    start = (struct node *)malloc(sizeof(struct node));
    struct node *newNode_2;
    newNode_2 = (struct node *)malloc(sizeof(struct node));
    struct node *newNode_3;
    newNode_3 = (struct node *)malloc(sizeof(struct node));
    struct node *newNode_4;
    newNode_4 = (struct node *)malloc(sizeof(struct node));
    start->next = newNode_2;
    newNode_2->next = newNode_3;
    newNode_3->next = newNode_4;
    newNode_4->next = NULL;

    temp = (struct node *)malloc(sizeof(struct node));
    temp = start;

    while (temp != NULL)
    {
        printf("Enter data in Node:  ");
        scanf("%d", &temp->data);
        temp = temp->next;
    }
    // parat temp = head karun takaych karan ki ata ouput karayach ahe

    display(start);
}

void delate(struct node *temp)
{
    create(start);
    struct node *p;
    int pos;
    printf(" \n Enter Position You can delate Node : ");
    scanf("%d", &pos);
    int nodeIdx = -1;
    temp = start;
    if (pos == 1)
    {
        start = start->next;
        free(temp);
        printf("\n Node Delated ");
    }
    display(start);
}

int main()
{

    int item;
    start = NULL;
    while (1)
    {
        int op;
        printf(" \n 1.Create()  ");
        printf(" \n 2.Display() ");
        printf(" \n 3.Delate() \n");
        printf(" \n Which Opertion You can Do : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
        {
            create(start);
            break;
        }
        case 2:
        {
            // insert();
            break;
        }
        case 3:
        {
            delate(start);
            break;
        }
        case 4:
        {
            // display();
            break;
        }
        default:
        {
            printf("Choose Opartion  form 1 to 4 ");
        }
        }
    }
    return 0;
} */



// Sllip no - 8  (b)
/* Q2. Write a program that checks whether a string of characters is palindrome
 or not. The function should use a stack_arr library (cststack.h) of stack_arr of
 characters using a static implementation of the stack_arr.  */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 5

int top = -1;
int stack_arr[MAX];
void push();
void pop();
void display();
int main()
{
    int ch;

    while (1)
    {
        int op;
        printf("   Stack Manu  \n ");
        printf("\n  1.Push() \n ");
        printf(" 2.Pop() \n ");
        printf(" 3.display() \n ");
        printf(" \n Which opertion u can do ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        default:
        {
            printf("Enter 1 to 3 ");
            break;
        }
        }
    }
    push();
    pop();
    display();
    return 0;
}
void push()
{
    int val;
    if (top == MAX - 1)
    {
        printf(" Stack is Full ....\n ");
    }
    else
    {
        printf("Enter Number to Push in  stack : \n ");
        scanf("%d", &val);
        top = top + 1;
        stack_arr[top] = val;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("Stack is Empty \n");
    }
    else
    {
        printf("  Delated elements is %d \n", stack_arr[top]);
        top = top - 1;
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty \n");
    }
    else
    {
        printf(" ...... Elements in Stacks ......\n ");
        for (int i = top; i >= 0; i--)
        {
            printf(" %d  ", stack_arr[i]);
        }
    }
    printf("\n");
}