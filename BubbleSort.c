#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubble_sort(int arr[],int n)
{
    int i,j;
    for (i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            swap(&arr[j],&arr[j+1]);
        }
    }
}
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}
void main()
{
    int n,arr[n],i,j;
    printf("enter number of elements:");
    scanf("%d",&n);
    printf("enter the elements:");
    for(i=0;i<n;i++)
    {
        printf("a[%d]=",i);
        scanf("%d",&arr[i]);
    }
    printf("array before sorting:");
    display(arr,n);
    printf("\narray after bubble sort:");
    bubble_sort(arr,n);
    display(arr,n);
}
