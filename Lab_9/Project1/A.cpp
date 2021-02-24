
#include<cstdio>
#include<stack> 
#include <iostream>
#define MAXSIZE 100
#define MaxInt 32767 //表示最大值，即正无穷大 
#define MVNum 100 //定义最大顶点数 
using namespace std;

typedef char VerTexType;//假设顶点数据类型为字符型
typedef int ArcType;//假设边的权值为整型
typedef struct {
	VerTexType vexs[MVNum];//顶点表 
	ArcType arcs[MVNum][MVNum];//邻接矩阵
	int vexnum, arcnum;//图的当前点数和边数 
}AMGraph;

//查找一个顶点在图G中的位置 
int LocateVex(AMGraph& G, VerTexType vex) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i] == vex) {
			return i;
		}
	}
}

//采用邻接矩阵表示法创建有向网
/*
1.输入总订单数和总边数；
2.依次输入点的信息，存入顶点表；
3.初始化邻接矩阵，每个边的权值初始化为最大值；
4.构造邻接矩阵：依次输入每条边依附的起点和终点和边的权值，确定两个顶点在图中的位置，
之后使相应的边赋予相应的权值。
*/
void CreateUDN(AMGraph& G) {
	printf("请输入总顶点数:");
	scanf("%d", &G.vexnum);
	printf("请输入总边数:");
	scanf("%d", &G.arcnum);
	for (int i = 0; i < G.vexnum; ++i) {
		printf("请输入第%d个顶点的信息:", (i + 1));
		cin >> G.vexs[i];
	}

	printf("\n");
	//初始化邻接矩阵 
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = MaxInt;
		}
	}
	//构造邻接矩阵
	for (int k = 0; k < G.arcnum; k++) {
		printf("请输入第%d条边的信息(边的顶点和权值):\n", (k + 1));
		printf("请输入边的起始顶点:");
		VerTexType v1;
		cin >> v1;
		printf("请输入边的终止顶点:");
		VerTexType v2;
		cin >> v2;
		printf("请输入边的权重:");
		ArcType weight;
		scanf("%d", &weight);
		//确定v1和v2在G中的位置，即顶点数组的下标
		int i = LocateVex(G, v1);
		printf("v1在图G中的位置:%d\n", i);
		int j = LocateVex(G, v2);
		printf("v2在图G中的位置:%d\n", j);
		G.arcs[i][j] = weight;
		//有向图，对称边的权值仍为初试最大值 
		//G.arcs[j][i]=G.arcs[i][j];
	}
}

//输出图的邻接矩阵 
void PrintAM(AMGraph& G) {
	printf("\n输出图的邻接矩阵:\n");
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