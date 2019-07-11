#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>

//����������ά��������ʾ��ͼ
//(1). show_map ��ʾ�����չʾ������(���ֱ�ʾ����,*��ʾδ����)
//(2). mine_map ��ʾ���׵Ĳ���(0���ǵ���,!�ǵ���)
#define MAX_ROW 9
#define MAX_COL 9
#define MAX_ROWS 11
#define MAX_COLS 11
#define MINE_COUNT 10

void Init(char show_map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_COL]){
	//1.����show_map ��ʼ��Ϊȫ*
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			show_map[row][col] = '*';
		}
	}//2.����mine_map��˵,�ȳ�ʼ��ȫΪ0,������������ɸ�����
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			mine_map[row][col] = '0';
		}
	}
	int count = MINE_COUNT;
	while (count>0){
		int row = (rand()%MAX_ROW);
		int col = (rand()%MAX_COL);
		if (mine_map[row][col] == '!'){//���λ���Ѿ�������,��������һ����
			continue;//�����´�ѭ��
		}
		mine_map[row][col] = '!';
		--count;
	}
}
void PrintMap(char map[MAX_ROW][MAX_COL]){
	//�ȴ�ӡ�����к�
	printf("  | ");
	for (int col = 0; col < MAX_COL; ++col){
		printf("%d ", col);
	}//2.��ӡһ�ŷָ���
	printf("\n");
	printf("--------------------------\n");
	for (int row = 0; row < MAX_ROW; ++row){
		printf(" %d| ", row);
		for (int col = 0; col < MAX_COL; ++col){
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}

void GetPos(char show_map[MAX_ROW][MAX_COL], int* row, int* col){
	while (1){
		printf("������һ������:");
		//scanf�Ĳ�����һ��ָ�����͵ı���
		//��ʱ�˿�row��col��������ָ��int*,�Ͳ�����&
		scanf("%d %d", row, col);
		//�Ϸ����ж�
		if (*row <= 0 || *row >= MAX_ROW
			||*col <= 0 || *col >= MAX_COL){
			printf("������������,����������!\n");
			continue;
		}
		if (show_map[*row][*col] != '*'){
			//��ǰλ���Ѿ�����������Ҫ������������
			printf("������������Ѿ�������,�������µ�����!\n");
			continue;
		}
		break;
	}
}
//�ж���ǰλ����Χ�׵���Ŀ,�����¶�Ӧ�ĵ�ͼλ��
void UpdateMap(char show_map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_COL],
	int row,int col){
	//1,��Χ�˸�λ���м�����
	//2,��������ָ��µ�show_map��
	int mine_count = 0;
	//rowһ����[0,MAX_ROW)
	//row - 1һ��С��MAX_ROW
	//����
	if (row-1>=0&&col-1>=0
		&&mine_map[row - 1][col - 1] == '!'){
		++mine_count;
	}
	//����
	if (row - 1 >= 0
		&& mine_map[row - 1][col] == '!'){
		++mine_count;
	}
	//����
	if (row - 1 >= 0 && col + 1 < MAX_COL
		&& mine_map[row - 1][col + 1] == '!'){
		++mine_count;
	}
	//����
	if ( col - 1 >= 0
		&& mine_map[row][col - 1] == '!'){
		++mine_count;
	}
	//����
	if (col + 1 < MAX_COL
		&& mine_map[row][col +1] == '!'){
		++mine_count;
	}
	//����
	if (row + 1 <MAX_ROW && col - 1 >= 0
		&& mine_map[row + 1][col - 1] == '!'){
		++mine_count;
	}
	//����
	if (row+ 1 <MAX_ROW
		&& mine_map[row +1][col] == '!'){
		++mine_count;
	}
	//����
	if (row + 1 <MAX_ROW && col + 1 <MAX_COL
		&& mine_map[row + 1][col + 1] == '!'){
		++mine_count;
	}
	//2.����������µ�show_map��
	//�ַ�Ҳ������������ʾ��,ascii���
	//Ҫ���������ת�ɶ�Ӧ���ַ�
	show_map[row][col] = mine_count + '0';
	
}

void Game(){
	//��������
	//1.������ͼ����ʼ��
	//a)show_map,��ʼ��ΪȫΪ*
	//b)mine_map,Ҫ����������ɸ���(10��)
	char show_map[MAX_ROWS][MAX_COLS];
	char mine_map[MAX_ROWS][MAX_COLS];
	Init(show_map, mine_map);
	//2.��ӡ��ͼ
	int safe_count = 0;
	while (1){
		// TODO  ��ӡmine_map���������ʱ����,������ȥ��
		PrintMap(mine_map);
		printf("=========================\n");


		PrintMap(show_map);
		//3.����������������,��У��(Ҫ���˷Ƿ�����)
		int row=0;
		int col=0;
		GetPos(show_map, &row, &col);
		//4.���Է�����Ӧ������
		//a)�����������ǵ���,��Ϸʧ��
		if (mine_map[row][col] == '!'){
			PrintMap(mine_map);
			printf("Game Over!\n");
			break;
		}
		//b)���������겻�ǵ���,����show_map,����ǰλ����ʾһ������
		++safe_count;
		if (safe_count == MAX_ROW*MAX_COL - MINE_COUNT){
			printf("Victory!\n");
			break;
		}
		//c)���������겻�ǵ���,���������һ�����ǵ��׵ĸ���,��Ϸ��ʤ
		UpdateMap(show_map,mine_map,row,col);
		//5.ѭ������ 2,whileѭ��
	}
}


int main(){
	srand((unsigned int)time(NULL));
	Game();
	system("pause");
	return 0;
}