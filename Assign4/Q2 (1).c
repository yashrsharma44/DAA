#include<stdio.h>
#include<stdlib.h>

typedef struct element
{
	int i,j,data;
	struct element *next;
	
	
}Element;

int main()
{
	int n;
	Element *l1=NULL, *current1=NULL, *l2=NULL, *current2=NULL;
	printf("Enter the order of a matrix\n");
	scanf("%d",&n);
	printf("Enter the values of first sparse matrix\n");
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			int a;
			scanf("%d",&a);
			if(a)
			{
				l1 = (Element*)malloc(sizeof(Element));
				l1->data=a;
				l1->i=i;
				l1->j=j;
				l1->next=current1;
				current1 = l1;
				
			}
		}
	}
	
	printf("Enter the values of second sparse matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			int a;
			scanf("%d",&a);
			if(a)
			{
				l2 = (Element*)malloc(sizeof(Element));
				l2->data=a;
				l2->i=i;
				l2->j=j;
				l2->next=current2;
				current2 = l2;
				
			}
		}
	}
	int C[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			C[i][j] = 0;
		}
	}
	Element *p1=current1, *temp=current2;
	while(p1!=NULL)
	{
		Element *p2=temp;
		while(p2!=NULL)
		{
			if(p1->j==p2->i)
			{
				C[p1->i][p2->j] += (p1->data*p2->data);
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	printf("The Multipied Matrix is \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf(" %d ",C[i][j]);
		}
		printf("\n");
	}
	
}
