/*
#include <iostream>
#include <queue>
using namespace std;

struct BTreeNode
{
    int _value;
    BTreeNode* _left;
    BTreeNode* _right;
};

BTreeNode* RebuildCode(int* PreStart, int* PreEnd, int* InStart, int* InEnd)
{
    BTreeNode* root = new BTreeNode();
    //�½��ڵ�root����ǰ���һ���ڵ�Ϊ�����
    root->_value = PreStart[0];
    root->_left = NULL;
    root->_right = NULL;
    if (InStart == InEnd && *InStart == *InEnd)
    {
        return root;
    }
    //�ݴ˽ڵ��ҵ���������˽ڵ��λ��
    int* rootIn = InStart;
    while (*PreStart != *rootIn)
    {
        rootIn++;
    }
    //�������ĳ���
    int leftlen = rootIn - InStart;
    //�ؽ�������
    if (leftlen > 0)
    {
        root->_left = RebuildCode(PreStart + 1, PreStart + leftlen, InStart, InStart + leftlen - 1);
    }
    //�ؽ�������
    if (InStart + leftlen < InEnd)
    {
        root->_right = RebuildCode(PreStart + leftlen + 1, PreEnd, InStart + leftlen + 1, InEnd);

    }
    return root;
}

BTreeNode* RebuildTree(int* PreOrder, int* InOrder, int len)
{
    //�����жϱ߽�����
    if (PreOrder == NULL || InOrder == NULL || len <= 0)
    {
        return NULL;
    }
    else
    {
        return RebuildCode(PreOrder, PreOrder + len - 1, InOrder, InOrder + len - 1);
    }
}

int solve(int N,int L[]) {
    int min = 0;    //��С����
    //����һ����С����ȡ����ֵ�����ȶ���
    priority_queue<int, vector<int>, greater<int>> que;

    for (int i = 0; i < N; ++i) {
        que.push(L[i]);
    }
    int l1, l2;
    //����ѡȡ��̵�����ľ����кϳ�,�ϵ�ֻʣ1��Ϊֹ
    while (que.size() > 1) {
        l1 = que.top();
        que.pop();
        l2 = que.top();
        que.pop();
        min += l1 + l2;
        que.push(l1 + l2);
    }
    return min;
}

int main() {
    int T;
    cin >> T;
    while (T)
    {
        int N;
        cin >> N;
        int Len[N];
        for (int i = 0; i < N; i++)
        {
            cin >> Len[i];
        }
        cout << solve(N,Len) << endl;
        T--;
    }
    
    return 0;
}
*/