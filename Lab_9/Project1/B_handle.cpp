#include<iostream>  
#include<malloc.h>  
using namespace std;
#define maxNum 1000
int visited[maxNum];
int DFS_Count;
int pre[maxNum];
int post[maxNum];
int point;


typedef struct
{
    char v[maxNum];
    int e[maxNum][maxNum];
    int vNum;
    int eNum;
}graph;
void createGraph(graph* g);
void DFS(graph* g);
void dfs(graph* g, int i);
void dfs(graph* g, int i)
{


    visited[i] = 1;
    pre[i] = ++point;
    for (int j = 1; j <= g->vNum; j++)
    {
        if (g->e[i][j] != 0 && visited[j] == 0)
            dfs(g, j);
    }
    post[i] = ++point;
}

void DFS(graph* g)
{
    int i;

    for (i = 1; i <= g->vNum; i++)
    {
        visited[i] = 0;
        pre[i] = 0;
        post[i] = 0;
    }

    point = 0;

    DFS_Count = 0;

    for (i = 1; i <= g->vNum; i++)
    {
        if (visited[i] == 0)
        {
            DFS_Count++;
            dfs(g, i);
        }
    }
}
void createGraph(graph* g)
{
    cin >> g->vNum;
    cin >> g->eNum;
    int i, j;
    for (i = 1; i <= g->vNum; i++)
        for (j = 1; j <= g->vNum; j++)
            g->e[i][j] = 0;
    for (int k = 0; k < g->eNum; k++)
    {
        cin >> i >> j;
        g->e[i][j] = 1;
        g->e[j][i] = 1;
    }
}
int main()
{
    graph* g;
    g = (graph*)malloc(sizeof(graph));
    createGraph(g);
    DFS(g);

    if (g->eNum + DFS_Count > g->vNum)
        cout << "Bad" << endl;
    else
        cout << "Good" << endl;
    int k;
    cin >> k;
    return 0;
}