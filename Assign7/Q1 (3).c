#include<stdio.h>
#include<stdlib.h>

void countSort(int *A, int *C, int n, int k)
{
	
	k +=1;
	int B[k];
	int i=0;
	for(i=0;i<k;i++)
	{	
		B[i]=0;
	}
	int j=0;

	for(j=0;j<n;j++)
	{
		B[A[j]] += 1;
	}
	
	
	for(i=2;i<k;i++)
	{
		B[i] += B[i-1];
	}
	

	for(j=n-1;j>=0;j--)
	{
		C[B[A[j]]-1] = A[j];
		B[A[j]] -= 1;
	}

	

}

int main()
{	
	int n,k,max=0;
	int i;
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	int *A = (int *)malloc(n*sizeof(int));
	
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	for(i=0;i<n;i++)
	{
		if(max < A[i])
		{
			max = A[i];
		}
	}
	k = max;
	int *B = (int *)malloc(n*sizeof(int));
	countSort(A,B,n,k);
	for(i=0;i<n;i++)
	{
		printf("%d ",B[i]);
	}
	
}
