#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct date
{
	int year;
	int month;
	int day;
};
typedef struct date date;

struct id
{
	char name[20];
	date birth;
	char gender[5];
	char number[15];
};
typedef struct id id;

void printf_id(id**, int);
void rearr_by_name(id**, int);
void rearr_by_birth(id**, int);

void main()
{
	int size,i;

	id **ptr_id = NULL;


	printf("<개인명세서>\n전화번호는 숫자를 모두 붙여서 입력해주세요\n이름은 영어로 입력해주시고, 첫 글자만 대문자로 해주세요\n\n");
	printf("(예시)\nKimseungh 19980412 남 01012345678\n\n");

	while (1)
	{

		printf("입력할 명세서의 개수를 입력해주세요(7~10) : ");
		scanf_s("%d", &size);


		if (size > 6 && size < 11)
		{
			ptr_id = (id **)malloc(sizeof(id *)*size);
			for (i = 0; i < size; i++)
			{
				*(ptr_id + i) = (id *)malloc(sizeof(id));
			}
			printf("\n");
			for (i = 0; i < size; i++)
			{
				printf("%d번째 사람입니다 : ", i + 1);
				scanf(" %s %4d%2d%2d %s %s", (**(ptr_id + i)).name, &(**(ptr_id + i)).birth.year, &(**(ptr_id + i)).birth.month, &(**(ptr_id + i)).birth.day, (**(ptr_id + i)).gender, (**(ptr_id + i)).number);
			}
			printf("\n");
			printf("---------입력순으로 출력한 결과입니다---------\n");
			printf("%-16s%-16s%-8s%-16s\n", "이름", "생년월일", "성별", "전화번호");
			printf_id(ptr_id, size);
			printf("\n");
			printf("---------이름의 ASCII코드값이 큰 것부터 출력한 결과입니다---------\n");
			printf("%-16s%-16s%-8s%-16s\n", "이름", "생년월일", "성별", "전화번호");
			rearr_by_name(ptr_id, size);
			printf_id(ptr_id, size);
			printf("\n");
			printf("---------생년원일이 빠른 사람부터 출력한 결과입니다---------\n");
			printf("%-16s%-16s%-8s%-16s\n", "이름", "생년월일", "성별", "전화번호");
			rearr_by_birth(ptr_id, size);
			printf_id(ptr_id, size);
			printf("\n");

			free(ptr_id);
			for (i = 0; i < size; i++)
			{
				free(*(ptr_id + i));
			}
		}

		else
		{
			printf("7~10 사이의 수를 입력해주세요\n\n");
			continue;
		}
	}

}

void printf_id(id **ptr_id, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{

		printf("%-16s", (**(ptr_id + i)).name);
		printf("%4d-%02d-%02d      ", (**(ptr_id + i)).birth.year, (**(ptr_id + i)).birth.month, (**(ptr_id + i)).birth.day);
		printf("%-8s", (**(ptr_id + i)).gender);
		printf("%-16s", (**(ptr_id + i)).number);
		printf("\n\n");

	}
}
void rearr_by_name(id **ptr_id, int size)
{
	int i, j;
	id *temp;
	temp = (id *)malloc(sizeof(id));
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (strcmp((**(ptr_id+j)).name, (**(ptr_id + j+1)).name) < 0)
			{
				temp = *(ptr_id + j);
				*(ptr_id + j) = *(ptr_id + j+1);
				*(ptr_id + j + 1) = temp;
			}
		}
	}
}
void rearr_by_birth(id **ptr_id, int size)
{
	int i,j;
	id *temp;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if ((**(ptr_id + j)).birth.year >(**(ptr_id + j+1)).birth.year)
			{
				temp = *(ptr_id + j);
				*(ptr_id + j) = *(ptr_id + j+1);
				*(ptr_id + j+1) = temp;
			}
			else if ((**(ptr_id + j)).birth.year == (**(ptr_id + j+1)).birth.year)
			{
				if ((**(ptr_id + j)).birth.month > (**(ptr_id + j+1)).birth.month)
				{
					temp = *(ptr_id + j);
					*(ptr_id + j) = *(ptr_id + j + 1);
					*(ptr_id + j + 1) = temp;
				}
				else if ((**(ptr_id + j)).birth.month == (**(ptr_id + j+1)).birth.month)
				{
					if ((**(ptr_id + j)).birth.day >(**(ptr_id + j+1)).birth.day)
					{
						temp = *(ptr_id + j);
						*(ptr_id + j) = *(ptr_id + j + 1);
						*(ptr_id + j + 1) = temp;
					}
				}
			}
		}
	}
}