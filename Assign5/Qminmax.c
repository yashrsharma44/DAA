#include<stdio.h>
#include<stdlib.h>

void Exchange(int *p, int *q)
{
	int *a = p;
	p = q;
	q = a;
}

int Pivot(int *A, int p, int q)
{
	int ran = rand()%(q-p) + p;
	if((q-p)>4)
	{
		int min2=99999;
		int max2=-99999;
		int i=0;
		int max1=A[p];
		int min1=A[p];
		int minind1=0;
		int minind2=0;
		int maxind1=0;
		int maxind2=0;
	
		for(i=p;i<=q;i++)
		{
			if(A[i]<min1)
			{
			
				minind1 = i;
			}
			if(A[i]>max1)
			{
			
				maxind1 = i;
			}
		}
	
		for(i=p;i<=q;i++)
		{
			if(A[i] < min1)
			{
				minind2 = minind1;
				minind1 = i;
			}
			else if((A[i]<min2) && (A[i] > min1))
			{
				minind2 = i;
			}
			if(A[i] > max1)
			{
				maxind2 = maxind1;
				maxind1 = i;
			}
			else if((A[i]>max2) && (A[i] < max1))
			{
				maxind2 = i;
			}
		}
	
		
		while((ran==maxind1) || (ran==minind1) || (ran==maxind2) || (ran==minind2))
		{
			ran=rand()%(q-p) + p;
		}
	}
	
	
	return(ran);
}

int partition(int *A, int p, int q)
{
	// Calculate the random number between p and q
	int ran = Pivot(A,p,q);
	
	//Swap the A[random] and A[p]
	int val = A[ran];
	A[ran] = A[p];
	A[p] = val;
	
	int x = A[p];
	int i=p;
	int j=0;
	
	for(j=p+1;j<=q;j++)
	{
		if(A[j]<x)
		{
			i+=1;
			//swap the elements
			int a = A[i];
			A[i] = A[j];
			A[j] = a;
		}
	}
	//Swap the elements
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
