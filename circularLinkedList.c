#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node*head=NULL;
int length(struct Node*p)
{
    int count=0;
    do
    {
        count++;
        p=p->next;
    }
    while(p!=head);
    printf("Length is %d",count);
}
int recurLength(struct Node*p,int flag)
{
    if(p!=head ||flag==0)
       {
           flag=1;
            return recurLength(p->next,flag)+1;
       }
    else
        return 0;
}
void insert(struct Node*p)
{
   int val,i,index;
   struct Node*t;
   t=(struct Node*)malloc(sizeof(struct Node));
   printf("Enter data\n");
   scanf("%d",&val);
   t->data=val;
   t->next=NULL;
   printf("Enter the index number\n");
   scanf("%d",&index);
   if(index<0 ||index>recurLength(head,0))
       {
           printf("Invalid\n");
            return;
       }
   if(index==0)
   {
     if(p==NULL)
     {
        head=t;
        head=head->next;
     }
     else
     {
    while(p->next!=head) p=p->next;
     p->next=t;
     t->next=head;
     head=t;
     }
   }
   else
   {
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
   }
}

void delete(struct Node*p)
{
    int index,i;
    struct Node*q;
    printf("Enter the index for delete\n");
    scanf("%d",&index);
    if(index<0 ||index>recurLength(head,0))
    {
        printf("Invalid Index\n");
        return 0;
    }
    if(index==0)
        {
           if(p==NULL)
           {
               printf("Empty list\n");
               return 0;
           }
           else
           {
               while(p->next!=head)
                    p=p->next;
               head=head->next;
               p->next=head;
           }
        }
        else
        {
            for(i=0;i<index-2;i++)
            {
                p=p->next;
            }
            q=p->next;
            p->next=q->next;
            q->next=NULL;
        }
}
void display(struct Node*p)
{
    do
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    while(p!=head);
}
int main()
{
    int i,n,val,ch;
    struct Node*last,*t;
    head=(struct Node *)malloc(sizeof(struct Node));
    printf("Create circular linked list\nEnter the number of element\n");
    scanf("%d",&n);
    printf("Enter the 1 st number\n");
    scanf("%d",&val);
    head->data=val;
    head->next=head;
    last=head;
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        printf("Enter the number\n");
        scanf("%d",&val);
        t->data=val;
        t->next=last->next;
        last->next=t;
        last=t;
    }
   while(1)
   {
        printf("\n1.display\n2.Insert\n3.Delete\n4.Length using recursion\n5.length\nEnter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
   case 1:
    display(head);
    break;
   case 2:
    insert(head);
    break;
   case 3:
    delete(head);
    break;

   case 4:
    printf("Length is %d",recurLength(head,0));
    break;
   case 5:
    length(head);
    break;


   case 100:
    exit(0);
    default:printf("Invalid Input\n");

    }
   }
    return 0;
}
