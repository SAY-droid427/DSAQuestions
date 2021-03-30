// this is a prim's algorithm
//time complexity: O(ElogV)
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int no;
    int PI;
    int Key;
    struct node *next;
};
struct Graph
{
    int V;
    int E;
};
struct Graph* create_graph(int V,int E)
{
 struct Graph *G;
 G=malloc(sizeof(struct Graph));
 G->E=E;
 G->V=V;
 return(G);
}
int less_priority(struct node *Start)
{
    int less=0,no=0;
    less=Start->Key;
    no=Start->no;
    Start=Start->next;
    while(Start!=NULL)
    {
        if(Start->Key<less)
        {
            less=Start->Key;
            no=Start->no;
        }
        Start=Start->next;
    }
    return(no);
}
void insertion(struct node **Start,int no)
{
    struct node *temp,*t;;
    temp=malloc(sizeof(struct node));
    temp->no=no;
    temp->PI=0;
    temp->Key=1000;
    temp->next=NULL;
    if(*Start==NULL)
    { temp->Key=0;
        *Start=temp;
       }
    else
    {
        t=*Start;
        while(t->next!=NULL)
            t=t->next;
        t->next=temp;
    }
}
struct node* deletion(struct node **Start)
{ int check=0;
struct node *temp,*t,*pre;
    temp=malloc(sizeof(struct node));
    check=less_priority(*Start);
    if((*Start)->no==check)
    {
        temp->no=(*Start)->no;
        temp->Key=(*Start)->Key;
        temp->PI=(*Start)->PI;
        temp->next=NULL;
        t=*Start;
        *Start=(*Start)->next;
        free(t);
    }
    else
    { t=*Start;
        while(t->next!=NULL)
        {
            pre=t;
            t=t->next;
            if(check==t->no)
                break;
            }
            temp->no=t->no;
            temp->PI=t->PI;
            temp->Key=t->Key;
            temp->next=NULL;
            pre->next=t->next;
            free(t);
    }
    return(temp);
}
int check_in_q(int n,struct node *Start)
{
   while(Start!=NULL)
   {
       if(Start->no==n)
        return(1);
       Start=Start->next;
   }
   return(0);
}
int get_n(int n,struct node *Start)
{ int Key;
    while(Start!=NULL)
    {
        if(n==Start->no)
        {
            Key=Start->Key;
            break;
        }
        Start=Start->next;
    }
    return(Key);
}
void change(int n,struct node **Start,int Key,int PI)
{
    struct node *temp;
    if((*Start)->no==n)
    {
        (*Start)->Key=Key;
        (*Start)->PI=PI;
    }
    else
    {
      temp=*Start;
      while(temp!=NULL)
      {
          if(temp->no==n)
          {
              temp->Key=Key;
              temp->PI=PI;
              break;
          }
          temp=temp->next;
      }
    }
}
void Prims(struct node **Start,struct Graph *G)
{ int e1,i,n,w;
    struct node *temp;
    int t,cost=0;
    while(*Start!=NULL)
    {
    temp=deletion(Start);
    cost+=temp->Key;
    printf("Enter the no. of nodes connected to V%d",temp->no);
    scanf("%d",&e1);
    for(i=0;i<e1;i++)
    {
        printf("enter the node no of v%d and weight",temp->no);
        scanf("%d%d",&n,&w);
        if(1==check_in_q(n,*Start))
        {
            t=get_n(n,*Start);
            if(w<t)
                change(n,Start,w,e1);
        }
    }
    }
    printf("\n Cost=%d",cost);
}
int main()
{
    struct node *Start=NULL;
    struct Graph *G;
    int i,v,e;
    printf("enter vertex and edges");
    scanf("%d %d",&v,&e);
    G=create_graph(v,e);
    for(i=0;i<G->V;i++)
        insertion(&Start,i+1);
    Prims(&Start,G);
    return 0;
}
// Input: 5 6
// 1 2 3
// 1 3 4
// 4 2 6
// 5 2 2
// 2 3 5
//3 5 7

// Output: cost=15
