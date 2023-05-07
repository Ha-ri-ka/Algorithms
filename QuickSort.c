#include<stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int L,int U)
{
    int pivot=arr[L];
    int start=L; 
    int end = U;
    while(start<end)
    {
        while(arr[start]<=pivot)
        start++; 
        while(arr[end]>pivot)
        end--; 
        if(start<end)
        swap(&arr[start],&arr[end]);
    }
    swap(&arr[L],&arr[end]); 
    return end; 
}

void quick_sort(int arr[],int L,int U)
{
    int loc;
    if(L<U)
    {
        loc=partition(arr,L,U);
        quick_sort(arr,L,loc-1);
        quick_sort(arr,loc+1,U);
    }
}

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}

void main()
{
    int n,i,j;
    printf("enter number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements:");
    for(i=0;i<n;i++)
    {
        printf("a[%d]=",i);
        scanf("%d",&arr[i]);
    }
    printf("array before sorting:");
    display(arr,n);
    printf("\narray after sort:");
    quick_sort(arr,0,n-1);
    display(arr,n);
}
