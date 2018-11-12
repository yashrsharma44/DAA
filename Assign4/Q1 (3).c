#include<stdio.h>
#include<stdlib.h>

typedef struct element
{
	int i,j,data;
	
	
}Element;

int main()
{
	int n;
	printf("Enter the order of a matrix\n");
	scanf("%d",&n);
	printf("Enter the values of first sparse matrix\n");
	Element *C = (Element*)malloc((n*n)*sizeof(Element));
	int i,k=0,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			int dat;
			scanf("%d",&dat);
			if(dat)
			{
				Element a;
				a.i = i;
				a.j = j;
				a.data = dat;
				C[k] = a;
				k++;
			}
			
		}
	}
	int range1=k;
	
	printf("Enter the values of second sparse matrix\n");
	Element *D = (Element*)malloc((n*n)*sizeof(Element));
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			int dat;
			scanf("%d",&dat);
			if(dat)
			{
				
				D[k].i = i;
				D[k].j = j;
				D[k].data = dat;
				
				k++;
			}
			
		}
	}
	
	int range2=k;
	int max,val=0;
	
	if(range1>=range2)
	{
		max=range1;
		val=1;
		
	}
	else
	{
		max=range2;
		val=2;
			
	}

	int F[n][n];
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			F[i][j]=0;
		}
	}

	k=0;
	int l=0,m=0;
	int min = range1+range2-max;
	int count=0;

		for(m=0;m<max;m++)
		{
			for(l=0;l<min;l++)
			{
				if(C[m].j == D[l].i)
				{
					F[C[m].i][D[l].j] += (C[m].data)*(D[l].data);
					
					
				}
			}
		}
		printf("The Multipied Matrix is \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf(" %d ",F[i][j]);
		}
		printf("\n");
	}
	
	
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
	
}
