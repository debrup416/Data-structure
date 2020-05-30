#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node*r;
    struct Node*l;
};
struct Queue
{
  int size;
  int front;
  int rear;
  struct Node **Q;
}*q=NULL;


struct stack
{
    int size;
    int top;
    struct Node **A;
};

void createstk(struct stack*st,int k)
{
    st->size=k;
    st->top=-1;
    st->A=(struct Node**)malloc(st->size*sizeof(struct Node*));
}
void push(struct stack*st,struct Node*x)
{
  st->top++;
  st->A[st->top]=x;
}
struct Node* pop(struct stack*st)
{
    struct Node* x ;
    if(st->top==-1)
         return NULL;
    else
    {
        x=st->A[st->top--];
        return x;
    }
}

int isStackEmpty(struct stack *p)
{
    if(p==NULL)
        return 1;
    else
        return 0;
}

void create(struct Queue*q,int size )
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct Node**)malloc(q->size*sizeof( struct Node*));
}
void enqueue(struct Queue *q,  struct Node* x)
{
    if((q->rear+1)%q->size==q->front)
        return ;
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
struct Node* dequeue(struct Queue*q)
{
    struct Node* x=NULL;
    if(q->front==q->rear)
        return NULL;
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
        return x;
    }
}
int isEmpty( struct Queue q)
{
    return q.front==q.rear;
}

 struct Node*root=NULL;
 void tree()
 {
     struct Node*p,*t;
     int x;
     struct Queue q;
     create(&q,100);
     printf("Enter root value\n");
     scanf("%d",&x);
     root=(struct Node*)malloc(sizeof(struct Node));
     root->data=x;
     root->l=root->r=NULL;
     enqueue(&q,root );
     while(!isEmpty(q))
     {
         p=dequeue(&q);
         printf("Enter left child %d\n",p->data);
         scanf("%d",&x);
        if(x!=-1)
        {
         t=(struct Node*)malloc(sizeof(struct Node));
         t->data=x;
         t->l=t->r=NULL;
         p->l=t;
         enqueue(&q,t);
        }
         printf("Enter right child %d\n",p->data);
         scanf("%d",&x);
        if(x!=-1)
        {
         t=(struct Node*)malloc(sizeof(struct Node));
         t->data=x;
         t->l=t->r=NULL;
         p->r=t;
         enqueue(&q,t);
        }
     }
 }
 void preOrder(struct Node*p)
 {
     if(p)
     {
         printf("%d\t",p->data);
         preOrder(p->l);
         preOrder(p->r);
     }
 }
 void inOrder(struct Node*p)
 {
     if(p)
     {
         inOrder(p->l);
         printf("%d\t",p->data);
         inOrder(p->r);
     }
 }
 void postOrder(struct Node*p)
 {
     if(p)
     {
         postOrder(p->l);
         postOrder(p->r);
         printf("%d\t",p->data);
     }
 }

 void Ipreorder(struct Node *p)
 {
    struct stack st;
      createstk(&st,100);
     while(p||!isStackEmpty(&st))
     {
         if(p)
         {
             printf("%d\t",p->data);
             push(&st,p);
             p=p->l;
         }
         else
         {
             p=pop(&st);
             p=p->r;
         }
     }
 }
void IInorder(struct Node *p)
{
    struct stack st;
 createstk(&st,100);

 while(p || !isStackEmpty(&st))
 {
 if(p)
 {
 push(&st,p);
 p=p->l;
 }
 else
 {
 p=pop(&st);
 printf("%d ",p->data);
 p=p->r;
 }
 }
}
 int sum(struct Node*p)
 {
     int x,y;
     if(p)
     {
         x=sum(p->l);
         y=sum(p->r);
         return x+y+p->data;
     }
     else
     return 0;
 }
 int nodeCount(struct Node*p)
 {
     int x,y;
     if(p)
     {
         x=nodeCount(p->l);
         y=nodeCount(p->r);
         return x+y+1;
     }
     else
     return 0;
 }
  int node2Count(struct Node*p)
 {
     int x,y;
     if(p)
     {
          x=node2Count(p->l);
          y=node2Count(p->r);
         if(p->r &&p->l)
         {
          return x+y+1;
         }
         else
            return x+y;
     }
     else
     return 0;
 }

   int ht(struct Node*p)
 {
     int x,y;
     if(p)
     {
          x=ht(p->l);
          y=ht(p->r);
         if(x>y)
         {
          return x+1;
         }
         else
            return y+1;
     }
     else
     return 0;
 }
int node0Count(struct Node*p)
 {
      if(!p)
        return 0;
      if(!p->l&&!p->r)
        return node0Count(p->l)+node0Count(p->r)+1 ;
      else
        return  node0Count(p->l)+node0Count(p->r);
 }
 int node1Count(struct Node*p)
 {
     if(!p)
        return 0;
      if(!p->l^!p->r)
        return  node1Count(p->l)+node1Count(p->r)+1;
      else
        return  node1Count(p->l)+node1Count(p->r);
       /*
        int x,y;
        if(p==NULL)
            return 0;
        else
        {
            x=node1Count(p->l);
            y=node1Count(p->r);
            if(p->l!=NULL ^ p->r!=NULL)
                return x+y+1;
            else
                return x+y;
        }*/
 }
int main()
{
    tree();
    printf("\npreOrder Traversal\n");
    preOrder(root);
    printf("\nInOrder Traversal\n");
    inOrder(root);
    printf("\npostOrder Traversal\n");
    postOrder(root);

    printf("\nThe sum is %d\n",sum(root));
     printf("\nThe Number of Node is %d: ",nodeCount(root));
     printf("\nNumber of Node having two child is %d: ",node2Count(root) );
    printf("\nHeight is %d: ",ht(root) );
    printf("\nLeaf-Node is %d: ",node0Count(root));
     printf("\nNode having 1 child is %d: ",node1Count(root));

    return 0;
}



