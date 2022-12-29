// slip no 3 
/* Q1. Sort a random array of n integers (accept the value of n from user) in 
 ascending order by using insertion sort algorithm. */
/* #include<stdio.h>
int main(){
    int n ;
    printf("Enter Size of the array : ");
    scanf("%d",&n);
    int arr[10];
    for(int i = 0; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 1 ; i < n ; i++){
        int j = i-1;
        int temp = arr[i];
        while(j >= 0 && temp <= arr[j]){
             arr[j+1] = arr[j];     
            j = j-1;    
        }
        arr[j+1] = temp;
    }
    for (int i = 0; i < n; i++)  
        printf("%d ", arr[i]);  
} */


// slip no 3 Q - B 
// Q2. Write a C program to evaluate postfix expression.
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int stack[20];
int top = -1;
void push(int x){
    stack[++top] = x;
}
int pop(){
    return stack[top--];
}
 int main(){
  char exp[20];
  char *temp;
  int n1, n2,n3,num;
  printf("Enter Postfix Expression whiout space : ");
  scanf("%s",exp);
  temp = exp;
  while(*temp  != '\0'){
    if(isdigit(*temp)){
        num = *temp - 48 ; // convert exp string into interger 
        push(num);
    }
    else{
        n1 = pop();
        n2 = pop();
        switch(*temp){
            case '+':{
                n3 = n2+n1;
                break;
            }
            case '-':{
                n3 = n2-n1;
                break;
            }
            case '*':{
                n3 = n2*n1;
                break;
            }
            case '/':{
                n3 = n2/n1;
                break;
            }
        }
        push(n3);
    }
    temp++;
  }
  
  printf(" Result of postfix exp %s = %d \n ",exp,pop());
  return 0;
  
 }