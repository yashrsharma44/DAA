#include <stdio.h>
#include <stdlib.h>

//Swaps the number
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
//Perform insertion sort
void insertionsort(int arr[],int l,int r)
{
    int i,j,temp;
    for(i=l+1;i<=r;i++)
    {
        temp=arr[i];
        j=i-1;
        while(arr[j]>temp && j>=l)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }   
}
//Select the elements
int Select(int arr[],int left,int right)
{
    if(left==right)   
    {
        //If single element
        return left;
    }
    if(left<right)
    {
       
        int size=right-left+1;
        int i,count=left;
        //Calculate the number of groups, and remaining elements
        int rem=size%5,quo=size/5;
        if(size<5)
        {
            insertionsort(arr,left,right);
            if(rem==1 || rem==2)
            {
                return left;
            }
            else if(rem==3 || rem==4)
            {
                return left+1;
            }
        }
        else
        {
            for(i=left;i<=quo*5-5;i=i+5)
            {
                insertionsort(arr,i,i+4);//Perform insertion sort between ith and i+4th position
                swap(arr+count,arr+i+2);//Swap the median
                count++;
            }
            if(rem!=0)
            {   
                insertionsort(arr,quo*5,quo*5+rem-1);//Perform insertion sort between left over group containing less than 5 elements
                if(rem==1 || rem==2) swap(arr+count,arr+quo*5);
                else if(rem==3 || rem==4) swap(arr+count,arr+quo*5+1);
                count++;
            }
            //Recursively call the array
            Select(arr,left,count-1);   
        }

           
    }
}

int Partition(int arr[],int left,int right,int index)
{
    if(left==right) return arr[left];
    if(left<right)
    {
        int pivot=Select(arr,left,right);
        int k,i=left,j=left;
        swap(arr+left,arr+pivot);//swap the pivot element
        for(j=left;j<=right;j++)
        {
            if(arr[j]<arr[left])
            {
                i++;
                swap(arr+i,arr+j);
            }
        }
        swap(arr+left,arr+i);
       
        if(i==index) return arr[i];
        else if(i>index) Partition(arr,left,i-1,index);
        else if(i<index) Partition(arr,i+1,right,index);   
    }
}   

int main()
{
    int n;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int i,arr[n];
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++) scanf("%d",arr+i);
    int index;
    printf("Enter the value of k\n");
    scanf("%d",&index);
    printf("The kth smallest number is %d\n",Partition (arr,0,n-1,index-1));
    return 0;
}
