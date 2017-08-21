#include<stdio.h>
struct node{
    int data;
    struct node *left,*right;
};
typedef struct node Node;
Node *newnode(int);
void preOrder(Node*);
Node *minValue(Node*);
Node *deleteNode(Node*,int);
void main()
{
    Node *root=newnode(3);
    root->left=newnode(1);
    root->left->right=newnode(2);
    root->right=newnode(8);
    root->right->left=newnode(7);
    root->right->left->left=newnode(5);
    root->right->right=newnode(10);
    root->right->right->left=newnode(9);
    root->right->right->right=newnode(13);
    printf("PreOrder:");
    preOrder(root);
    printf("Deleting 2.\n");
    root=deleteNode(root,2);
    preOrder(root);
    printf("Deleting 7.\n");
    root=deleteNode(root,7);
    preOrder(root);
    printf("Deleting 10");
    root=deleteNode(root,10);
    preOrder(root);

}
Node *newnode(int data)
{
    Node *n=(Node*)malloc(sizeof(Node));
    n->data=data;
    n->left=n->right=NULL;
    return n;
}
void preOrder(Node *root)
{
    if(root==NULL)
    return;
    else
    {
        printf("%d",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
Node *minValue(Node *node)
{
    Node *temp=node;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
Node *deleteNode(Node *root,int item)
{
    if(root==NULL)
        return root;
    if(item<root->data)
        root->left=deleteNode(root->left,item);
    else if(item>root->data)
        root->right=deleteNode(root->right,item);
    else if(root->left==NULL && root->right==NULL)
    {
        Node *temp=minValue(root->right);
        root->data=temp->data;  
        root->right=deleteNode(root->right,temp->data);
        return root;
    }
    else
    {
        if(root->left==NULL)
        {
                Node* k=root->right
                free(root);
                return k;
        }
        else if(root->right==NULL)
        {
                Node*   k=root->left;
                free(root);
                return k;
        }
        
    }
    return root;
    
}