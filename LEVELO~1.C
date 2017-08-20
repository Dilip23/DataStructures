#include<stdio.h>
struct node{
	int data;
	struct node *left;
	struct node*right;
};
typedef struct node Node;
void printLevel(Node* ,int);
void levelOrder(Node*);
int height(Node*);
Node* newnode(int);
void main()
{
	Node *root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	printf("Level Order Traversal: ");
	levelOrder(root);
}
Node* newnode(int data)
{
	Node* newNode=(Node* )malloc(sizeof(Node));
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	return(newNode);
}
void levelOrder(Node* root)
{

	int h=height(root);
	int i;
	for(i=1;i<=h;i++)
		printLevel(root,i);
}
void printLevel(Node* root,int level)
{
	if(root==NULL)
		return;
	if(level==1)
		printf("%d",root->data);
	else if(level>1)
	{
		printLevel(root->left,level-1);
		printLevel(root->right,level-1);
	}
}
int height(Node* root)
{
	if(root==NULL)
		return 0;
	else
	{
		int lh=height(root->left);
		int rh=height(root->right);
		if(lh>rh)
			return(lh+1);
		else
			return(rh+1);
	}
}
