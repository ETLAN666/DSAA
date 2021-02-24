#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MAX 1024
int map[MAX][MAX];
#define MAX_VERTEX  20  
typedef char DataType;
typedef struct
{
	int vertexNum, edgeNum;
	DataType vertexArr[MAX_VERTEX];       
	int edgeArr[MAX_VERTEX][MAX_VERTEX]; 

}ArrayGraph;

void ArrayGraph_init(ArrayGraph* pGraph)
{
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		for (int j = 0; j < MAX_VERTEX; j++)
			pGraph->edgeArr[i][j] = 0;
	}
}

int T;

int main()
{
	cin >> T;
	while (T--)
	{
		int n, m;

		memset(map, 0, sizeof(map));
		
		cin >> n >> m;

		for (int i = 0; i < m; ++i)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			map[u][v]++;
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				printf("%d ", map[i][j]);
			}
			cout << endl;
		}
	}
	int data[10] ;
	memset(data, 0, sizeof(data));
	int temp = 0;
	for (int i = 0; i < 10 - 1; i++)
		for (int j = 0; j < 10 - 1 - i; j++)
			if (data[j] < data[j + 1])
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
	return 0;
}