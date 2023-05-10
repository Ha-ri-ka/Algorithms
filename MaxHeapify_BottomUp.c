#include<stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
//heapify a subtree with root at index i
//n is total eles
void heapify(int arr[],int n,int i)
{
    int largest=i; //assume that the ele at index i(root) is  largest among root,l,r
    int left=2*i+1; //INDEX bitch INDEX not element u bitchass 
    int right=2*i+2;

    if(left<n && arr[left]>arr[largest])
    largest=left;

    if(right <n && arr[right]>arr[largest])
    largest=right;

    if(largest!=i) //if your assuption is WRONG
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);  //heapify the affected subtree
    }    
}

void displayArry(int n,int array[n])
{
    for(int i=0;i<n;i++)
    {
        printf("%d  ",array[i]);
    }
}

void main()
{
    int n,i,j;
    printf("enter number of nodes in tree:"); 
    scanf("%d",&n);
    int arr[n];
    printf("enter elements:\n");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("tree before heapify:\n");
    displayArry(n,arr);
    printf("\ntree after heapify:\n");

    for(i=n/2-1;i>=0;i--)
    heapify(arr,n,i);

    displayArry(n,arr);
}
