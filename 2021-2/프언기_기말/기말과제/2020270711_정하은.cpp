// 2020270711_정하은
#include <stdio.h>
#include <stdlib.h>     // malloc, free 함수가 선언된 헤더 파일
#include <string.h>		// strcmp 함수가 선언된 헤더 파일

// person 구조체 선언
typedef struct person {
	char name[7];	// 이름(문자열 변수)
	int age;		// 나이(정수 변수)
	char gender;	// 성별(문자열 변수)
	char phone[14];	// 전화번후(문자열 변수)
} info_person;		// 구조체 별칭 선언

//struct info_person{
//	char name[20];
//	int age;
//	char gender;
//	char phone[14]; 
//}; 
//이거와 동일.

// 이름을 이용해서 사람 찾기
info_person* search_person(info_person all_list[], info_person target, int n)
{
	info_person* result = (info_person*)malloc(sizeof(info_person));	// int의 크기 4byte만큼 동적 메모리 할당

	for (int i = 0; i < n; i++)								// int i = 0부터 n-1까지 1씩 증가
		if (strcmp(all_list[i].name, target.name) == 0)		// 만약 all_list[]의 name(이름)과 타겟이 같은 경우
		{
			result = &all_list[i];							// result = all_list[]의 주소값 저장
			break;											// if문 종료
		}
		else											    // 만약 all_list[]의 name(이름)과 타겟이 다른 경우
			result = NULL;						        	// result = NULL값 저장
	return result;											// result값 리턴
}

// save_file.txt 파일 생성 함수
void save_result(info_person temp, int count)
{
	FILE* fp = NULL;	// 파일 포인터 변수 선언 및 초기화
	fopen_s(&fp, "save_file.txt", "a");		// save_file.txt 파일 쓰기 모드로 열기
	// 파일이 있으면 덮어쓰고 없으면 파일을 새로 만드는 'w'와 달리 파일이 있으면 원래 있는 내용에 추가하고 없으면 파일을 새로 만든다.
	fprintf(fp, "(%d) 이름 : %s, 나이 : %d, 성별 : %c, 전화번호 : %s \n", count, temp.name, temp.age, temp.gender, temp.phone);
	// 이름, 나이, 성별, 전화번호 입력
	fclose(fp);	// 파일 닫기
}

// 나이를 10으로 나눈 몫을 나타내는 함수
int* distribution(info_person all_list[], int n)
{
	int* val = (int*)malloc(n * sizeof(int));	// val에 대한 동적 할당
	for (int i = 0; i < n; i++)					// int i = 0부터 n-1까지 1씩 증가
		val[i] = all_list[i].age / 10;			// val[] = all_list[]에서 age(나이)를 10으로 나눈 몫
	return val;									// for문 종료 후 val값 리턴
}

// max값 찾는 함수
int find_max(int* val, int n)
{
	int max = 0;					// 정수형 변수 max 선언 및 초기화
	for (int i = 0; i < n; i++)		// int i = 0부터 n-1까지 1씩 증가
		if (val[i] > max)			// 최댓값 찾기 (val[]값 중 최댓값 max보다 큰 값 = 최댓값)
			max = val[i];
	return max;						// for문 종료 후 max값 리턴
}

// 연령대별 사람 수 출력
void print_dis(int* val, int n, int max)
{

	for (int i = 0; i < max + 1; i++)						// int i = 0부터 max까지 1씩 증가
	{
		int temp = 0;										// 정수형 변수 temp 선언 및 초기화
		for (int j = 0; j < n; j++)							// int j = 0부터 n-1까지 1씩 증가
		{
			if (val[j] == (i + 1))							// 만약 val[j]값이 i+1과 일치한다면
				temp++;										// temp값 1 증가
		}
		printf("%d대 : %d명 \n", (i + 1) * 10, temp);		// val값(나이를 10으로 나눈 값의 몫) * 10, temp값 출력
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
	// 구조체 별칭 info_person으로 변수 선언 및 값 할당 (이름, 나이, 성별, 전화번호)
	info_person temp = {}, * p = NULL;	// 구조체 별칭 info_person으로 temp 변수 선언
	int choice, count = 0, retry = 1, n = sizeof(list) / sizeof(list[0]);
	// 정수형 변수 선언 및 초기화

	while (retry)	// retry = 1일 때 한 번 더 반복, retry = 0일 때 종료
	{
		printf("리스트에서 사람을 찾고자 합니다.\n");
		printf("찾고 있는 사람의 이름을 입력하세요 : ");
		gets_s(temp.name);										// temp에 찾고 있는 사람 이름(문자열) 입력
		printf("리스트에서 %s의 정보를 찾습니다...", temp.name);	// 
		p = search_person(list, temp, n);						// 변수 p => search_person() 함수로 사람 찾기
		if (p == NULL)											// 찾는 사람이 없을 때
			printf("검색 실패!!\n");								// 검색 실패 출력
		else						                            // 찾는 사람이 있을 때
		{
			printf("검색 성공!! \n검색 결과 -> ");				// 검색 성공
			printf("%s, %d, %c, %s\n", p->name, p->age, p->gender, p->phone);	// 검색 결과 출력(이름, 나이, 성별, 전화번호)
			printf("결과를 저장할까요? (0. 아니요 / 1. 예");
			scanf_s("%d", &choice);								// 결과 저장 여부 -> choice 변수에 저장
			if (choice)											// choice = 1일 때
			{
				count++;										// count 변수 1 증가
				save_result(*p, count);							// save_file.txt 파일 생성 함수 호출 (파일에 검색 결과 및 count 값 저장)
			}
		}
		printf("다시 검색할까요? (0. 아니요 / 1. 예) ");
		scanf_s("%d", &retry);	// 재검색 여부 ->  retry 변수에 저장
		getchar();				// 버퍼
		printf("\n\n");
	}

	// 무한 반복문 종료 후
	int* a = distribution(list, n);		// 나이를 10으로 나눈 몫을 나타내는 함수 호출, 저장
	int nn = find_max(a, n);			// max값 찾는 함수 호출, 저장
	print_dis(a, n, nn);				// 연령대별 사람 수 출력 함수 호출
	return 0;							// 코드 종료
}