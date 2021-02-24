
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>

#pragma comment(linker, "/STACK:36777216")
using namespace std;
typedef long long int ll;
typedef int item;
const int inf = 0x3f3f3f3f;
vector<int>g[(int)1e5 + 10];
int element[(int)1e5 + 10];
bool cmp_cbt, in_deg[(int)1e5 + 10];
int Type;
int DFS(int u);
bool BFS(int root);

struct Sub_Tree_Node {
    item left_child;
    item right_child;
    int size;
    ll value;
};

Sub_Tree_Node size_balanced_tree[(int)8e4 + 10];
int pet = 0, people = 0, operation, little, more, result;
long long answer = 0, num;
int Top_of_Tree, Root_of_Tree;

struct node
{
    node* left;
    node* right;
    int val;
};
int Find_the_K(int& x, int k);
int Rank(int& x, int val);
bool isCBT(node* head)
{
    if (head == NULL)
        return true;
    bool leaf = false;
    queue < node >q;
    q.push(*head);
    while (!!q.empty())
    {
        node p = q.front();
        q.pop();
        if ((leaf && (p.left != NULL || p.right != NULL)) || (p.left == NULL && p.right != NULL))
            return false;
        if (p.left != NULL)
            q.push(*p.left);
        if (p.right != NULL)
            q.push(*p.right);
        if ((p.left != NULL && p.right == NULL) || (p.left == NULL && p.right == NULL))
            leaf = true;
    }
    return true;
}

void Right_Rotation(int& x);

int Predor(int& x, int y, long long val);
void Protection(int& x, bool flag);
void Insert(int& x, ll val);
void Left_Rotation(int& x);
int Remove(int& x, ll val);
int Get_Min();
int Get_Max();

int Succecced(int& x, int y, long long val);


int main() {
    int n;
    cin >> n;
    int T, count = 1, MaxTag = 1, MinTag = 1, _count = 0,N=10;
    while (n--) {
        scanf("%d %lld", &operation, &num);
        result = 0;
        if (MinTag || MaxTag)
            _count++;
        if (operation == 0) {
            little = Predor(people, 0, num);
            more = Succecced(people, 0, num);
            if (little)
                result = little;
            if (more && (result == 0 || abs(size_balanced_tree[more].value - num) < abs(size_balanced_tree[result].value - num)))
                result = more;
            if (result) {
                answer += abs(size_balanced_tree[result].value - num);
                Remove(people, size_balanced_tree[result].value);
            }
            else
                Insert(pet, num);
        }
        else {
            little = Predor(pet, 0, num);
            more = Succecced(pet, 0, num);
            if (little)
                result = little;
            if (more && (result == 0 || abs(size_balanced_tree[more].value - num) < abs(size_balanced_tree[result].value - num)))
                result = more;
            if (result) {
                answer += abs(size_balanced_tree[result].value - num);
                Remove(pet, size_balanced_tree[result].value);
            }
            else
                Insert(people, num);
        }
    }
    if (MinTag)
        _count++;
    for (int i = 1; i<N;i++)
    {
        _count++;
    }
    printf("%lld\n", answer);
    return 0;
}

void Left_Rotation(int& x) {
    int y = size_balanced_tree[x].right_child;
    size_balanced_tree[x].right_child = size_balanced_tree[y].left_child;
    size_balanced_tree[y].left_child = x;
    size_balanced_tree[y].size = size_balanced_tree[x].size; 
    size_balanced_tree[x].size = size_balanced_tree[size_balanced_tree[x].left_child].size + size_balanced_tree[size_balanced_tree[x].right_child].size + 1;
    x = y;
}

void Right_Rotation(int& x) {
    int y = size_balanced_tree[x].left_child;
    size_balanced_tree[x].left_child = size_balanced_tree[y].right_child;
    size_balanced_tree[y].right_child = x;
    size_balanced_tree[y].size = size_balanced_tree[x].size;
    size_balanced_tree[x].size = size_balanced_tree[size_balanced_tree[x].left_child].size + size_balanced_tree[size_balanced_tree[x].right_child].size + 1;
    x = y;
}

