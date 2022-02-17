#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node *next;
struct node *prev;
};
void display(struct node *);
struct node* insert(struct node *,int);
struct node* insert1(struct node *,struct node *,struct node *,int);
struct node* insert2(struct node *,struct node *,int);
void delete(struct node *,struct node *,struct node *);
void main()
{
	struct node *first,*second,*head,*last,*temp;
	int del;
	first = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
	
	first->info = 5;
	first->next = second;
	first->prev = 0;

	second->info = 10;
	second->next = 0;
	second->prev = first;

	head = first;
	last = second;
	printf("Nodes Present\n");
	display(head);
	printf("\nInserting from begining\n");
	head = insert(head,1);
	display(head);
	printf("\nInserting from end\n");
	head = insert1(head,last,second,15);
	display(head);
	printf("\nInserting in between\n");
	head = insert2(head,last,0);
	display(head);
	printf("\nEnter a no.you want to delete\n");
	scanf("%d",&del);
	temp = head;
	while((temp->info !=del) && (temp->next != 0))
	{
		temp = temp->next;

	}
	if(temp == 0)
	{
		printf("Number doesn't exist\n");
	}
	else
	{
		delete(temp,head,last);
		display(head);
	}
}
void display(struct node *head)
{
	if(head==0)
	{
		printf("list is empty\n");
	}
	else
	{
		struct node *save;
		save = (struct node *)malloc(sizeof(struct node));
		save = head;
		while(save!=0)
		{
			printf("%d\t",save->info);
			save = save->next;
		}
	}
}
struct node* insert(struct node *head,int x)
{
	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
	new->info = x;
	new->prev = 0;
	if(head==0)
	{
		head->next = 0;
		return new;
	}
	else
	{
		new->next = head;
		return new;
	}
}
struct node* insert1(struct node *head,struct node *last,struct node *second,int x)
{
	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
	new->info = x;
	if(head==0)
	{
		head->prev = 0;
		return new;
	}
	else
	{
			if(second->next == 0)
			{
				second->next = new;
				new->prev = second;
				new->next = 0;
				last = new;
				return head;
			}
			else
			{
				last->next = new;
				new->prev = last;
				new->next = 0;
				last = new;
				return head;
			}
	}
}
struct node* insert2(struct node *head,struct node *last,int x)
{
	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
	new->info=x;
	if(head==0)
	{
		head->next = 0;	
		head->prev = 0;
		return new;
	}
	else
	{
		if(head->info > x)
		{
			new->prev = 0;
			new->next = head;
			return new;
		}
		else
		{
			struct node *save,*temp;
			save = (struct node *)malloc(sizeof(struct node));
			save = head;
			if(x < save->info && save->next!=0)
			{
				temp=save;
				save = save->next;
			}
			if(save->next==0)
			{
				last->next = new;
				new->prev = last;
				new->next = 0;
				return head;
			}
			else
			{
				new->prev = temp->next;
				temp->next = new;
				new->next = save->prev;
				save->prev = new;
				return head;
			}
		}
	}
}
void delete(struct node *x,struct node *head,struct node *last)
{
	if(head==0)
	{
		printf("Underflow\n");
		return ;
	}
	else
	{
		struct node *save,*pred;
		save = head;
		while(save !=x && save->next != 0)
		{
			pred = save;
			save = save->next;
		}
		
			if(save == head)
			{
				head = head->next;
				head->prev = 0;
			}
			else if(save == last)
			{
				last = last->prev;
				last->next = 0;
			}
			else
			{
				pred->next = save->next;
			}
			free(save);
	}
}
