#include<stdio.h>
#include<stdlib.h>

void displayMatrix(int n,int matrix[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d  ",matrix[i][j]);
        printf("\n");
    }
}

void BFS(int start,int verts,int matrix[verts][verts])
{
    int visited[verts];
    int i,j,vis;
    for(i=0;i<verts;i++)
    visited[i]=0;
    int queue[verts];
    int front=-1,rear=-1;
    rear+=1;
    queue[rear]=start;
    visited[start]=1;
    while(front!=rear)
    {
        front+=1;
        vis=queue[front];
        printf("%d  ",vis);
        for(j=0;j<verts;j++)
        {
            if(matrix[vis][j]==1 && visited[j]!=1)
            {
                queue[++rear]=j;
                visited[j]=1;
            }
        }
    }

}

void main()
{
    int vertices,i,j;
    printf("enter number of vertices:"); scanf("%d",&vertices);
    int matrix[vertices][vertices];
    printf("1 if there is an edge, 0 if there isnt");
    for(i=0;i<vertices;i++)
    {
        for(j=i;j<vertices;j++)
        {
            printf("between %d and %d:",i,j);
            scanf("%d",&matrix[i][j]);
            matrix[j][i]=matrix[i][j];
        }
    }
    displayMatrix(vertices,matrix);
    printf("BFS traversal:\n");
    BFS(0,vertices,matrix);

}
