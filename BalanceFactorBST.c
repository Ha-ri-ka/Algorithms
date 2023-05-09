#include<stdio.h>
#include<stdlib.h>

struct node
{
int value;
struct node *right;
struct node *left;
};

struct node * getnode(int ele)
{
    struct node * temp=malloc(sizeof(struct node));
    temp->value=ele;
    temp->left=NULL;
    temp->right=NULL;
    return (temp);
}
int max(int a,int b)
{
    return a>b?a:b;
}

int height(struct node*root)
{
    if(root==NULL)
    return 0;
    return 1+max(height(root->left),height(root->right));
}

int BalanceFactor(struct node * root)
{
    int left=height(root->left);
    int right=height(root->right);
    return left-right;
}

void inorder(struct node* temp) 
{
    if(temp)
    {
        inorder(temp->left);
        printf("balance factor of %d is %d\n",temp->value,BalanceFactor(temp));
        inorder(temp->right);
    }
}

struct node*create_bst(struct node*root,int ele)
 {
    if(root==NULL)
    {
        root=getnode(ele);
        return root;
    }
    else
    {
        if (ele < root->value) 
            root->left = create_bst(root->left, ele); 
        else if(ele>root->value) 
            root->right=create_bst(root->right,ele); 
        else 
            printf("duplicates not allowed\n");
    }
    return root;
 }

 void main()
 {
    struct node*root=NULL;
    printf("enter data to start/continue creation of bst,enter -1 to stop\n");
    int ch,ele;
    do
    {
        printf("enter data:");
        scanf("%d",&ele);
        root=create_bst(root,ele);
        printf("enter choice:");
        scanf("%d",&ch);
    }while(ch!=-1);
    printf("the tree created with balance factor is:\n");
    inorder(root);
}
