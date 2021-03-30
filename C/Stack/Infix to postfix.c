// this is a infix to postfix algorithm 
// Time complexity: O(N)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack_array
{
    int top;
    int capacity;
    char *arr;
};
struct Stack_array* create_array(int cap)
{
 struct Stack_array *array;
 array=(struct Stack_array*)malloc(sizeof(struct Stack_array));
 array->capacity=cap;
 array->top=-1;
 array->arr=malloc(sizeof(char)*cap);
return(array);
}
void push(struct Stack_array *array,char data)
{
        array->top++;
        array->arr[array->top]=data;
}
char pop(struct Stack_array *array)
{
    char item;
        item=array->arr[array->top];
        array->top-=1;
        return(item);
}
int check_priority(char Q[],int i,struct Stack_array *array)
{
    if(array->arr[array->top]=='('){
     return 0;
     }
  else if(Q[i]=='+')
  {
      if(array->arr[array->top]=='*'||array->arr[array->top]=='/'||array->arr[array->top]=='+')
   return(1);
   else
    return(0);
  }
  else if(Q[i]=='*')
  {
      if(array->arr[array->top]=='*'||array->arr[array->top]=='/')
        return(1);
      else
        return(0);
  }
  else if(Q[i]=='/')
  {
      if(array->arr[array->top]=='/')
        return(1);
      else
        return(0);
  }
  else if(Q[i]=='-')
  {
      if(array->arr[array->top]=='-'||array->arr[array->top]=='+'||array->arr[array->top]=='/'||array->arr[array->top]=='*')
  return(1);
  else
  return(0);
  }
}
void postfix(char Q[],int size,struct Stack_array *array)
{ int i=0,p=0;
    char P[size];
while(array->top!=-1)
{
if(Q[i]>='a'&&Q[i]<='z'||Q[i]>='A'&&Q[i]<='Z')
{
    P[p]=Q[i];
    p++;
}
else if(Q[i]=='(')
 push(array,'(');
else if(Q[i]=='*'||Q[i]=='-'||Q[i]=='/'||Q[i]=='+')
{
if(array->top==0)
{
        push(array,Q[i]);
}
else
{
    while(1)
    {
        if(1==check_priority(Q,i,array))
        {
            P[p]=pop(array);
            p++;
        }
        else
        break;
        }
     push(array,Q[i]);
}
}
else if(Q[i]==')')
{
    while(array->arr[array->top]!='('){
        P[p]=pop(array);
   p++;
    }
    pop(array);
}
i++;
}
printf("infix to postfix\n");
puts(P);
}
int main()
{ char Q[20];
    struct Stack_array *array;
    array=create_array(10);
    printf("enter string");
gets(Q);
Q[strlen(Q)]=')';
push(array,'(');
postfix(Q,strlen(Q),array);
    return 0;
}
// Input: a*(b+c)*d
//Output: abc+*d*
