#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *search(struct node *,int);
void inorder(struct node *);
struct node *new(int);
struct node *insert(struct node *,int);
struct node *delete(struct node *,int);
struct node *findmin(struct node *);
void main()
{
	struct node *head=NULL,*t,*y;
	int n,i,x,z;
	printf("Enter total no. you want to insert\n");
	scanf("%d",&n);
	int num[n];
	printf("Enter numbers\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		head = insert(head,num[i]);
	}
	t = head;
	printf("\nInorder of tree is:\n");
	inorder(t);
	
	printf("\nEnter number you want to search\n");
	scanf("%d",&x);
	y = search(head,x);
	if(y!=NULL)
	{
		printf("Found: %d\n",y->data);
	}
	else
	{
		printf("Not found\n");
	}
	printf("\nEnter number you want to delete\n");
	scanf("%d",&z);
	delete(head,z);
	printf("\nInorder of tree is:\n");
	inorder(t);
	
}
struct node *new(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
struct node *insert(struct node *head,int data)
{
	if(head==NULL)
	{
		head = new(data);
		return head;
	}
	else if(data<=head->data)
	{
		head->left =insert(head->left,data);
	}
	else
	{
		head->right =insert(head->right,data);
		return head;
	}
}
void inorder(struct node *t)
{
	if(t==NULL)
	{
		printf("Empty Tree\n");
	}
	else
	{
		if(t->left!=NULL)
		{
			inorder(t->left);	
		}
		printf("%d\t",t->data);
		if(t->right!=NULL)
		{
			inorder(t->right);
		}
	}	
}
struct node *search(struct node *head,int data)
{
	if(head == NULL)
	{
		return NULL;		
	}
	if(data==head->data)
	{
		return head;
	}
	else if(data<head->data)
	{
		return search(head->left,data);
	}
	else
	{
		return search(head->right,data);
	}
}
struct node *findmin(struct node *head)
{
	
	while(head->left!= NULL)
	{
		head = head->left;
		return head;
	}
	
}
struct node *delete(struct node *head,int data)
{
	if(head==NULL)
	{
		return head;
	}
	else if(data < head->data)
	{
		head->left = delete(head->left,data);
	}
	else if(data > head->data)
	{
		head->right = delete(head->right,data);
	}
	else 
	{
		if(head->left == NULL && head->right == NULL)
		{
			free (head);
			head = NULL;
			
		}
		else if(head->left == NULL)
		{
			struct node *temp = head;
			head = head->right;
			free (temp);
			
		}
		else if(head->right == NULL)
		{
			struct node *temp = head;
			head = head->left;
			free (temp);	
		}
		else
		{
			struct node *temp = findmin(head->right);
			head->data = temp->data;
			head->right = delete(head->right,temp->data);
		}
	}
	
	return head;
}
