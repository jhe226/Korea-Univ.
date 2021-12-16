#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
	char data[7];
	struct ListNode* link;
} listNode;


listNode* head;

// 전체 메모리를 해제
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

// 순서대로 출력
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
// 첫 번째 노드로 삽입
void insertFirstNode(char* x) {

	listNode* new = (listNode*)malloc(sizeof(listNode));
	if (new == NULL)
	{
		printf("동적할당 실패");
		exit(1);
	}
	strcpy_s(new->data, sizeof(new->data), x);
	new->link = NULL;


	if (head != NULL)// 노드가 하나이상 있는경우 -> 처음위치에 연결
	{
		new->link = head;
		head = new;
	}
	else// 노드가 하나도 없는경우 -> 전역L포인터에 노드 바로연결 
	{
		head = new;
	}
}
// 마지막 노드로 삽입
void insertLastNode(char* x) {
	listNode* new = (listNode*)malloc(sizeof(listNode));
	if (new == NULL) {
		printf("동적할당 실패!\n");
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
		tmp->link = new;// 마지막위치에서 새노드를 연결	
	}
	else
	{
		head = new;
	}

}

// 리스트에서 x 노드를 탐색하는 연산
listNode* searchNode(char* x) {
	listNode* tmp = head;		
	//노드가 하나도 없는경우
	if (head == NULL)
		return NULL;

	//노드가 있을때 
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

// 노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode(listNode* pre, char* x) {

	//1 new 노드 생성(구조체+동적할당+포인터)-> Null체크 
	listNode* new = (listNode*)malloc(sizeof(listNode));
	if (new == NULL)
	{
		exit(1);
	}
	strcpy_s(new->data, sizeof(new->data), x);//2 데이터 부분 값삽입
	new->link = NULL;							//3 링크 Null 삽입


	if (pre != NULL) // 노드탐색 완료상태 ,pre뒤에 new노드를 연결함
	{
		new->link = pre->link;
		pre->link = new;
	}
	else // 연결하려고 하는 노드가 존재하지 않는상태
	{
		printf("검색노드가 없습니다\n");
		free(new);
	}

}

// 리스트에서 노드 p를 삭제하는 연산
void deleteNode(listNode* p) {
	// 삭제전 해당 데이터 존재유무 조회
	if (p == NULL)
	{
		return;
	}

	// 삭제 전노드의 위치 탐색 
	listNode* pre = head;
	if (pre == NULL) //연결된 노드가 하나도 없는경우
	{
		return;
	}

	if (pre == p) //삭제할 노드가 첫노드인경우 
	{
		head = p->link;
	}
	else  //삭제할 노드가 첫노드가 아닌경우 
	{
		while (pre != NULL)
		{
			if (pre->link == p)
			{
				break;
			}

			pre = pre->link;
		}
		pre->link = p->link; // pre->link == p 같아지는경우 -> 전 노드
	}
	free(p);
}

int main() {
	listNode* p;
	head = NULL;

	printf("-----------노무현 삽입-----------\n");
	insertFirstNode("노무현");
	printList();
	printf("\n"); printf("\n");


	printf("-----------이명박, 문재인 삽입-----------\n");
	insertLastNode("이명박");
	insertLastNode("문재인");
	printList();
	printf("\n"); printf("\n");


	printf("-----------이명박 탐색 후, 뒤에 박근혜 삽입-----------\n");
	p = searchNode("이명박");
	insertMiddleNode(p, "박근혜");
	printList();
	printf("\n"); printf("\n");
	

	printf("-----------이명박 삭제-----------\n");
	p = searchNode("이명박");
	deleteNode(p);		
	printList();
	printf("\n"); printf("\n");


	printf("-----------노무현 삭제-----------\n");
	p = searchNode("노무현");
	deleteNode(p);
	printList();
	printf("\n"); printf("\n");


	printf("-----------박근혜 삭제-----------\n");
	p = searchNode("박근혜");
	deleteNode(p);
	printList();
	printf("\n"); printf("\n");


	freeLinkedList();               //리스트 메모리 해제
	return 0;
}