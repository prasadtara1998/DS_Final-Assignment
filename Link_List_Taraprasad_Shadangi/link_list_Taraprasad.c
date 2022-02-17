#include<stdio.h>
#include<stdlib.h>

struct node{
int info;
struct node *link;
};
void display(struct node *);
struct node* insert(int,struct node *);
struct node* insert1(int,struct node *);
struct node* insert2(int,struct node *);
void delete(int,struct node *);
int count(struct node *);
void main()
{
	struct node *first,*second;
	int flag;
	first = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
	first->info=1;
	first->link=second;
	second->info=2;
	second->link=NULL;
	display(first);
	first = insert(5,first);
	printf("\ninsertion from front\n");
	display(first);
	first=insert1(15,first);
	printf("\ninsertion from end\n");
	display(first);
	first=insert2(10,first);
	printf("\ninsertion in between\n");
	display(first);
	delete(10,first);
	printf("\nAfter Deletion\n");
	display(first);
	flag = count(first);
	printf("\nTotal nodes present are :%d\n",flag);
	//copy(first);
}
void display(struct node *first)
{
	struct node *save;
	save = first;
	while(save!=NULL)
	{
		printf("%d,",save->info);
		save = save->link;
	}
}
struct node* insert1(int x,struct node *first)
{
	struct node *new;
	new= (struct node *)malloc(sizeof(struct node));
	new->info = x;
	new->link = NULL;
	if(new==NULL)
	{
		printf("overflow"); 
	}
	else
	{
		if(first==NULL)
		{
			return new;
		}
		else
		{
			struct node *save;
			save = first;
			while(save->link !=NULL)
			{
				save = save->link;
			}
			save->link = new;
			return first;
		}
	}
}
struct node* insert2(int x,struct node *first)
{
	struct node *new;
	new= (struct node *)malloc(sizeof(struct node));
	new->info = x;
	if(new==NULL)
	{
		printf("overflow"); 
	}
	else
	{
		if(first==NULL)
		{
			new->link=NULL; 
			return new;
		}
		else
		{
			if(new->info <= first->info)
			{
				new->link = first;
				return new;
			}
			else
			{
				struct node *save;
				save = first;
				while(save->link !=NULL && (new->info >= (save->link)->info))
				{
					save = save->link;
				}
				new->link = save->link;
				save->link = new;
				return first;
			}
		}
	}
}
struct node* insert(int x,struct node *first)
{
	struct node *new;
	new= (struct node *)malloc(sizeof(struct node));
	new->info = x;
	if(new==NULL)
	{
		printf("overflow"); 
	}
	else
	{
		if(first==NULL)
		{
			new->link=NULL; 
			return new;
		}
		else
		{
			new->link=first;
			return new;
		}
	}
}
void delete(int x,struct node *first)
{
	if(first==NULL)
	{
		printf("Underflow\n");
		return ;
	}
	else
	{
		struct node *save,*pred;
		save = first;
		while(save->info !=x && save->link !=NULL)
		{
			pred = save;
			save = save->link;
		}
		
		if(save->info !=x)
		{
			printf("Node not found\n");
			return;
		}
		else
		{
			if(save == first)
			{
				first = first->link;
			}
			else
			{
				pred->link = save->link;
			}
			free(save);
		}
	}
}
int count(struct node *first)
{
	int count=0;
	if(first == NULL)
	{
		return count;
	}
	else
	{
		struct node *save,*pred;
		save = first;
		while(save!=NULL)
		{
			save = save->link;
			count++;
		}
		return count;
	}
}

