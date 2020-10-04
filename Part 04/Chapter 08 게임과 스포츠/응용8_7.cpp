#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

void display_rule(void);
void gotoxy(int x, int y);
void make_treasure_and_bomb(int tx[], int ty[], int bombx[], int bomby[]);  //���� ���� : ������ ��ź�� ��ġ ���� 

void display_map(int matrix[][10]);  //���� 
void basic_map(void);
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);  
void game_control(int tx[], int ty[], int bombx[], int bomby[]);

int main(void)
{
    int tx[2], ty[2];        //������ ������ġ 
	int bombx[2], bomby[2];  //��ź2���� ��ġ�� ������ �迭 
	int matrix[10][10]={0};
    clock_t start, end;
    double pst;
    srand(time(NULL));
	make_treasure_and_bomb(tx, ty, bombx, bomby);  //�Լ� ����
    display_rule();
    start=clock();
	system("cls");
    game_control(tx, ty, bombx, bomby);
    end=clock();
	pst=(double)(end-start)/CLK_TCK;
	gotoxy(1, 13);
	printf("��� �ð� : %.1f ��", pst);
	gotoxy(1, 14);
	printf("��� ã�ҽ��ϴ�. ������ �����մϴ�. \n");
	getch();
    printf("press any key to continue.......");
    getch();
	return 0;
}

void display_rule(void)
{
	gotoxy(1, 1);
	printf("����ã��");
	gotoxy(1,3);
	printf("�Ʒ��� �ٵ��� ����� ���ڿ��� ������ \n");
	gotoxy(1,4);
	printf("������ �ֽ��ϴ�. \n");
	gotoxy(1,5);
	printf("ȭ��ǥ(�����)Ű�� �������� ã���ϴ�. \n");
	gotoxy(1,7);
	basic_map();
	printf("\n�ƹ�Ű�� ������ �����մϴ�. \n");
	getch();
}

void basic_map(void)
{
	int i, j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
			printf("��");
		printf("\n");
	}
}


void make_treasure_and_bomb(int tx[], int ty[], int bombx[], int bomby[])   //����
{
	int i;
    for(i=0;i<2;i++)
    {
		do
		{
			tx[i]=rand()%11; //������ x��ǥ
			ty[i]=rand()%11; //������ y��ǥ
		}while((tx[i]<=1) || (ty[i]<=1));  
		do
		{
			bombx[i]=rand()%11; //��ź�� x��ǥ
			bomby[i]=rand()%11; //��ź�� y��ǥ
		}while((bombx[i]<=1) || (bomby[i]<=1) || (bombx[i]==tx[i]) || (bomby[i]==tx[i]));  
		
	}
}



void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void display_map(int matrix[][11])          //����
{
	int i, j;
	basic_map();
	for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
			if (matrix[i][j]==1)
			{
				gotoxy(2*i-1, j);
				printf("��");
			}
			else if (matrix[i][j]==2)
			{
				gotoxy(2*i-1, j);
				printf("��");
			}	
			else if (matrix[i][j]==3)
			{
				gotoxy(2*i-1, j);
				printf("��");  //��ź ǥ��
				gotoxy(1, 1);
			}	

}
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch(key)
	{
	case 72:  //����(��) ������ ȭ��ǥ Ű �Է�
		*y1=*y1-1;
		if (*y1<1)	*y1=1; //y��ǥ�� �ּҰ�
		break;
	case 75:  //����(��) ������ ȭ��ǥ Ű �Է�
		*x1=*x1-2;            //x��ǥ�� ���Ұ�
		if (*x1<1)	*x1=1; //x��ǥ�� �ּҰ�
		break;
	case 77:  //������(��) ������ ȭ��ǥ Ű �Է�
		*x1=*x1+2;               //x��ǥ�� ������
		if (*x1>x_b)  *x1=x_b; //x��ǥ�� �ִ밪
		break;
	case 80:  //�Ʒ���(��) ������ ȭ��ǥ Ű �Է�
		*y1=*y1+1;
		if (*y1>y_b)  *y1=y_b; //y��ǥ�� �ִ밪
		break;
	default:
		return;
	}
}

void game_control(int tx[], int ty[], int bombx[], int bomby[])
{
	char key;
	int i, j, count=0;
	int x=1, y=1;
	int matrix[11][11]={0};
	do
	{
		gotoxy(x, y);
		printf("��");
		matrix[(x+1)/2][y]=1;

		for(i=0;i<2;i++)
		{
			if (((x+1)/2==tx[i]) && (y==ty[i]))
				matrix[(x+1)/2][y]=2;
			if (((x+1)/2==bombx[i]) && (y==bomby[i]))  //���� ���� ��ġ�� ��ź�� ��ġ�� ������ 3����
			{
				matrix[(x+1)/2][y]=3;
				gotoxy(1,13);
                printf("��ź�߰�!, Ŀ����ġ ���� �̵� 1,1\n");
				x=1;y=1;         //Ŀ���� ��ġ�� 1,1�� �̵� 
				gotoxy(x, y);
			}
		}
		gotoxy(1, 1);
		display_map(matrix);

		count=0;
		for(i=1;i<=10;i++)
			for(j=1;j<=10;j++)
				if (matrix[i][j]==2)
					count=count+1;
		gotoxy(1,12);
   		printf("ã�� ����(��)�� ���� : %d", count);
		key=getch();
		move_arrow_key(key, &x, &y, 19, 10);
	}while(count<2);
}
