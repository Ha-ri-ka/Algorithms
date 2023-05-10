//very lazy and unclear code. needs improvement.
#include<stdio.h>
void DFS(int start,int visited[],int arr[4][4])
{
    printf("%d  ",start);
    visited[start]=1;
    for(int i=0;i<4;i++)
    {
        if(arr[start][i]==1 && visited[i]!=1)
        DFS(i,visited,arr);
    }

}

void main()
{
   int verts,i,j,start;
   printf("enter number of vertices:"); scanf("%d",&verts);
   int arr[verts][verts],visited[verts];
   printf("enter elements:");
   for(i=0;i<verts;i++)
   {
       for(j=0;j<verts;j++)
       scanf("%d", &arr[i][j]);
       visited[i]=0;
   }
   printf("enter start node:"); scanf("%d",&start);
   printf("DFS traversal of this thang:\n");
   DFS(start,visited,arr);
}
