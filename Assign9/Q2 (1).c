#include<stdio.h>
#include<stdlib.h>
//Function for defining a linked list structure
typedef struct node
{
    int key;
    struct node* left;
    struct node* right;
}Node;
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

int main()
{
    int n=0,i;
    printf("Enter the values in the binary search tree.");
    printf("Enter -1 to exit\n");
    i=1;
    Node *root =NULL;
    
    while(n!=-1)
    {
        printf("Enter the %dth value\n",i);
        i++;
        scanf("%d",&n);
        if(n!=-1)
        root = insert(root,n);
        
    }
    //Sorted inorder traversal
    printf("--------------\n");
    inorder(root);
    printf("--------------\n");
}
