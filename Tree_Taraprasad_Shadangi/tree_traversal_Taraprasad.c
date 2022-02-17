#include<stdio.h>
#include<stdlib.h>

struct node{
	char info;
	struct node *left;
	struct node *right;
};
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
void main()
{
	struct node *a,*b,*c,*d,*e,*f,*g,*t;
	a=(struct node *)malloc(sizeof(struct node));
	b=(struct node *)malloc(sizeof(struct node));
	c=(struct node *)malloc(sizeof(struct node));
	d=(struct node *)malloc(sizeof(struct node));
	e=(struct node *)malloc(sizeof(struct node));
	f=(struct node *)malloc(sizeof(struct node));
	g=(struct node *)malloc(sizeof(struct node));
	
	a->info='A';
	a->left=b;
	a->right=d;

	b->info='B';
	b->left=c;
	b->right=NULL;

	c->info='C';
	c->left=NULL;
	c->right=NULL;

	d->info='D';
	d->left=e;
	d->right=g;

	e->info='E';
	e->left=NULL;
	e->right=f;

	f->info='F';
	f->left=NULL;
	f->right=NULL;

	g->info='G';
	g->left=NULL;
	g->right=NULL;

	printf("Preorder of tree is:\n");
	t = a;
	preorder(t);
	printf("\nInorder of tree is:\n");
	inorder(t);
	printf("\nPostorder of tree is:\n");
	postorder(t);
}

void preorder(struct node *t)
{
	if(t==NULL)
	{
		printf("Empty Tree\n");
	}
	else
	{
		printf("%c",t->info);
		if(t->left!=NULL)
		{
			preorder(t->left);	
		}
		if(t->right!=NULL)
		{
			preorder(t->right);
		}
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
		printf("%c",t->info);
		if(t->right!=NULL)
		{
			inorder(t->right);
		}
	}	
}
void postorder(struct node *t)
{
	if(t==NULL)
	{
		printf("Empty Tree\n");
	}
	else
	{
		if(t->left!=NULL)
		{
			postorder(t->left);	
		}

		if(t->right!=NULL)
		{
			postorder(t->right);
		}
		printf("%c",t->info);
	}	
}
