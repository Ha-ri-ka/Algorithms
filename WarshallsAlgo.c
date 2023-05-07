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

void warshalls(int n,int mat[n][n])
{
    int i,j,k;
    int T[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        T[i][j]=mat[i][j];
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(T[i][k]==1 && T[k][j]==1)
                T[i][j]=1;
            }
        }
    }
    display(n,T);
}

void main()
{
    int n,i,j;
    printf("enter number of vertices:"); scanf("%d",&n);
    int mat[n][n];
    printf("enter the 1 if there is path,0 if there isnt\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            jump:
            printf("(%d,%d):",i,j);
            scanf("%d",&mat[i][j]);
            if(mat[i][j]!=0 && mat[i][j]!=1)
            {
                printf("\ninvalid input,enter again.\n");
                goto jump;
            }
        }
    }
    printf("adjacency matrix entered:\n");
    display(n,mat);
    printf("transitive closure matrix:\n");
    warshalls(n,mat);
}
