#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node*left;
    struct Node*right;
};
struct Node*root=NULL;
void insert()
{
    int key;
    struct Node*p=(struct Node*)malloc(sizeof(struct Node));
    struct Node*r,*t=root;
    printf("Enter the value\n");
    scanf("%d",&key);
    p->data=key;
    p->left=NULL;
    p->right=NULL;
    if(root==NULL)
    {
        root=p;
        return;
    }
    else
    {
        while(t)
        {
            r=t;
            if(key<t->data)
                t=t->left;
            else if(key>t->data)
                t=t->right;
            else
            {
             printf("Already exist\n");
             return ;
            }
        }
        if(key>r->data)
            r->right=p;
        else
            r->left=p;
    }
    return p;
}
void search( )
{
    int key,flag=0;
    struct Node*p=(struct Node*)malloc(sizeof(struct Node));
    struct Node*r,*t=root;
    printf("Enter the value\n");
    scanf("%d",&key);
    p->data=key;
    p->left=NULL;
    p->right=NULL;
        while(t)
        {
            if(key==t->data)
                {
                    flag=1;
                    break;
                }
            else if(key>t->data)
                t=t->right;
            else
                t=t->left;

        }
        if(flag==1)
            printf("Found\n");
        else
            printf("Not Found\n");
}
void inOrder(struct Node*p)
{
    if(p)
    {
        inOrder(p->left);
        printf("%d\t",p->data);
        inOrder(p->right);

    }
}
void preOrder(struct Node*p)
{
    if(p)
    {
        printf("%d\t",p->data);
        preOrder(p->left);
        preOrder(p->right);

    }
}
void postOrder(struct Node*p)
{
    if(p)
    {
        postOrder(p->left);
        postOrder(p->right);
        printf("%d\t",p->data);
    }
}

struct Node *Rinsert( struct Node*p,int key)
{
    struct Node*t=NULL;
    if(p==NULL)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=key;
        t->right=t->left=NULL;
        return t;
    }
    if(key<p->data)
        p->left=Rinsert(p->left,key);
    else if(key>p->data)
        p->right=Rinsert(p->right,key);
    return p;
};
int Height(struct Node*p)
{
    int x,y;
    if(p==NULL)
        return 0;
    x=Height(p->left);
    y=Height(p->right);
    return x>y?x+1:y+1;
}
struct Node*Inpre(struct Node*p)
{
    while(p && p->right!=NULL)
        p=p->right;
    return p;
};
struct Node* InSucc(struct Node*p)
{
     while(p && p->left!=NULL)
        p=p->left;
    return p;
};

struct Node* Delete(struct Node*p,int key)
{
    struct Node*q;
    if(p==NULL)
         return NULL;
    if(p->left==NULL && p->right==NULL)
    {
        if(p==root)
            root=NULL;
            free(p);
        return NULL;
    }
    if(key<p->data)
        p->left=Delete(p->left,key);
    else if(key>p->data)
        p->right=Delete(p->right,key);
    else
    {
        if(Height(p->left)>Height(p->right))
        {
            q=Inpre(p->left);
            p->data=q->data;
            p->left=Delete(p->left,q->data);
        }
        else
        {
            q=InSucc(p->right);
            p->data=q->data;
            p->right=Delete(p->right,q->data);
        }
    }
    return p;
};
int main()
{
    int n,i,ch;
    printf("Create a Binary Tree\nEnter the number of element\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       insert();
    }
    while(1)
    {
        printf("\n1.Insert Using Recursion\n2.Delete\n3.PREORDER\n4.INORDER\n5.POSTORDER\n6.Search\n7.Insert\n100.Exit\nEnter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        {
        int key;
        printf("Enter the value\n");  //work if already root is present
        scanf("%d",&key);             //Or first call to make root
        Rinsert(root,key);            // root=Rinsert(root,key)
        }
        break;
    case 4:
        inOrder(root);
        break;
    case 3:
        preOrder(root);
        break;
    case 5:
        postOrder(root);
        break;
    case 6:
        search();
        break;
    case 2:
        {
            int key;
            printf("Enter the element to delete\n");
            scanf("%d",&key);
            Delete(root,key);
         }
        break;
    case 7:
        insert();
        break;
    default:printf("InValid Input\n");
        break;
    case 100:
        exit(0);
    }
}

    return 0;
}
