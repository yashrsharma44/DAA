#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void populateArray(int** a, int val, int index, int w) {
	int offset = 0;	
	while (val > 0) {
		int digit = val % 10;
		a[index][w - 1 - (offset++)] = digit;
		val = val / 10;
	}
}


int toDec(int** a, int index, int msdIndex, int lsdIndex) {
	int sum = 0;
	int i;
	int power = 0;
	for (i = lsdIndex; i >= msdIndex; i--)
		sum += a[index][i] * pow(2, power++);
		
	return sum;
}


int** countingSort(int** a, int msdIndex, int lsdIndex, int n, int w) {
	int r = lsdIndex - msdIndex + 1;
	
	
	int maxDecim = pow(2, r);
	
	int* freq = (int*) malloc(sizeof(int)*maxDecim);
	
	
	int i;
	for (i = 0; i < n; i++) {
		int decimalVal = toDec(a, i, msdIndex, lsdIndex);
		freq[decimalVal]++;
	}
	
	int* postSum = (int*) malloc(sizeof(int) * maxDecim);
	postSum[0] = freq[0];
	for (i = 1; i < maxDecim; i++)
		postSum[i] = postSum[i-1] + freq[i];
	
	
	int** aux = (int**) malloc(sizeof(int*)*n);
	for (i = 0; i < n; i++)
		aux[i] = (int*) malloc(sizeof(int)*w);
	
	
	for (i = n-1; i >= 0; i--) {
		int decimVal = toDec(a, i, msdIndex, lsdIndex);
		int index = (postSum[decimVal]--) - 1;
		aux[index] = a[i];
	}
	
	return aux;
}


void print(int* arr, int w) {
	int i;
	for (i = 0; i < w; i++)
		printf("%d", arr[i]);
}


int main() {
	
	int n;
	printf("Enter size of n : \n");
	scanf("%d", &n);
	
	int w, r;
	printf("Enter no. of bits each value has (w) : \n");
	scanf("%d", &w);
	printf("Enter bits according to which it will be sorted (r) : \n");
	scanf("%d", &r);
	
	
	int** a = (int**) malloc(sizeof(int*)*n);
	int i;
	for (i = 0; i < n; i++)
		a[i] = (int*) malloc(sizeof(int)*w);
	
	printf("Enter values : \n");
	for (i = 0; i < n; i++) {
		int val;
		scanf("%d", &val);
		populateArray(a, val, i, w);
	}
	
	int j;	
	for (i = w-r; i >= 0; i -= r) {
		
		a = countingSort(a, i, i+r-1, n, w);
	}
	
	printf("After sorting : \n");
	for (i = 0; i < n; i++) {
		print(a[i], w);
		printf("\n");
	}
}
