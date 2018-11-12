#include<stdio.h>
#include<stdlib.h>

int** allocate(int row)
{
	int **c= (int**)malloc(row*sizeof(int*));
	int i;
	for(i=0;i<row;i++)
	{
		c[i]=(int*)malloc(row*sizeof(int*));
	}
	return c;
}

int** Add(int **a,int **b,int row)
{
	int **c;
	c=allocate(row);
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<row;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	return c;
}

int** Multiply(int** a,int **b,int row)
{
	int i,j;
	int** c=allocate(row);
	if(row==1)
	{
		c[0][0]=a[0][0]*b[0][0];
		return c;
	}
	else
	{
		int r=row/2;
		int** p=allocate(r);	
		int** q=allocate(r);
		int** y=allocate(r);
		int** s=allocate(r);
		int** t=allocate(r);	
		int** u=allocate(r);
		int** v=allocate(r);
		int** w=allocate(r);

		for(i=0;i<r;i++)
		{
			for(j=0;j<r;j++)
			{
				p[i][j]=a[i][j];
				q[i][j]=a[i][j+r];
				y[i][j]=a[i+r][j];
				s[i][j]=a[i+r][j+r];

				
				t[i][j]=b[i][j];
				u[i][j]=b[i][j+r];
				v[i][j]=b[i+r][j];
				w[i][j]=b[i+r][j+r];
			}
		}
		int **c00=Add(Multiply(p,t,r),Multiply(q,v,r),r);	
		int **c01=Add(Multiply(p,u,r),Multiply(q,w,r),r);
		int **c10=Add(Multiply(y,t,r),Multiply(s,v,r),r);
		int **c11=Add(Multiply(y,u,r),Multiply(s,w,r),r);
		for(i=0;i<r;i++)
		{
			for(j=0;j<r;j++)
			{
				c[i][j]=c00[i][j];
				c[i][j+r]=c01[i][j];
				c[i+r][j]=c10[i][j];
				c[i+r][j+r]=c11[i][j];
			}
		}
	}
	return c;
}

		
	

int main()
{
	int n;
	printf("Enter the dimension of a square matrix");
	scanf("%d",&n);
	int **A,**B;
	A=allocate(n);
	B=allocate(n);
	printf("Enter the elements of first matrix\n");
	int i,j;
	for(i=0;i<n;i++)
	{
		
		
		for(j=0;j<n;j++)
		{
			printf("Enter elements of %dth row and %dth column:",(i+1),(j+1));
			scanf("%d",&A[i][j]);
		}
	}
	printf("Enter the elements of second matrix\n");
	for(i=0;i<n;i++)
	{
		
		for(j=0;j<n;j++)
		{
			printf("Enter elements of %dth row and %dth column:",(i+1),(j+1));
			scanf("%d",&B[i][j]);
		}
	}

	int** C=Multiply(A,B,n);
	printf("Product of 2 matrices are as follow:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",C[i][j]);
		}
		printf("\n");
	}
	return 0;
}