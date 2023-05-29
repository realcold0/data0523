#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 16

int count = 0;
typedef struct {
	char name[100];
} element;

typedef struct ListNode { 	// ��� Ÿ��
	element data;
	struct ListNode* link;
} ListNode;

ListNode* create_node(element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;
	return p;
}
// ���� ó�� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// ��� �������� ���� ����	//(3)
	head = p;	// ��� ������ ����		//(4)
	return head;
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = pre->link;	//(3)	
	pre->link = p;		//(4)	
	return head;		//(5)	
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;	// (1)
	head = removed->link;	// (2)
	free(removed);		// (3)
	return head;		// (4)
}
// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�. 
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;		// (2)
	free(removed);			// (3)
	return head;			// (4)
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s->", p->data.name);
	printf("NULL \n");
}

ListNode* search_list(ListNode* head, element x)
{
	count = 0;
	ListNode* p = head;
	while (p != NULL) {
		if (strcmp(p->data.name, x.name) == 0) return p;
		p = p->link;
	}
	return NULL; // Ž�� ����
}
ListNode* insert_last(ListNode* head, element value)
{
	ListNode* p = create_node(value);
	int count = 0;

	if (head == NULL)
	{
		head = p;
	}
	else
	{
		ListNode* last = head;
		while (last->link != NULL)
		{
			count++;
			last = last->link;
		}
		last->link = p;
	}

	return head;
}
// �׽�Ʈ ���α׷�
int main(void)
{
	ListNode* head = NULL;
	ListNode* deleteList = NULL;
	
	element data;
	element deleteData;

	strcpy_s(data.name, MAX, "Peach");
	head = insert_first(head, data);


	strcpy_s(data.name, MAX, "Banana");
	head = insert_first(head, data);

	strcpy_s(data.name, MAX, "Raspberry");
	head = insert_first(head, data);

	strcpy_s(data.name, MAX, "Guava");
	head = insert_first(head, data);

	strcpy_s(data.name, MAX, "Plum");
	head = insert_first(head, data);

	strcpy_s(data.name, MAX, "Cherry");
	head = insert_first(head, data);

	strcpy_s(data.name, MAX, "Grape");
	head = insert_first(head, data);

	strcpy_s(data.name, MAX, "Apple");
	head = insert_first(head, data);

	strcpy_s(data.name, MAX, "Ornage");
	head = insert_first(head, data);

	strcpy_s(data.name, MAX, "Mango");
	head = insert_first(head, data);


	while (1)
	{
		int menu;
		printf("1. Insert the fruit \n2. Delete the Fruit\n3.Print the deleted List\n4.Exit\nEnter the menu: ");
		scanf_s("%d", &menu);

		if (menu == 1)
		{
			element fruit;
			printf("Fruit name to add : ");
			scanf_s("%s", &fruit.name,sizeof(fruit.name));

			if (search_list(head, fruit) != NULL)
			{
				printf("%s is already exists\n", fruit.name);
				print_list(head);

				continue;
			}
			else {
				insert_last(head, fruit);
				print_list(head);

			}
			


		}
		else if (menu == 2)
		{
			element fruit;
			printf("Fruit name to delete : ");
			scanf_s("%s", &fruit.name, sizeof(fruit.name));
		
			ListNode* tmp = NULL;
			if (tmp = search_list(head, fruit) != NULL)
			{
				
				print_list(head);
			}
			else {
				printf("%s is not on the list.\n");
				continue;
			}


		}
		else if (menu == 3)
		{

		}
		else if (menu == 4)
		{

		}
		else {
			printf("insert menu \n");
			continue;
		}
	}




	print_list(head);
	return 0;
}