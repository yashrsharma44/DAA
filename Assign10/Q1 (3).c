#include<stdio.h>
#include<stdlib.h>
//Structure of a Node
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
    char color='R';
}Node;
//Auxilary function to swap RED and BLACK colors
void swap(char *A, char *B)
{
    char C = *A;
    *A = *B;
    *B = C;
}
//Auxilary function to create a Node, and allocate memory
Node *create(int val)
{
    Node* Point = (Node*)malloc(sizeof(struct node));
    Point->left=NULL;
    Point->right = NULL;
    Point->parent= NULL;
    Point->data = val;
    return Point;
}
//Function to perform left-rotation of a node
void rotateLeft(Node *root, Node *pt)
{
    Node *pt_right = pt->right;
    pt->right = pt_right->left;
    
    if (pt->right != NULL)
    {
        pt->right->parent = pt;//Linking pointer with parent
    }
    pt_right->parent = pt->parent;
    
    if(pt->parent == NULL)
    {
        root = pt_right;
    }
    else if(pt == pt->parent->left)
    {
        pt->parent->left = pt_right;
    }
    else
    {
        pt->parent->right = pt_right;
    }
    
    pt_right->left = pt;
    pt->parent = pt_right;
}
//Function to perform right-rotation of a node
void rotateRight(Node *root, Node *pt)
{
    Node *pt_left = pt->left;
    pt->left = pt_left->right;
    
    if(pt->left != NULL)
    {
        pt->left->parent = pt;//Linking 
    }
    pt_left->parent = pt->parent;
    
    if(pt->parent == NULL)
    {
        root = pt_left;
    }
    else if(pt == pt->parent->left)
    {   
        pt->parent->left = pt_left;
    }
    else
    {
        pt->parent->right = pt_left;
    }
    pt_left->right = pt;
    pt->parent = pt_left;
}
//Function for inserting the nodes in a tree
Node* RB-Insert(Node *root,Node *leaf)
{
    if(root==NULL)
    {
        return(leaf);
    }
    else if(leaf->data > root->right)
    {
        root->right = RB-Insert(root->right,value);
        root->right->parent = root;
    }
    else if(leaf->data < root-left)
    {
        root->left = RB-Insert(root->left, value);
        root->left->parent = root;
    }
    return(root);
    
}



//Function to arrange the tree according to RB Trees
void RB-Fixup(Node *root,Node *leaf)
{
    
    while((leaf!=parent) && (leaf->parent->color=='R')&&(leaf->color=='B'))
    {
        Node *parent_pt=leaf->parent;
        Node *gparent_pt = leaf->parent->parent;
        
        if(parent_pt == gparent_pt->left)
        {
            Node *uncle_pt = gparent_pt->right;
            
            if((uncle_pt->color=='R') &&(uncle_pt!=NULL))
            {
                parent_pt->color = 'B';
                uncle_pt->color = 'B';
                gparent_pt->color = 'R';
                leaf = gparent_pt;
            }
            else 
            {
                if(pt==parent_pt->right)
                {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                
                rotateRight(root, gparent_pt);
                swap(parent_pt->color, gparent_pt->color);
                pt = parent_pt;
            }
        }
        else
        {
            Node *uncle_pt = gparent_pt->left;
            
            if((uncle_pt!=NULL)&&(uncle_pt->color=='R'))
            {
                gparent_pt->color = 'R';
                parent_pt->color = 'B';
                uncle_pt->color = 'B';
                pt = gparent_pt;
            }
            else
            {
                if(pt == parent_pt->left)
                {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                
                rotateLeft(root, gparent_pt);
                swap(parent_pt->color, gparent_pt->color);
                pt = parent_pt;
            }
        }
    }
    root->color = 'B';
}
//Function for performing inorder traversal
void inorder(Node *root)
{
    inorder(root->left);
    print(" %d ",root->data);
    inorder(root->right);
}
//Function for inserting a data, and making a RB Tree
void insert(Node *root,int value)
{
    Node *pt = create(value);
    root = RB-Insert(root,pt);
    RB-Fixup(root,pt);
}

//Main function, for demonstration of RB Trees, and printing them in inorder traversal
int main()
{
    int i,n;
    printf("Enter the values to be inserted in the Red Black Tree\n");
    printf("Enter -1 to stop\n");
    scanf("%d",&n);
    Node *root=NULL;
    while(n!=-1)
    {
        insert(root,n);
        printf("Number Inserted %d \n",n);
        scanf("%d",&n);
    }
    
    printf("Values Inserted in RBT are\n");
    inorder(root);
}
