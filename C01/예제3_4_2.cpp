#include <stdio.h>
#include <windows.h>

void intro_color_set(void);
void text_color(char attr[]);
int main(void)
{
	char attr[3];
	intro_color_set();
	printf("�Է� �� Enter>");
	scanf("%s", attr);
	text_color(attr);
	printf("�������� ���ڻ��� ������ Ȯ���մϴ�.\n");
	return 0;
}

void intro_color_set(void)
{
	printf("�ؽ�Ʈȭ���� ���󺯰�\n\n");
	printf("0: ������, 1: �Ķ���, 2: �ʷϻ�\n");
	printf("3: ����,   4: ������, 5: ���ֻ�\n");
	printf("6: �����, 7: ���,   8: ȸ��\n");
	printf("9: ���� �Ķ���,  A: ���� �ʷϻ� \n");
	printf("B: ���� ����,    C: ���� ������\n");
	printf("D: ���� ���ֻ�,  E: ���� �����\n");
	printf("F: ���� ���\n\n");
	printf("���� ��� fc�� �Է��ϸ� ���� ���������\n");
	printf("���� �������� ���ڸ� ����մϴ�.\n\n");
}

void text_color(char attr[])
{
	char dos_command[9];
	sprintf(dos_command,"color %s",attr);
	system("cls");
	system(dos_command);
}
