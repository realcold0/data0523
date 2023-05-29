#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 16

int count = 0;
typedef struct {
	char name[100];
} element;

typedef struct ListNode { 	// 노드 타입
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
// 오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// 헤드 포인터의 값을 복사	//(3)
	head = p;	// 헤드 포인터 변경		//(4)
	return head;
}

// 노드 pre 뒤에 새로운 노드 삽입
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
// pre가 가리키는 노드의 다음 노드를 삭제한다. 
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
	return NULL; // 탐색 실패
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
// 테스트 프로그램
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

				continue;
			}
			else {
				head = insert_last(head, fruit);

			}
			


		}
		else if (menu == 2)
		{
			element fruit;
			printf("Fruit name to delete: ");
			scanf_s("%s", fruit.name, sizeof(fruit.name));

			ListNode* prev = NULL;
			ListNode* curr = head;

			while (curr != NULL) {
				if (strcmp(curr->data.name, fruit.name) == 0) {
					if (prev == NULL) {
						head = delete_first(head);
					}
					else {
						head = delete(head, prev);
					}
					deleteList = insert_last(deleteList, fruit);


					printf("%s has been deleted\n", fruit.name);
					break;
				}
				prev = curr;
				curr = curr->link;
			}

			if (curr == NULL) {
				printf("%s is not in the list.\n", fruit.name);
			}


		}
		else if (menu == 3)
		{
			printf("Deleted Fruit List: ");
			print_list(deleteList);
		}
		else if (menu == 4)
		{
			return 0;
		}
		else {
			printf("insert right menu \n");
			continue;
		}

		print_list(head);
		printf("==========================\n");
	}



	return 0;
}