#include<stdio.h>
#include<stdlib.h>

struct node{
int info;
struct node *link;
};
void display(struct node *);
struct node* insert(int,struct node *,struct node *);
struct node* insert1(int,struct node *,struct node *);
struct node* insert2(int,struct node *,struct node *);
void delete(struct node *,struct node *,struct node *);
void main()
{
	struct node *first,*second,*last,*temp;
	int flag,del;
	first = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
	first->info=1;
	first->link = second;
	second->info=2;
	second->link=first;
	display(first);
	first = insert(5,first,second);
	printf("\ninsertion from front\n");
	display(first);
	first=insert1(15,first,last);
	printf("\ninsertion from end\n");
	display(first);
	first = insert2(10,first,last);
	printf("\nInsert in between\n");
	display(first);
	printf("\nEnter a no.you want to delete\n");
	scanf("%d",&del);
	temp = first;
	while((temp->info !=del) && (temp != NULL))
	{
		temp = temp->link;

	}
	if(temp == NULL)
	{
		printf("Number doesn't exist\n");
	}
	else
	{
		delete(temp,first,last);
		display(first);
	}
}
void display(struct node *first)
{
	struct node *save;
	save = first;
	do
	{
		printf("%d,",save->info);
		save = save->link;
	}
	while(save!=first);
}

struct node* insert(int x,struct node *first,struct node *last)
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
			new->link=new; 
			return new;
		}
		else
		{
			new->link=first;
			last->link = new;
			return new;
		}
	}
}
struct node* insert1(int x,struct node *first,struct node *last)
{
	struct node *new;
	new= (struct node *)malloc(sizeof(struct node));
	new->info = x;
	new->link = first;
	if(new==NULL)
	{
		printf("overflow"); 
	}
	else
	{
		if(first==NULL)
		{
			new->link = new;
			return new;
		}
		else
		{
			struct node *save;
			save = first;
			do
			{
				save = save->link;
			}
			while(save->link !=first);
			save->link = new;
			last = save->link;
			return first;
		}
	}
}
struct node* insert2(int x,struct node *first,struct node *last)
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
			new->link=new; 
			return new;
		}
		else
		{
			if(new->info <= first->info)
			{
				new->link = first;
				last->link = new;
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
void delete(struct node *x,struct node *first,struct node *last)
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
		while(save !=x && save->link != last)
		{
			pred = save;
			save = save->link;
		}
		
			if(save == first)
			{
				first = first->link;
				last->link = first;
			}
			else if(save == last)
			{
				pred->link = first;
			}
			else
			{
				pred->link = save->link;
			}
			free(save);
	}
}
