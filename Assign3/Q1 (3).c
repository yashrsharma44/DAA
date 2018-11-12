#include<stdio.h>
int main()
{
	int i,j;
	printf("Enter the row and column of matrix1\n");
	int r1,c1;
	scanf("%d%d",&r1,&c1);
	printf("Enter the row and column of matrix2\n");
	int r2,c2;
	scanf("%d%d",&r2,&c2);
	if(c2!=r1)
		{
			printf("The Matrix multiplication is not possible!\n");
			return 0;
		}
	printf("Enter the values of the matrix 1\n");
	int A[r1][c1];
	int B[r2][c2];
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("Enter the %dth row, %dth column\n",(i+1),(j+1));
			scanf("%d",&A[i][j]);
		}
	}
	
	printf("Enter the values of the matrix 2\n");
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("Enter the %dth row, %dth column\n",(i+1),(j+1));
			scanf("%d",&B[i][j]);
		}
	}
	int C[r1][c2];
	
	
	int k=0;
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			int sum = 0;
			for(k=0;k<c2;k++)
			{
				sum = sum + A[i][k] * B[k][j];
			}
			C[i][j] = sum;
		}
	}
	printf("The multiplication matrix is \n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf(" %d ",C[i][j]);
		}
		printf("\n");
	}
}