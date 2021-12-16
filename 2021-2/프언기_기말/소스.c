#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
	char data[7];
	struct ListNode* link;
} listNode;


listNode* head;

// ��ü �޸𸮸� ����
void freeLinkedList() {
	listNode* p;
	listNode* cur = head;

	while (cur != NULL) {
		p = cur;
		cur = cur->link;
		free(p);
	}

	head = NULL;
}

// ������� ���
void printList() {
	listNode* cur = head;

	while (cur != NULL) {
		printf("%s", cur->data);
		cur = cur->link;
		if (cur != NULL)
			printf(" - ");
	}
	printf("\n");
}
// ù ��° ���� ����
void insertFirstNode(char* x) {

	listNode* new = (listNode*)malloc(sizeof(listNode));
	if (new == NULL)
	{
		printf("�����Ҵ� ����");
		exit(1);
	}
	strcpy_s(new->data, sizeof(new->data), x);
	new->link = NULL;


	if (head != NULL)// ��尡 �ϳ��̻� �ִ°�� -> ó����ġ�� ����
	{
		new->link = head;
		head = new;
	}
	else// ��尡 �ϳ��� ���°�� -> ����L�����Ϳ� ��� �ٷο��� 
	{
		head = new;
	}
}
// ������ ���� ����
void insertLastNode(char* x) {
	listNode* new = (listNode*)malloc(sizeof(listNode));
	if (new == NULL) {
		printf("�����Ҵ� ����!\n");
		exit(1);
	}
	strcpy_s(new->data, sizeof(new->data), x);
	new->link = NULL;

	if (head != NULL) 
	{
		listNode* tmp = head;
		while (tmp->link != NULL)
		{
			tmp = tmp->link;
		}
		tmp->link = new;// ��������ġ���� ����带 ����	
	}
	else
	{
		head = new;
	}

}

// ����Ʈ���� x ��带 Ž���ϴ� ����
listNode* searchNode(char* x) {
	listNode* tmp = head;		
	//��尡 �ϳ��� ���°��
	if (head == NULL)
		return NULL;

	//��尡 ������ 
	while (tmp != NULL)
	{
		if (strcmp(tmp->data, x) == 0)
		{
			break;
		}
		tmp = tmp->link;
	}
	return tmp;
}

// ��带 pre �ڿ� �����ϴ� ����
void insertMiddleNode(listNode* pre, char* x) {

	//1 new ��� ����(����ü+�����Ҵ�+������)-> Nullüũ 
	listNode* new = (listNode*)malloc(sizeof(listNode));
	if (new == NULL)
	{
		exit(1);
	}
	strcpy_s(new->data, sizeof(new->data), x);//2 ������ �κ� ������
	new->link = NULL;							//3 ��ũ Null ����


	if (pre != NULL) // ���Ž�� �Ϸ���� ,pre�ڿ� new��带 ������
	{
		new->link = pre->link;
		pre->link = new;
	}
	else // �����Ϸ��� �ϴ� ��尡 �������� �ʴ»���
	{
		printf("�˻���尡 �����ϴ�\n");
		free(new);
	}

}

// ����Ʈ���� ��� p�� �����ϴ� ����
void deleteNode(listNode* p) {
	// ������ �ش� ������ �������� ��ȸ
	if (p == NULL)
	{
		return;
	}

	// ���� ������� ��ġ Ž�� 
	listNode* pre = head;
	if (pre == NULL) //����� ��尡 �ϳ��� ���°��
	{
		return;
	}

	if (pre == p) //������ ��尡 ù����ΰ�� 
	{
		head = p->link;
	}
	else  //������ ��尡 ù��尡 �ƴѰ�� 
	{
		while (pre != NULL)
		{
			if (pre->link == p)
			{
				break;
			}

			pre = pre->link;
		}
		pre->link = p->link; // pre->link == p �������°�� -> �� ���
	}
	free(p);
}

int main() {
	listNode* p;
	head = NULL;

	printf("-----------�빫�� ����-----------\n");
	insertFirstNode("�빫��");
	printList();
	printf("\n"); printf("\n");


	printf("-----------�̸��, ������ ����-----------\n");
	insertLastNode("�̸��");
	insertLastNode("������");
	printList();
	printf("\n"); printf("\n");


	printf("-----------�̸�� Ž�� ��, �ڿ� �ڱ��� ����-----------\n");
	p = searchNode("�̸��");
	insertMiddleNode(p, "�ڱ���");
	printList();
	printf("\n"); printf("\n");
	

	printf("-----------�̸�� ����-----------\n");
	p = searchNode("�̸��");
	deleteNode(p);		
	printList();
	printf("\n"); printf("\n");


	printf("-----------�빫�� ����-----------\n");
	p = searchNode("�빫��");
	deleteNode(p);
	printList();
	printf("\n"); printf("\n");


	printf("-----------�ڱ��� ����-----------\n");
	p = searchNode("�ڱ���");
	deleteNode(p);
	printList();
	printf("\n"); printf("\n");


	freeLinkedList();               //����Ʈ �޸� ����
	return 0;
}