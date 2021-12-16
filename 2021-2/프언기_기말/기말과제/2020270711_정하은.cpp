// 2020270711_������
#include <stdio.h>
#include <stdlib.h>     // malloc, free �Լ��� ����� ��� ����
#include <string.h>		// strcmp �Լ��� ����� ��� ����

// person ����ü ����
typedef struct person {
	char name[7];	// �̸�(���ڿ� ����)
	int age;		// ����(���� ����)
	char gender;	// ����(���ڿ� ����)
	char phone[14];	// ��ȭ����(���ڿ� ����)
} info_person;		// ����ü ��Ī ����

//struct info_person{
//	char name[20];
//	int age;
//	char gender;
//	char phone[14]; 
//}; 
//�̰ſ� ����.

// �̸��� �̿��ؼ� ��� ã��
info_person* search_person(info_person all_list[], info_person target, int n)
{
	info_person* result = (info_person*)malloc(sizeof(info_person));	// int�� ũ�� 4byte��ŭ ���� �޸� �Ҵ�

	for (int i = 0; i < n; i++)								// int i = 0���� n-1���� 1�� ����
		if (strcmp(all_list[i].name, target.name) == 0)		// ���� all_list[]�� name(�̸�)�� Ÿ���� ���� ���
		{
			result = &all_list[i];							// result = all_list[]�� �ּҰ� ����
			break;											// if�� ����
		}
		else											    // ���� all_list[]�� name(�̸�)�� Ÿ���� �ٸ� ���
			result = NULL;						        	// result = NULL�� ����
	return result;											// result�� ����
}

// save_file.txt ���� ���� �Լ�
void save_result(info_person temp, int count)
{
	FILE* fp = NULL;	// ���� ������ ���� ���� �� �ʱ�ȭ
	fopen_s(&fp, "save_file.txt", "a");		// save_file.txt ���� ���� ���� ����
	// ������ ������ ����� ������ ������ ���� ����� 'w'�� �޸� ������ ������ ���� �ִ� ���뿡 �߰��ϰ� ������ ������ ���� �����.
	fprintf(fp, "(%d) �̸� : %s, ���� : %d, ���� : %c, ��ȭ��ȣ : %s \n", count, temp.name, temp.age, temp.gender, temp.phone);
	// �̸�, ����, ����, ��ȭ��ȣ �Է�
	fclose(fp);	// ���� �ݱ�
}

// ���̸� 10���� ���� ���� ��Ÿ���� �Լ�
int* distribution(info_person all_list[], int n)
{
	int* val = (int*)malloc(n * sizeof(int));	// val�� ���� ���� �Ҵ�
	for (int i = 0; i < n; i++)					// int i = 0���� n-1���� 1�� ����
		val[i] = all_list[i].age / 10;			// val[] = all_list[]���� age(����)�� 10���� ���� ��
	return val;									// for�� ���� �� val�� ����
}

// max�� ã�� �Լ�
int find_max(int* val, int n)
{
	int max = 0;					// ������ ���� max ���� �� �ʱ�ȭ
	for (int i = 0; i < n; i++)		// int i = 0���� n-1���� 1�� ����
		if (val[i] > max)			// �ִ� ã�� (val[]�� �� �ִ� max���� ū �� = �ִ�)
			max = val[i];
	return max;						// for�� ���� �� max�� ����
}

// ���ɴ뺰 ��� �� ���
void print_dis(int* val, int n, int max)
{

	for (int i = 0; i < max + 1; i++)						// int i = 0���� max���� 1�� ����
	{
		int temp = 0;										// ������ ���� temp ���� �� �ʱ�ȭ
		for (int j = 0; j < n; j++)							// int j = 0���� n-1���� 1�� ����
		{
			if (val[j] == (i + 1))							// ���� val[j]���� i+1�� ��ġ�Ѵٸ�
				temp++;										// temp�� 1 ����
		}
		printf("%d�� : %d�� \n", (i + 1) * 10, temp);		// val��(���̸� 10���� ���� ���� ��) * 10, temp�� ���
	}
}

int main()
{
	info_person list[] = { {"Kim", 15,'M',"010-0000-0000"},
						   {"Lee", 22,'M',"010-1020-3040"},
						   {"Kang", 28,'F',"010-1234-5678"},
						   {"Seo", 19,'F',"010-9999-9999"},
						   {"Park", 42,'M',"010-1544-1544"},
						   {"Song", 31,'F',"010-8520-0369"},
						   {"Choi", 20,'M',"010-7777-7777"} };
	// ����ü ��Ī info_person���� ���� ���� �� �� �Ҵ� (�̸�, ����, ����, ��ȭ��ȣ)
	info_person temp = {}, * p = NULL;	// ����ü ��Ī info_person���� temp ���� ����
	int choice, count = 0, retry = 1, n = sizeof(list) / sizeof(list[0]);
	// ������ ���� ���� �� �ʱ�ȭ

	while (retry)	// retry = 1�� �� �� �� �� �ݺ�, retry = 0�� �� ����
	{
		printf("����Ʈ���� ����� ã���� �մϴ�.\n");
		printf("ã�� �ִ� ����� �̸��� �Է��ϼ��� : ");
		gets_s(temp.name);										// temp�� ã�� �ִ� ��� �̸�(���ڿ�) �Է�
		printf("����Ʈ���� %s�� ������ ã���ϴ�...", temp.name);	// 
		p = search_person(list, temp, n);						// ���� p => search_person() �Լ��� ��� ã��
		if (p == NULL)											// ã�� ����� ���� ��
			printf("�˻� ����!!\n");								// �˻� ���� ���
		else						                            // ã�� ����� ���� ��
		{
			printf("�˻� ����!! \n�˻� ��� -> ");				// �˻� ����
			printf("%s, %d, %c, %s\n", p->name, p->age, p->gender, p->phone);	// �˻� ��� ���(�̸�, ����, ����, ��ȭ��ȣ)
			printf("����� �����ұ��? (0. �ƴϿ� / 1. ��");
			scanf_s("%d", &choice);								// ��� ���� ���� -> choice ������ ����
			if (choice)											// choice = 1�� ��
			{
				count++;										// count ���� 1 ����
				save_result(*p, count);							// save_file.txt ���� ���� �Լ� ȣ�� (���Ͽ� �˻� ��� �� count �� ����)
			}
		}
		printf("�ٽ� �˻��ұ��? (0. �ƴϿ� / 1. ��) ");
		scanf_s("%d", &retry);	// ��˻� ���� ->  retry ������ ����
		getchar();				// ����
		printf("\n\n");
	}

	// ���� �ݺ��� ���� ��
	int* a = distribution(list, n);		// ���̸� 10���� ���� ���� ��Ÿ���� �Լ� ȣ��, ����
	int nn = find_max(a, n);			// max�� ã�� �Լ� ȣ��, ����
	print_dis(a, n, nn);				// ���ɴ뺰 ��� �� ��� �Լ� ȣ��
	return 0;							// �ڵ� ����
}