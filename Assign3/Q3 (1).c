#include<stdio.h>
#include<stdlib.h>

int** Allocate(int row)
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
	c=Allocate(row);
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

int** Sub(int **a,int **b,int row)
{
	int **c;
	c=Allocate(row);
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<row;j++)
		{
			c[i][j]=a[i][j]-b[i][j];
		}
	}
	return c;
}

int** Mul(int** a,int **b,int row)
{
	int i,j;
	int** c=Allocate(row);
	if(row==1)
	{
		c[0][0]=a[0][0]*b[0][0];
		return c;
	}
	else
	{
		int r=row/2;
		int** a00=Allocate(r);	
		int** a01=Allocate(r);
		int** a10=Allocate(r);
		int** a11=Allocate(r);
		int** b00=Allocate(r);	
		int** b01=Allocate(r);
		int** b10=Allocate(r);
		int** b11=Allocate(r);

		for(i=0;i<r;i++)
		{
			for(j=0;j<r;j++)
			{
				a00[i][j]=a[i][j];
				a01[i][j]=a[i][j+r];
				a10[i][j]=a[i+r][j];
				a11[i][j]=a[i+r][j+r];

				
				b00[i][j]=b[i][j];
				b01[i][j]=b[i][j+r];
				b10[i][j]=b[i+r][j];
				b11[i][j]=b[i+r][j+r];
			}
		}

		
		int**p1=Mul(a00,Sub(b01,b11,r),r);
		int**p2=Mul(Add(a00,a01,r),b11,r);
		int**p3=Mul(Add(a10,a11,r),b00,r);
		int**p4=Mul(a11,Sub(b10,b00,r),r);
		int**p5=Mul(Add(a00,a11,r),Add(b00,b11,r),r);
		int**p6=Mul(Sub(a01,a11,r),Add(b10,b11,r),r);
		int**p7=Mul(Sub(a00,a10,r),Add(b00,b01,r),r);


		int **c00=Add(Sub(Add(p5,p4,r),p2,r),p6,r);	
		int **c01=Add(p1,p2,r);
		int **c10=Add(p3,p4,r);
		int **c11=Sub(Sub(Add(p5,p1,r),p3,r),p7,r);
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
	A=Allocate(n);
	B=Allocate(n);
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

	int** C=Mul(A,B,n);
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