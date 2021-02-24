#include<cstdio>
#include <iostream>
//#define MAX 111111
//#define INF 0x7FFFFFFF
#pragma comment(linker, "/STACK:36777216")
using namespace std;
struct sbt_node {
    int left,right,size;
    long long val;
};
sbt_node size_balanced_tree[(int)8e4+10];
int pet=0,people=0,op,les,more,result;
long long ans=0,num;
int tree_top ,tree_root;
void left_rot(int &x) {
    int y = size_balanced_tree[x].right;
    size_balanced_tree[x].right = size_balanced_tree[y].left;
    size_balanced_tree[y].left = x;
    size_balanced_tree[y].size = size_balanced_tree[x].size; //转上去的节点数量为先前此处节点的size
    size_balanced_tree[x].size = size_balanced_tree[size_balanced_tree[x].left].size + size_balanced_tree[size_balanced_tree[x].right].size + 1;
    x = y;
}

void right_rot(int &x) {
    int y = size_balanced_tree[x].left;
    size_balanced_tree[x].left = size_balanced_tree[y].right;
    size_balanced_tree[y].right = x;
    size_balanced_tree[y].size = size_balanced_tree[x].size;
    size_balanced_tree[x].size = size_balanced_tree[size_balanced_tree[x].left].size + size_balanced_tree[size_balanced_tree[x].right].size + 1;
    x = y;
}

void maintain(int &x,bool flag) {
    if(flag == 0) { //左边
        if(size_balanced_tree[size_balanced_tree[size_balanced_tree[x].left].left].size > size_balanced_tree[size_balanced_tree[x].right].size) {//左孩子左子树size大于右孩子size
            right_rot(x);
        } else if(size_balanced_tree[size_balanced_tree[size_balanced_tree[x].left].right].size > size_balanced_tree[size_balanced_tree[x].right].size) {//左孩子右子树size大于右孩子size
            left_rot(size_balanced_tree[x].left);
            right_rot(x);
        } else return ;
    } else { //右边
        if(size_balanced_tree[size_balanced_tree[size_balanced_tree[x].right].right].size > size_balanced_tree[size_balanced_tree[x].left].size) //右孩子的右子树大于左孩子
            left_rot(x);
        else if(size_balanced_tree[size_balanced_tree[size_balanced_tree[x].right].left].size > size_balanced_tree[size_balanced_tree[x].left].size) { //右孩子的左子树大于左孩子
            right_rot(size_balanced_tree[x].right);
            left_rot(x);
        } else return ;
    }
    maintain(size_balanced_tree[x].left,0);
    maintain(size_balanced_tree[x].right,1);
}

void insert(int &x,long long val) {
    if(x == 0) { //空节点
        x = ++ tree_top;
        size_balanced_tree[x].left = size_balanced_tree[x].right = 0;
        size_balanced_tree[x].size = 1;
        size_balanced_tree[x].val = val;
    } else {
        size_balanced_tree[x].size ++;
        if(val < size_balanced_tree[x].val) insert(size_balanced_tree[x].left,val);
        else insert(size_balanced_tree[x].right,val);
        maintain(x,val >= size_balanced_tree[x].val);
    }
}

int remove(int &x,long long val) {
    int k;
    size_balanced_tree[x].size --;
    if(val == size_balanced_tree[x].val || (val < size_balanced_tree[x].val && size_balanced_tree[x].left == 0) || (val > size_balanced_tree[x].val && size_balanced_tree[x].right == 0)) {
        k = size_balanced_tree[x].val;
        if(size_balanced_tree[x].left && size_balanced_tree[x].right)
            size_balanced_tree[x].val = remove(size_balanced_tree[x].left,size_balanced_tree[x].val + 1);
        else
            x = size_balanced_tree[x].left + size_balanced_tree[x].right;
    } else if(val > size_balanced_tree[x].val)
        k = remove(size_balanced_tree[x].right,val);
    else if(val < size_balanced_tree[x].val)
        k = remove(size_balanced_tree[x].left,val);
    return k;
}

int getmin() { //二叉搜索树找最小值
    int x;
    for(x = tree_root; size_balanced_tree[x].left; x = size_balanced_tree[x].left) ;
    return size_balanced_tree[x].val;
}
int getmax() {
    int x;
    for(x = tree_root ; size_balanced_tree[x].right; x = size_balanced_tree[x].right) ;
    return size_balanced_tree[x].val;

}

//前驱 小于
int pred(int &x,int y,long long val)

{
    if(x == 0) return y;
    if(size_balanced_tree[x].val < val)//加上等号，就是小于等于
        return pred(size_balanced_tree[x].right,x,val);
    else return pred(size_balanced_tree[x].left,y,val);
}
//pred(root,0,val)
//后继 大于
int succ(int &x,int y,long long val) {
    if(x == 0) return y;
    if(size_balanced_tree[x].val > val)
        return succ(size_balanced_tree[x].left,x,val);
    else return succ(size_balanced_tree[x].right,y,val);
}

//求第k小数
int search(int &x,int k) {
    int r = size_balanced_tree[size_balanced_tree[x].left].size + 1;
    if(r == k) return size_balanced_tree[x].val;
    else if(r < k) return search(size_balanced_tree[x].right,k - r);
    else return search(size_balanced_tree[x].left,k);
}

//求第K小数的逆运算
int rankk(int &x,int val) {
    if(val < size_balanced_tree[x].val)
        return rankk(size_balanced_tree[x].left,val);
    else if(val > size_balanced_tree[x].val)
        return rankk(size_balanced_tree[x].right,val);
    else return size_balanced_tree[size_balanced_tree[x].left].size + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %lld", &op, &num);
        result = 0;
        if (op == 0) {
            les = pred(people, 0, num);
            more = succ(people, 0, num);
            if (les)
                result = les;
            if (more && (result == 0 || abs(size_balanced_tree[more].val - num) < abs(size_balanced_tree[result].val - num)))
                result = more;
            if (result) {
                ans += abs(size_balanced_tree[result].val - num);
                remove(people, size_balanced_tree[result].val);
            } else
                insert(pet, num);
        } else {
            les = pred(pet, 0, num);
            more = succ(pet, 0, num);
            if (les)
                result = les;
            if (more && (result == 0 || abs(size_balanced_tree[more].val - num) < abs(size_balanced_tree[result].val - num)))
                result = more;
            if (result) {
                ans += abs(size_balanced_tree[result].val - num);
                remove(pet, size_balanced_tree[result].val);
            } else
                insert(people, num);
        }
    }
    printf("%lld\n", ans);
    return 0;
}