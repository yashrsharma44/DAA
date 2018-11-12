#include <stdio.h>
#include <stdlib.h>

void ex(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}


int toggle=0;

int part(int arr[],int l,int r)
{
	if(l<r)
	{
		int pivot=arr[l];
		int i=l,j;
		for(j=l+1;j<=r;j++)
		{
		
			if(arr[j]<pivot)
			{
				i++;
				ex(arr+i,arr+j);
			}
		}	
		ex(arr+i,arr+l);
		return i;
	}
	
}

void q_sort(int arr[],int l,int r,int k)
{
	if(l==r) return;
	if(l<r)
	{
		int p=part(arr,l,r);
		if(p==k-1) return;
		if(p>k-1) q_sort(arr,l,p-1,k);
		else q_sort(arr,p+1,r,k);
			
	}
	
}

void lacckyuq_sort(int arr[],int l,int r)
{
	if(l==r) return;
	if(l<r)
	{
		if(toggle==0)
		{
			q_sort(arr,l,r,(l+r)/2);
			toggle=1;
			lacckyuq_sort(arr,l,r);	
		}
		else
		{
			toggle=0;	
			int i,min=arr[l],hola=l;
			for(i=l;i<=r;i++)
			{
				if(min>arr[i])
				{
					min=arr[i];
					hola=i;
				}
			}
			ex(&arr[hola],&arr[l]);
			lacckyuq_sort(arr,l,r);
		}
	}
}

int main()
{
	int n;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("Enter the unsorted array:\n");
	int i,a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	lacckyuq_sort(a,0,n-1);
	printf("Sorted array:");
	for(i=0;i<n;i++)
	{
		printf("%d ",*(a+i));
	}
	printf("\n");
	return 0;
}
