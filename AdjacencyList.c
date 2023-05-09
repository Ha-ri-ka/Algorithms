#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
void display(int verts,node *head[verts])
{
    int i;
    for(i=0;i<verts;i++)
    {
        node *temp = head[i];
        while (temp)
        {
            if(temp->next!=NULL)
            printf("%d-->", temp->data);
            else
            printf("%d",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void main()
{
    int vertices,edges,i,j,val;
    printf("enter number of vertices:"); 
    scanf("%d",&vertices);
    node *adj_list[vertices];
    node *head,*temp;
    for(i=0;i<vertices;i++)
    {
        printf("enter the vertex:"); 
        scanf("%d",&val);
        printf("enter number of edges to the vertex %d:",val);
        scanf("%d",&edges);
        head=(node*)malloc(sizeof(node));
        head->data=val;
        head->next=NULL;
        temp=head;
        for(j=0;j<edges;j++)
        {
            node *new=(node*)malloc(sizeof(node));
            printf("enter linked vertex:"); 
            scanf("%d",&new->data);
            temp->next=new;
            new->next=NULL;
            temp=new;
        }
        adj_list[i]=head;
    }
    display(vertices,adj_list);
}
