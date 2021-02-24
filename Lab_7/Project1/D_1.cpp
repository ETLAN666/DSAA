/*
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
struct BTreeNode
{
    int _value;
    BTreeNode* _left;
    BTreeNode* _right;
};

//解法一
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
//后序遍历输出二叉树序列
void PostOrder(BTreeNode* root)
{
    if (root->_left != NULL)
    {
        PostOrder(root->_left);
    }
    if (root->_right != NULL)
    {
        PostOrder(root->_right);
    }
    if (root != NULL)
    {
        cout << root->_value << " ";
    }
}
int main()
{
    
   
    int T;
    cin >> T;
    while (T)
    {
        int N;
        cin >> N;
        int  PreOrder[N];
        int  InOrder[N];  
        for (int i = 0; i < N; i++)
        {
            cin >> PreOrder[i];
        }      
        for (int i = 0; i < N; i++)
        {
            cin >> InOrder[i];
        }
        PostOrder(RebuildTree(PreOrder, InOrder, N));
        cout << endl;     
        T--;
    }
    return 0;
}
*/