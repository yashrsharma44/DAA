#include <stdio.h>
int first=1;
int tempo;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void heapify(int arr[],int i,int size)
{
	int left=2*i,right=2*i+1;
	int min=i;
	if(left<=size && arr[left-1]<arr[i-1]) min=left;
	if(right<=size && arr[right-1]<arr[min-1]) min=right;

	if(min!=i)
	{
		swap(&arr[min-1],&arr[i-1]);
		heapify(arr,min,size);
	}
}

void build_min_heap(int arr[],int size)
{
	int i;
	for(i=size/2;i>=1;i--) heapify(arr,i,size);
}

void count(int arr[],int size)
{
	int i;
	
	if(size<=1) return;

	if(size==2) 
	{
		if(first==1)
		{
			arr[1]=arr[0]+arr[1];
			first=0;
		}			
		
		else arr[1]=2*arr[0]+arr[1];
	}

	build_min_heap(arr,size);


	
	if(size>2)
	{
		if(arr[1]>arr[2])
		{
			
			if(first==1)
			{
				arr[2]=arr[2]+arr[0];
				first=0;
			}
			else arr[2]=arr[2]+2*arr[0];
			swap(&arr[2],&arr[1]);
		} 
		else
		{
			
			if(first==1)
			{
				arr[1]=arr[1]+arr[0];
				first=0;
			}
	
			else arr[1]=arr[1]+2*arr[0];
		}
		count(arr+1,--size);
	}
	
}	



int main()
{
	int n;
	printf("Enter the number of arrays:");
	scanf("%d",&n);
	int arr[n],i;
	for(i=0;i<n;i++)
	{
		printf("Size of row %d:",i+1); 
		scanf("%d",arr+i);
	}
	count(arr,n);
	printf("Optimal cost for merging: %d\n",arr[n-1]);
	return 0;
}
