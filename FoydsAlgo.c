#include<stdio.h>
void display(int n,int mat[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        printf("%d\t",mat[i][j]);
        printf("\n");
    }
}
int min(int a,int b)
{
    return (a<b?a:b);
}

void floyds(int n,int mat[n][n])
{
    int i,j,k;
    int D[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        D[i][j]=mat[i][j];
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                D[i][j]=min(D[i][j],(D[i][k]+D[k][j])); 
            }
        }
    }
    display(n,D);    
}

void main()
{
    int n,i,j;
    printf("enter number of vertices:"); scanf("%d",&n);
    int mat[n][n];
    printf("enter the cost between each pair of vertices,enter -1 if there is no direct path\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("(%d,%d):",i,j);
            scanf("%d",&mat[i][j]);
            if(mat[i][j]==-1)
            mat[i][j]=999;
        }
    }
    printf("weight matrix entered:\n");
    display(n,mat);
    printf("distance matrix:\n");
    floyds(n,mat);
}
