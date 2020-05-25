#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
struct queue
{
    int data;
    struct queue*next;
}*front=NULL,*rear=NULL;

void enqueue(int val)
{
    struct queue*t=(struct queue*)malloc(sizeof(struct queue));
    t->data=val;
    t->next=NULL;
    if(front==NULL)
    {
        rear=t;
        front=t;
    }
    else
    {
        rear->next=t;
        rear=t;
    }

}

int dequeue()
{
    int x;
    if(front==NULL)
        return 0;
    x=front->data;
    front=front->next;
    return x;
}

int isEmpty( )
{
    if(front==NULL)
        return 1;
   else
        return 0;
}

void BFS(int G[][7],int start,int n)
{
    int i=start,j;
    int visited[7]={0};
    printf("%d\t",i);
    visited[i]=1;
    enqueue(i);

     while(!isEmpty())
     {
         i=dequeue();
         for(j=1;j<n;j++)
         {
             if(G[i][j]==1 && visited[j]==0)
             {
                 printf("%d\t",j);
                 visited[j]=1;
                 enqueue(j);
             }
         }
     }
}

void DFS(int G[][7],int start,int n)
{
    int j;
    static int visit[7]={0};
    if(visit[start]==0)
    {
        printf("%d\t",start);
       visit[start]=1;
    for(j=1;j<n;j++)
    {
        if(visit[j]==0 && G[start][j]==1)
        {
            DFS(G,j,n);
        }
    }
    }
}
int main()
{
        int i,j,n=7;
    int G[7][7]={ {0,0,0,0,0,0,0},
                {0,0,1,1,0,0,0 },
                {0,1,0,0,1,0,0},
                {0,1,0,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0},
               };
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",G[i][j]);
        }
        printf("\n");
    }
    printf("AFTER BFS \n");
     BFS(G,4,7);
    printf("\nAFTER DFS \n");
     DFS(G,4,7);
    return 0;
}
