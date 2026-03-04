// BST tree

#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* insertNode(struct Node* root, int value);
void inorderTraversal(struct Node* root);
void preorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);

int main()
{
	struct Node* root = NULL;
	int choice,value;
	struct Node* result;
	
	while(1)
	{
		printf("\n ***** Binary Search Tree *****\n");
		printf("1. Insert Operation\n");
		printf("2. Inorder Traversal\n");
		printf("3. Preorder Traversal\n");
		printf("4. Postorder Traversal\n");
		printf("5. Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter value to insert:");
				scanf("%d",&value);
				root = insertNode(root,value);
				break;
			
			case 2:
				printf("Inorder Traversal:");
				inorderTraversal(root);
				printf("\n");
				break;
				
			case 3:
				printf("Preorder Traversal:");
				preorderTraversal(root);
				printf("\n");
				break;
				
			case 4:
				printf("Postorder Traversal:");
				postorderTraversal(root);
				printf("\n");
				break;
				
			case 5:
				printf("Exiting program");
				exit(0);
				
			default:
				printf("Invalid choice");
		}
	}	
	return 0;
}
struct Node* insertNode(struct Node* root,int value)
{
	if(root==NULL)
	{
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode -> data = value;
		newNode -> left = newNode -> right = NULL;
		printf("node with %d is inserted\n",value);
		return newNode;
	}
	if(value < root -> data)
		root -> left = insertNode(root -> left,value);
	else if(value > root -> data)
		root -> right = insertNode(root -> right,value);
	else
		printf("Duplicate value %d not allowed in BST\n",value);
	return root;
}
void inorderTraversal(struct Node* root)
{
	if (root != NULL)
	{
		inorderTraversal(root->left);
		printf("%d ", root->data);  // Add space after %d
		inorderTraversal(root->right);
	}
}

void preorderTraversal(struct Node* root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);  // Add space
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void postorderTraversal(struct Node* root)
{
	if (root != NULL)
	{
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		printf("%d ", root->data);  // Add space
	}
}