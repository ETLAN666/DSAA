#include<iostream>  
#include<malloc.h>  
using namespace std;
#define maxNum 100 //�����ڽӾ�֤����󶨵���  
int visited[maxNum];//ͨ��visited�����������������Ƿ񱻷��ʹ���0��ʾδ�����ʣ�1��ʾ������  
int DFS_Count;//��ͨ�������������ڲ�������ͼ�Ƿ���ͨ��DFS_Count=1��ʾֻ��һ����ͨ������������������ͼ����ͨ��  
int pre[maxNum];
int post[maxNum];
int point;//pre��post��ֵ  

//ͼ���ڽӾ����ʾ�ṹ  
typedef struct
{
    char v[maxNum];//ͼ�Ķ�����Ϣ  
    int e[maxNum][maxNum];//ͼ�Ķ�����Ϣ  
    int vNum;//�������  
    int eNum;//�ߵĸ���  
}graph;
void createGraph(graph* g);//����ͼg  
void DFS(graph* g);//������ȱ���ͼg  
void dfs(graph* g, int i);//�Ӷ���i��ʼ������ȱ����������ڵĵ�  
void dfs(graph* g, int i)
{
    //cout<<"����"<<g->v[i]<<"�Ѿ�������"<<endl;  
    cout << "����" << i << "�Ѿ�������" << endl;
    visited[i] = 1;//��Ƕ���i������  
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
    //��ʼ��visited���飬��ʾһ��ʼ���ж��㶼δ�����ʹ�  
    for (i = 1; i <= g->vNum; i++)
    {
        visited[i] = 0;
        pre[i] = 0;
        post[i] = 0;
    }
    //��ʼ��pre��post  
    point = 0;
    //��ʼ����ͨ������Ϊ0  
    DFS_Count = 0;
    //�����������  
    for (i = 1; i <= g->vNum; i++)
    {
        if (visited[i] == 0)//����������Ϊ�����ʹ������i�����������������ȱ���  
        {
            DFS_Count++;//ͳ�Ƶ���void dfs(graph *g,int i);�Ĵ���  
            dfs(g, i);
        }
    }
}
void createGraph(graph* g)//����ͼg  
{
    cout << "���ڴ�������ͼ..." << endl;
    cout << "�����붥�����vNum:";
    cin >> g->vNum;
    cout << "������ߵĸ���eNum:";
    cin >> g->eNum;
    int i, j;
    //���붥����Ϣ  
    //cout<<"�����붥����Ϣ��"<<endl;  
    //for(i=0;i<g->vNum;i++)  
    //  cin>>g->v[i];  
    //��ʼ��ͼg  
    for (i = 1; i <= g->vNum; i++)
        for (j = 1; j <= g->vNum; j++)
            g->e[i][j] = 0;
    //����ߵ����  
    cout << "������ߵ�ͷ��β" << endl;
    for (int k = 0; k < g->eNum; k++)
    {
        cin >> i >> j;
        g->e[i][j] = 1;
        g->e[j][i] = 1;//����ͼ�Գ�  
    }
}
int main()
{
    graph* g;
    g = (graph*)malloc(sizeof(graph));
    createGraph(g);//����ͼg  
    DFS(g);//������ȱ���  
    //��ͨ�������������ж��Ƿ���ͨͼ  
    cout << "��ͨ����������";
    cout << DFS_Count << endl;
    if (DFS_Count == 1)
        cout << "ͼg����ͨͼ" << endl;
    else if (DFS_Count > 1)
        cout << "ͼg������ͨͼ" << endl;
    //�������pre��postֵ  
    for (int i = 1; i <= g->vNum; i++)
        cout << "����" << i << "��pre��post�ֱ�Ϊ��" << pre[i] << " " << post[i] << endl;
    //cout<<endl;  
    //�ж�����ͼ���Ƿ��л�  
    if (g->eNum + DFS_Count > g->vNum)
        cout << "Bad" << endl;
    else
        cout << "Good" << endl;
    int k;
    cin >> k;
    return 0;
}