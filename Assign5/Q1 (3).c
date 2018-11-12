#include<stdio.h>
#include<stdlib.h>

void Exchange(int *p, int *q)
{
	int *a = p;
	p = q;
	q = a;
}

int partition(int *A, int p, int q)
{

	int x=0;
	x = A[p];
	int i=p;
	int j=0;
	for(j=p+1;j<=q;j++)
	{
		if(A[j]<x)
		{
			i+=1;
			int a = A[i];
			A[i] = A[j];
			A[j] = a;
		}
	}
	int a = A[p];
	A[p] = A[i];
	A[i] = a;
	
	return(i);
}

void quicksort(int *A, int p, int q)
{
	if(p<q)
	{
		int r = partition(A,p,q);
		quicksort(A,p,r-1);
		quicksort(A,r+1,q);
	}
}

int main()
{
	int i,j,n;
	printf("Enter the number of values in the array\n");
	scanf("%d",&n);
	int *A;
	A = (int *)malloc(n*sizeof(int));
	printf("Enter the values in the array\n");
	for(i=0;i<n ;i++)
	{
		scanf("%d",&A[i]);
	}
	quicksort(A,0,n-1);
	printf("Sorted array\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	
	
}
