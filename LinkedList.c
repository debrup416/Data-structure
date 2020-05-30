#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *one=NULL;
struct Node *two=NULL;
struct Node *first=NULL;

void reverseListByElement(struct Node*p)
{
    int *A,i=0;
    A=(int*)malloc(recurLength(first)*sizeof(int));
    while(p)
    {
        A[i++]=p->data;
        p=p->next;
    }
    p=first;
    i--;
    while(p)
    {
        p->data=A[i--];
        p=p->next;
    }
}
void reverseListUsingSliding(struct Node*p)
{
    struct Node*q=NULL,*r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
struct Node* reverseUsingRecursion(struct Node*q,struct Node*p)
{
    if(p)
    {
            reverseUsingRecursion(p,p->next);
            p->next=q;
    }
    else
        first=q;

}
void removeDuplicateInSortedList(struct Node *p)
{
    struct Node*q=p->next;
    while(q!=NULL)
    {
        if(q->data!=p->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            q=p->next;
        }
    }
}
void isSorted(struct Node*p)
{
    int flag=1;
    struct Node*q;
    int x=-pow(2,sizeof(int));
    if(p==NULL)
    {
        printf("No element present\n");
        return;
    }
    else
    {
        while(p)
        {
            if(p->data<x)
                {
                    flag=0;
                    printf("Not sorted\n");
                    return ;
                }
            x=p->data;
            p=p->next;
        }
    }
    if(flag==1)
        printf("Sorted\n");
}
void delete(struct Node*p)
{
    int index,i=0;
    struct Node*q;
    printf("Enter index for deletion\n");
    scanf("%d",&index);
    if(p==NULL ||index>=recurLength(first))
    {
        printf("Not possible\n");
        return ;
    }
    else
    {
        if(index==0)
        {
            first=first->next;
        }
        else
        {
           for(i=0;i<index;i++)
           {
               q=p;
               p=p->next;
           }
           q->next=p->next;
           p->next=NULL;
        }
    }
}
void sortedInsert(struct Node*p)
{
    int val ;
    struct Node*t,*q;
    t=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the number to insert sorted position\n");
    scanf("%d",&val);
    t->data=val;
    t->next=NULL;
   if(p==NULL)
        first=t;
   else
   {
        while(p && p->data<val)
    {
        q=p;
        p=p->next;
    }
   if(p==first)
   {
       t->next=first;
       first=t;
   }
   else
   {
        t->next=q->next;
        q->next=t;
   }
   }

}
void append(struct Node*p)
{
    int val;
    printf("Enter the number\n");
    scanf("%d",&val);
    struct Node*t=(struct Node*)malloc(sizeof(struct Node));
    t->data=val;
    t->next=NULL;
    if(p==NULL)
    {
        first=t;
        p=first;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=t;
    }
}
void insert(struct Node*p)
{
    int val,index,i;
    struct Node*t=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the number and index\n");
    scanf("%d %d",&val,&index);
    t->data=val;
    t->next=NULL;
    if(index<0 ||index>recurLength(p))
        {
            printf("Invalid Index\n");
            return ;
        }
    else
    {
        if(index==0)
        {
            t->next=first;
            first=t;
        }
        else
        {
            for(i=0;i<(index-1);i++)
            {
                p=p->next;
            }
            t->next=p->next;
            p->next=t;
        }
    }

}
void modifiedSearch(struct Node*p)
{
    int key,flag=0;
    struct Node*q;
    printf("Enter the data for searching\n");
    scanf("%d",&key);
    while(p!=NULL)
    {
        if(key==p->data)
        {
          flag=1;
          q->next=p->next;
          p->next=first;
          first=p;
        }
        q=p;
        p=p->next;
    }
      if(flag==1)
        printf("Found\n");
    else
        printf("Not Found\n");
}
void search(struct Node*p)
{
    int key,flag=0;
    printf("Enter the data for searching\n");
    scanf("%d",&key);
    while(p)
    {
        if(key==p->data)
        {
            printf("Found\n");
            flag=1;
            break;
        }
        p=p->next;
    }
    if(flag==0)
        printf("Not Found\n");
}
int recurSearch(struct Node*p,int key)
{
    if(!p)
        return 0;
    if(p->data==key)
           return key;
    else
        return recurSearch(p->next,key);
}
void max(struct Node*p)
{
    int max=p->data;
    while(p)
    {
        if(p->data>max)
            max=p->data;
        p=p->next;
    }
    printf("Maximum value is %d\n",max);
}
int recurMax(struct Node*p)
{
    int x=0;
    if(p==0)
        return 0;
        x=recurMax(p->next);
    return p->data>x?p->data:x;
}
void sum(struct Node*p)
{
    int sum=0;
    while(p)
    {
        sum+=p->data;
        p=p->next;
    }
    printf("The sum is %d\n",sum);
}

int recurSum(struct Node*p)
{
    if(p!=NULL)
        return recurSum(p->next)+p->data;
    else
        return 0;
}
int length(struct Node*p)
{
    int count=0;
     while(p)
    {
        p=p->next;
        count++;
    }
    printf("Length of linked list is %d\n",count);
    return count;
}

int recurLength(struct Node*p)
{
    if(p)
    {
        return recurLength(p->next)+1;
    }
    else
        return 0;
}

void display(struct Node* p)
{
    while(p)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}
void recurDisplay(struct Node*p)
{
        if(p)
        {
             printf("%d\t",p->data);
            return recurDisplay(p->next);
        }
        else
            return ;
}

int main()
{
    int i,val,n,ch;
    struct Node *t,*last;
    printf("Create a linked list first\nEnter the number of element\n");
    scanf("%d",&n);
    printf("Enter 1st element\n");
    scanf("%d",&val);
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=val;
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
         printf("Enter %d element\n",i+1);
         scanf("%d",&val);
         t=(struct Node*)malloc(sizeof(struct Node));
         t->data=val;
         t->next=NULL;
         last->next=t;
         last=t;
    }
    while(1)
    {
    printf("\n1.Display using iteration\n2.Display using Recursion\n3.Length\n4.Length using Recursion\n5.sum\n6.Sum using recursion\n7.maximum\n");
    printf("8.maximum using recursion\n9.search using iteration\n10.search recursively\n11.Modified search\n12.Insert a Number\n13.Append\n");
    printf("14.Insert in sorted position\n15.Delete\n16.isSorted\n17.remove Duplicate In SortedList\n18.Reverse Using Recursion\n");
    printf("19.Reverse Using Slide Pointer\n20.Reverse by element\nEnter your choice\n");
     scanf("%d",&ch);
     switch(ch)
     {
   case 1:
        display(first);
        break;
   case 2:
        recurDisplay(first);
        break;
   case 3:
        length(first);
        break;
   case 4:
        printf("The length of array is %d\n",recurLength(first));
        break;
   case 5:
        sum(first);
        break;
   case 6:
        printf("The sum is %d\n",recurSum(first));
        break;
   case 7:
        max(first);
        break;
   case 8:
        printf("Maximum value is %d\n",recurMax(first));
        break;
   case 9:
        search(first);
        break;
   case 10:
        {
            int key;
            printf("Enter data for search\n");
            scanf("%d",&key);
            if(recurSearch(first,key))
                printf("Found\n");
            else
                printf("Not Found\n");
        }
        break;
   case 11:
        modifiedSearch(first);
        break;
   case 12:
        insert(first);
        break;
   case 13:
        append(first);
        break;
   case 14:
        sortedInsert(first);
        break;
   case 15:
        delete(first);
        break;
   case 16:
        isSorted(first);
        break;
   case 17:
        removeDuplicateInSortedList(first);
        break;
   case 18:
        reverseUsingRecursion(NULL,first);
        break;
   case 19:
       reverseListUsingSliding(first);
       break;
   case 20:
       reverseListByElement(first);
       break;
   case 100:
       exit(0);

    default:printf("Invalid Input\n");
     }
    }
    return 0;
}

     