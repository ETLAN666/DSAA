
#include<cstdio>
#include<stack> 
#include <iostream>
#define MAXSIZE 100
#define MaxInt 32767 //��ʾ���ֵ����������� 
#define MVNum 100 //������󶥵��� 
using namespace std;

typedef char VerTexType;//���趥����������Ϊ�ַ���
typedef int ArcType;//����ߵ�ȨֵΪ����
typedef struct {
	VerTexType vexs[MVNum];//����� 
	ArcType arcs[MVNum][MVNum];//�ڽӾ���
	int vexnum, arcnum;//ͼ�ĵ�ǰ�����ͱ��� 
}AMGraph;

//����һ��������ͼG�е�λ�� 
int LocateVex(AMGraph& G, VerTexType vex) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i] == vex) {
			return i;
		}
	}
}

//�����ڽӾ����ʾ������������
/*
1.�����ܶ��������ܱ�����
2.������������Ϣ�����붥���
3.��ʼ���ڽӾ���ÿ���ߵ�Ȩֵ��ʼ��Ϊ���ֵ��
4.�����ڽӾ�����������ÿ���������������յ�ͱߵ�Ȩֵ��ȷ������������ͼ�е�λ�ã�
֮��ʹ��Ӧ�ı߸�����Ӧ��Ȩֵ��
*/
void CreateUDN(AMGraph& G) {
	printf("�������ܶ�����:");
	scanf("%d", &G.vexnum);
	printf("�������ܱ���:");
	scanf("%d", &G.arcnum);
	for (int i = 0; i < G.vexnum; ++i) {
		printf("�������%d���������Ϣ:", (i + 1));
		cin >> G.vexs[i];
	}

	printf("\n");
	//��ʼ���ڽӾ��� 
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = MaxInt;
		}
	}
	//�����ڽӾ���
	for (int k = 0; k < G.arcnum; k++) {
		printf("�������%d���ߵ���Ϣ(�ߵĶ����Ȩֵ):\n", (k + 1));
		printf("������ߵ���ʼ����:");
		VerTexType v1;
		cin >> v1;
		printf("������ߵ���ֹ����:");
		VerTexType v2;
		cin >> v2;
		printf("������ߵ�Ȩ��:");
		ArcType weight;
		scanf("%d", &weight);
		//ȷ��v1��v2��G�е�λ�ã�������������±�
		int i = LocateVex(G, v1);
		printf("v1��ͼG�е�λ��:%d\n", i);
		int j = LocateVex(G, v2);
		printf("v2��ͼG�е�λ��:%d\n", j);
		G.arcs[i][j] = weight;
		//����ͼ���ԳƱߵ�Ȩֵ��Ϊ�������ֵ 
		//G.arcs[j][i]=G.arcs[i][j];
	}
}

//���ͼ���ڽӾ��� 
void PrintAM(AMGraph& G) {
	printf("\n���ͼ���ڽӾ���:\n");
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			if (G.arcs[i][j] == MaxInt) {
				G.arcs[i][j] = 0;
				printf("%d ", G.arcs[i][j]);
			}
			else {
				printf("%d ", G.arcs[i][j]);
			}
		}
		printf("\n");
	}
}

int main() {
	AMGraph G;
	CreateUDN(G);
	PrintAM(G);
}