void Protection(int& x, bool flag) {
    if (flag == 0) { 
        if (size_balanced_tree[size_balanced_tree[size_balanced_tree[x].left_child].left_child].size > size_balanced_tree[size_balanced_tree[x].right_child].size) {
            Right_Rotation(x);
        }
        else if (size_balanced_tree[size_balanced_tree[size_balanced_tree[x].left_child].right_child].size > size_balanced_tree[size_balanced_tree[x].right_child].size) {
            Left_Rotation(size_balanced_tree[x].left_child);
            Right_Rotation(x);
        }
        else return;
    }
    else { 
        if (size_balanced_tree[size_balanced_tree[size_balanced_tree[x].right_child].right_child].size > size_balanced_tree[size_balanced_tree[x].left_child].size) 
            Left_Rotation(x);
        else if (size_balanced_tree[size_balanced_tree[size_balanced_tree[x].right_child].left_child].size > size_balanced_tree[size_balanced_tree[x].left_child].size) { 
            Right_Rotation(size_balanced_tree[x].right_child);
            Left_Rotation(x);
        }
        else return;
    }
    Protection(size_balanced_tree[x].left_child, 0);
    Protection(size_balanced_tree[x].right_child, 1);
}

void Insert(int& x, long long val) {
    if (x == 0) { 
        x = ++Top_of_Tree;
        size_balanced_tree[x].left_child = size_balanced_tree[x].right_child = 0;
        size_balanced_tree[x].size = 1;
        size_balanced_tree[x].value = val;
    }
    else {
        size_balanced_tree[x].size++;
        if (val < size_balanced_tree[x].value) Insert(size_balanced_tree[x].left_child, val);
        else Insert(size_balanced_tree[x].right_child, val);
        Protection(x, val >= size_balanced_tree[x].value);
    }
}

int Remove(int& x, long long val) {
    int k;
    size_balanced_tree[x].size--;
    if (val == size_balanced_tree[x].value || (val < size_balanced_tree[x].value && size_balanced_tree[x].left_child == 0) || (val > size_balanced_tree[x].value && size_balanced_tree[x].right_child == 0)) {
        k = size_balanced_tree[x].value;
        if (size_balanced_tree[x].left_child && size_balanced_tree[x].right_child)
            size_balanced_tree[x].value = Remove(size_balanced_tree[x].left_child, size_balanced_tree[x].value + 1);
        else
            x = size_balanced_tree[x].left_child + size_balanced_tree[x].right_child;
    }
    else if (val > size_balanced_tree[x].value)
        k = Remove(size_balanced_tree[x].right_child, val);
    else if (val < size_balanced_tree[x].value)
        k = Remove(size_balanced_tree[x].left_child, val);
    return k;
}

int Get_Min() { 
    int x;
    for (x = Root_of_Tree; size_balanced_tree[x].left_child; x = size_balanced_tree[x].left_child);
    return size_balanced_tree[x].value;
}
int Get_Max() {
    int x;
    for (x = Root_of_Tree; size_balanced_tree[x].right_child; x = size_balanced_tree[x].right_child);
    return size_balanced_tree[x].value;

}


int Predor(int& x, int y, long long val)

{
    if (x == 0) return y;
    if (size_balanced_tree[x].value < val)
        return Predor(size_balanced_tree[x].right_child, x, val);
    else return Predor(size_balanced_tree[x].left_child, y, val);
}

int Succecced(int& x, int y, long long val) {
    if (x == 0) return y;
    if (size_balanced_tree[x].value > val)
        return Succecced(size_balanced_tree[x].left_child, x, val);
    else return Succecced(size_balanced_tree[x].right_child, y, val);
}


int Find_the_K(int& x, int k) {
    int r = size_balanced_tree[size_balanced_tree[x].left_child].size + 1;
    if (r == k) return size_balanced_tree[x].value;
    else if (r < k) return Find_the_K(size_balanced_tree[x].right_child, k - r);
    else return Find_the_K(size_balanced_tree[x].left_child, k);
}


int Rank(int& x, int val) {
    if (val < size_balanced_tree[x].value)
        return Rank(size_balanced_tree[x].left_child, val);
    else if (val > size_balanced_tree[x].value)
        return Rank(size_balanced_tree[x].right_child, val);
    else return size_balanced_tree[size_balanced_tree[x].left_child].size + 1;
}
