#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head, *newnode;
struct node *temp, *prenode;

int count =0;

void insertAtfirst()
{
	newnode = malloc(sizeof(struct node));
	printf("Enter data for newnode : ");
	scanf("%d",&newnode->data);
	if(head == NULL)
	{
		head = newnode;
		newnode->next = NULL;
		newnode->prev = NULL;
	}else
	{
		newnode->next= head;
		head->prev = newnode;
		newnode->prev=NULL;
		head = newnode;
	}
	count++;
}

void insertAtlast()
{
	newnode = malloc(sizeof(struct node));
	printf("Enter data for newnode : ");
	scanf("%d",&newnode->data);
	if(head ==NULL)
	{
		head = newnode;
		newnode->next = NULL;
		newnode->prev = NULL;
	}else
	{
		temp = head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->prev = temp;
		newnode->next = NULL;
	}
	count++;
}

void insertAtposition()
{
	int pos, count1=0;
	printf("enter postion to insert data:");
	scanf("%d",&pos);
	if(pos<1||pos>count)
	{
		printf("You enter wrong position\n");
	}
	else{
		newnode = malloc(sizeof(struct node));
		printf("Enter data for newnode : ");
		scanf("%d",&newnode->data);
		if(head == NULL){
			head = newnode;
			newnode->next = NULL;
			newnode->prev = NULL;
		}
		else{
		temp = head;
		while(count1<pos-1)
		{
			prenode = temp;
			temp = temp->next;
			count1++;
		}
		prenode->next = newnode;
		newnode->next = temp;
		temp->prev = newnode;
		newnode->prev = prenode;
		}
		count++;
	}
}

void deletionAtfirst()
{
	if(head == NULL)
	{
		printf("Empty\n");
	}else
	{
		temp = head;
		temp->prev = NULL;
		head = temp->next;
		temp->next = NULL;
		free(temp);
		count--;
	}
}

void deletionAtlast()
{
	if(head == NULL)
	{
		printf("Empty\n");
	}else
	{
		temp = head;
		while(temp->next!=NULL)
		{
			prenode = temp;
			temp = temp->next;
		}
		if(head == temp)
		{
			head = NULL;
			free(temp);
		}
		else
		{
			prenode->next = NULL;
			temp->prev = NULL;
			free(temp);
		}
		count--;
	}
}
void deleteAtposition()
{
if(head == NULL)
{
	printf("Empty\n");
}else
{
	int pos, count1=0;
	printf("enter postion to delete:");
	scanf("%d",&pos);
	if(pos<1||pos>count)
	{
		printf("You enter wrong position\n");
	}
	else{
		if(pos==1){
			deletionAtfirst();
		}
		else{
		temp = head;
		while(count1<pos-1)
		{
			prenode = temp;
			temp = temp->next;
			count1++;
		}
		prenode->next = temp->next;
		temp->next->prev = prenode;
		count--;
		}
	}
}
}

void display()
{
	if(head==NULL){
		printf("Empty\n");
	}
	else{
	temp = head;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("\n");
	}
}

void main()
{
	printf("D.L.L.\n");
	int ch;
	head = NULL;	
	do{
	printf("1. insertion at first\n2. insertion at last\n3.insertion at position\n4.deletion at first\n5. deletion at last\n6.delete at position\n7.display\n8.Exit\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		insertAtfirst();
	break;
	case 2:
		insertAtlast();
	break;
	case 3:
		insertAtposition();
	break;
	case 4:
		deletionAtfirst();
	break;
	case 5:
		deletionAtlast();
	break;
	case 6:
		deleteAtposition();
	break;
	case 7:
		display();
	break;
	case 8:
		printf("Thank You😊️");
	break;
	default:
		printf("Wrong choice☠️");
	break;
	}
	}while(ch!=8);
}








