#include <stdio.h>
void display(int row, int cols, int mat[row][cols])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

void displayArr(int n, int arr[n])
{
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void knapsack(int capacity, int n, int weights[n + 1], int values[n + 1], int mat[n + 1][capacity + 1])
{
    int i, j,k=0;
    int items[n];
    for (i = 1; i < n + 1; i++)
    {
        for (j = 1; j < capacity + 1; j++)
        {
            if (j - weights[i] < 0)
                mat[i][j] = mat[i - 1][j];
            if (j - weights[i] >= 0)
                mat[i][j] = max(mat[i - 1][j], values[i] + mat[i - 1][j - weights[i]]);
        }
    }
    display(n + 1, capacity + 1, mat);
    int remaining_weight = capacity;
    for (i = n; i >= 1; i--)
    {

        if (mat[i][remaining_weight] != mat[i - 1][remaining_weight])
        {
            items[k] = i;
            k++;
            remaining_weight=capacity-weights[i];
        }
        else
        {
            if(weights[i]<weights[i-1])
            {
                items[k] = i;
                k++;
            }
            else
            {
                items[k] = i-1;
                k++;
                i--;
            }
        }
    }
    for (i = 0; i < k; i++)
        {
            if(items[i]==0)
            continue;
            printf("%d  ", items[i]);
        }
}

void main()
{
    int n, i, j, capacity;
    printf("enter number of items:");
    scanf("%d", &n);
    printf("enter capacity of knapsack:");
    scanf("%d", &capacity);
    int mat[n + 1][capacity + 1];

    for (i = 0; i < n + 1; i++)
        mat[i][0] = 0;

    for (j = 0; j < capacity + 1; j++)
        mat[0][j] = 0;
        
    int weights[n + 1], values[n + 1];
    weights[0] = values[0] = 0;
    printf("enter the weights:");
    for (i = 1; i < n + 1; i++)
    {
        printf("W[%d]=", i);
        scanf("%d", &weights[i]);
    }

    printf("enter the values:");
    for (i = 1; i < n + 1; i++)
    {
        printf("V[%d]=", i);
        scanf("%d", &values[i]);
    }

    printf("\nweights:\n");
    displayArr(n + 1, weights);
    printf("\nvalues:\n");
    displayArr(n + 1, values);
    printf("\nknapsack matrix:\n");
    knapsack(capacity, n, weights, values, mat);
}
