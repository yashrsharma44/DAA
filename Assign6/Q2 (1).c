#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student
{
	double cgpa;
	char name[20];
	char roll[9];
}stud;

void swap(stud *a, stud *b)
{
	//swap name
	char nm[20];
	strcpy(nm, a->name);
	strcpy(a->name, b->name);
	strcpy(b->name, nm);
	
	//swap roll
	char rl[20];
	strcpy(rl, a->roll);
	strcpy(a->roll, b->roll);
	strcpy(b->roll, rl);
	
	//swap cgpa
	double cg;
	cg = a->cgpa;
	a->cgpa = b->cgpa;
	b->cgpa = cg;
}

void MaxHeapify(stud *A, int n, int i)
{
	int largest = i;
	int l = (2*i)+1;
	int r = (2*i)+2;
	if((l<n) && (A[l].cgpa>A[largest].cgpa))
	{
		largest = l;
	}
	
	if((r<n) && (A[r].cgpa>A[largest].cgpa))
	{
		largest = r;
	}
	if(largest != i)
	{
		
		swap(&A[i], &A[largest]);
		MaxHeapify(A ,n ,largest);
	}
}

void BuildMaxHeap(stud *A, int n)
{
	int i=0;
	for(i=(n/2)-1; i>=0; i--)
	{
		MaxHeapify(A,n,i);
	}

}


int main()
{
	int i;
	printf("Enter the total number of students\n");
	int n;
	
	stud *A;
	A =  (stud *)malloc(n*sizeof(stud));
	
	scanf("%d",&n);
	printf("Enter the Name, Roll, and cgpa\n");
	for(i=0;i<n;i++)
	{
		char B[20],C[9];
		printf("Enter the name\n");
		scanf("%s",B);
		printf("Enter the roll\n");
		scanf("%s",C);
		printf("Enter the cgpa\n");
		scanf("%lf",&A[i].cgpa);
		strcpy(A[i].name , B);
		strcpy(A[i].roll , C);
	}
	BuildMaxHeap(A, n);
	printf("Person with maximum cgpa\n");
	
	printf("Name :%s \n",A[0].name);
	printf("Roll :%s \n",A[0].roll);
	printf("CGPA :%lf \n",A[0].cgpa);
	
}
