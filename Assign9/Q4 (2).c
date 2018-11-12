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
//Function to find the ancestor of a root
int find(Node *root, int A, int B)
{
//If two nodes are less than/greater than root, then it should have a lowest common ancestor
    if(A<root->key && B<root->key)
    {
        return find(root->left, A, B);
    }
    else if(A>root->key && B>root->key)
    {
        return find(root->right,A,B);
    }
    else//root is the common ancestor
    {
        return (root->key);
    }
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
    
    int A, B;
    printf("Enter the two nodes, whose common ancestor is to be found\n");
    scanf("%d%d",&A,&B);
    int Ancestor = find(root,A,B);
    printf("The Value of the ancestor %d \n",Ancestor);
    
}
