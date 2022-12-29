/* #include<stdio.h>
#include<conio.h>
void quickSort(int a[10], int, int);

void main(){
    int i , j , pivot , a[10], temp , n;

     printf(" Enter size of the Array :");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Array Elements : %d ", i);
        scanf("%d", &a[i]);
    }
    int high ;
    int low ;

    quickSort(a[10], n-1 , 0);

    printf("After sorting elements : ");
    for(int i = 0 ; i < n ; i++){
        printf("%d  ",a[i]);
    }
}
void quickSort(int a[10], int high, int low ){
   int pivot ;
   int temp , i , j ;
   if(low < high){
    pivot = a[low];
    i = low + 1;
    j = high;
    while(i < j){
        while(pivot >= a[i] && i <= high)
        i++;
        while(pivot < a[j]  && j >= low)
            j--;
        if(i < j){
            temp = a[i];
            a[i] = a[j];
            a[j]= temp;
        }
    }
    a[low] = a[j];
    a[j]= pivot;
    quickSort(a,low,j-1);
    quickSort(a,j+1,high);
   }
} */

/* Q2. Write a program that checks whether a string of characters is palindrome
 or not. The function should use a stack library (cststack.h) of stack of
 characters using a static implementation of the stack. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 10
struct stack
{
    int size;
    int top;
    int *arr;
};

int init(struct stack *ptr)
{
    ptr->top = -1;
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow \n ");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Empty");
    }
    else
    {
        printf(" \n Delated element in Stack :  %d  ", ptr->arr[ptr->top]);
        ptr->top--;
    }
}

int pushc(struct stack *ptr, char ch[], int idx)
{
    int i;
    if (isFull(ptr))
    {
        printf("StackOverflow ");
    }
    else
    {
        for (i = 0; i <= idx; i++)
        {
            ptr->arr[++ptr->top] = ch[i];
        }
    }
}

int reverse(struct stack *ptr, char ch[], int idx)
{
    int i = 0;
    if(isEmpty(ptr)){
        return 0;
    }
    else{
        ptr->top=ptr->top-1;
        while(ptr->top != '\0' && i < idx){
          if(ptr->arr[ptr->top]==ch[i]){
            i++;
            ptr->top= ptr->top-1;
            continue;
          }
          else{
            return 0;
          }
        }

    }
    return 1;
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = Max;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    char ch[Max];
    int idx = 0;
    int p;
    printf(" Enter  string : ");
    gets(ch);
    while (ch[idx] != '\0')
    {
        idx++;
    }
    printf(" \n length of string is %d \n ", idx);
    pushc(sp, ch, idx);
    p = reverse(sp, ch,idx);
     if(p!=0){
        printf(" \n it is Palindrome");
     }
     else{
        printf(" \n it is Not Palindrome");
        return 0;
     }
}