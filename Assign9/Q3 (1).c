#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//Function for defining a linked list structure
typedef struct node
{
    int key;
    struct node* left;
    struct node* right;
}Node;
//Function to calculate the height of the tree
int height(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lft = height(root->left);//Recursively calculate the height of the left subtree
    int rit = height(root->right);//Recursively calculate the height of the right subtree
    if(lft>rit)
    {
        return(lft+1);//Increment by one, to include the root
    }
    else
    return(rit+1);//Increment by one, to include the root
}
//Function to create a node, and allocate memory
Node *create(int val)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->left=NULL;
    temp->right=NULL;
    temp->key=val;
    return (temp);
}
//Function to print the inorder traversal
Node *inorder(Node *root)
{
   
    if(root!=NULL)
    {
        Node *left = root->left;
        Node *right = root->right;
        inorder(left);
        printf("%d\n",root->key);
        inorder(right);
    }
}
//Function to insert a node in a given root with value
Node *insert(Node *root, int value)
{
    
    if(root==NULL)
    {
        return create(value);
    }
    if(value > root->key)
    {
       root->right = insert(root->right,value);
    } 
    else if(value < root->key)
    {
        root->left = insert(root->left, value);
    }
    return(root);
}
//Function that returns the 'floored' exponential value of a number, lg(7) returns 2
int lg(int n)
{
    int i=0;
    while(n>1)
    {
        i=i+1;
        n=n/2;
    }
    return i;
}

int main()
{
    int MAX = 100;
    int MIN = 1;
    int n=0,i,j;
    printf("Enter the total number of elements in the binary search tree.");
    int SIZE;
    scanf("%d",&SIZE);
   //Iterate the permutation, SIZE times
    printf("Value Inserted\n");
    printf("-----------------\n");
    srand(time(0));
    for(j=1;j<=SIZE;j++)
    {
         Node *root =NULL;
        for(i=1;i<=SIZE;i++)
        {
            n = (rand() % (MAX-MIN)) + MIN;
            
            printf("%d\n",n);
            root = insert(root,n);
            
        }
        
        printf("-----------------\n");
        int ht = height(root);
        printf("Height %d \n",ht);
        
        //If height is lg(7) + 1 == Height of balanced binary tree
        if(lg(SIZE)+1 == ht)
        {
            printf("Balanced Binary Search Tree\n");
        }
        else
        {
            printf("Non Balanced Binary Search Tree\n");
        }
    }
    
}
