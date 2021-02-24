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

//�ⷨһ
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
//��������������������
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