#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void MaxHeapify(int *A, int n, int i)
{
	int largest = i;
	int l = (2*i)+1;
	int r = (2*i)+2;
	if((l<n) && (A[l]>A[largest]))
	{
		largest = l;
	}
	
	if((r<n) && (A[r]>A[largest]))
	{
		largest = r;
	}
	if(largest != i)
	{
		
		swap(&A[i], &A[largest]);
		MaxHeapify(A ,n ,largest);
	}
}

void BuildMaxHeap(int *A, int n)
{
	int i=0;
	for(i=(n/2)-1; i>=0; i--)
	{
		MaxHeapify(A,n,i);
	}

}


int main()
{
	int i;
	printf("Enter the capacity of array\n");
	int n;
	scanf("%d",&n);
	int *A = (int *)malloc(n*sizeof(int));
	int *B = (int *)malloc(n*sizeof(int));
	printf("Enter the values\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		//Creating two arrays for implementing two different functions
		B[i] = A[i];	
	}
	printf("Array before Build Max Heap\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	BuildMaxHeap(A,n);
	printf("\nArray after Build Max Heap\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	
	printf("\nArray before Max Heapify\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",B[i]);
	}
	MaxHeapify(B,n,0);//Choosing pivot as the first element
	printf("\nArray after Max Heapify\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",B[i]);
	}
	printf("\n");
	
	
}
