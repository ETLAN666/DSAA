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
    //新建节点root保存前序第一个节点为根结点
    root->_value = PreStart[0];
    root->_left = NULL;
    root->_right = NULL;
    if (InStart == InEnd && *InStart == *InEnd)
    {
        return root;
    }
    //据此节点找到中序遍历此节点的位置
    int* rootIn = InStart;
    while (*PreStart != *rootIn)
    {
        rootIn++;
    }
    //左子树的长度
    int leftlen = rootIn - InStart;
    //重建左子树
    if (leftlen > 0)
    {
        root->_left = RebuildCode(PreStart + 1, PreStart + leftlen, InStart, InStart + leftlen - 1);
    }
    //重建右子树
    if (InStart + leftlen < InEnd)
    {
        root->_right = RebuildCode(PreStart + leftlen + 1, PreEnd, InStart + leftlen + 1, InEnd);

    }
    return root;
}

BTreeNode* RebuildTree(int* PreOrder, int* InOrder, int len)
{
    //首先判断边界条件
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
    int min = 0;    //最小开销
    //声明一个从小到大取出数值的优先队列
    priority_queue<int, vector<int>, greater<int>> que;

    for (int i = 0; i < N; ++i) {
        que.push(L[i]);
    }
    int l1, l2;
    //不断选取最短的两块木板进行合成,合到只剩1块为止
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