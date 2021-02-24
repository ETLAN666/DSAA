#include<cstdio>
#include <iostream>

#pragma comment(linker, "/STACK:36777216")
using namespace std;


typedef long long int ll;
typedef int item;
struct Sub_Tree_Node {
    item left_child;
    item right_child;
    int size;
    ll value;
};
Sub_Tree_Node size_balanced_tree[(int)8e4 + 10];
int pet = 0, people = 0, operation, little, more, result;
struct node {
    ll p;
    ll d;
}a[110000];
ll answer = 0, num;
item Top_of_Tree;
typedef struct Node
{
    int data;
    int key;
}List;
item Root_of_Tree;

void swap(List* p, int x, int y) {
    int key1 = p[x].data;
    p[x].data = p[y].data;
    p[y].data = key1;
    int key2 = p[x].key;
    p[x].key = p[y].key;
    p[y].key = key2;
}

void upAdjust(List* p, int low, int high)
{
    int i = high, j = i / 2;
    while (j >= low)
    {
        if (p[j].data < p[i].data)
        {
            swap(p, j, i);
            i = j;
            j = i / 2;
        }
        else
            break;

    }
}
void Left_Rotation(int& x);

void Down(List* array, int i, int n) { 
    int parent = i;                    
    int child = 2 * i + 1;            
    while (child < n) {
        if (array[child].data < array[child + 1].data && child + 1 < n) { 
            child++;
        }
        if (array[parent].data < array[child].data) {
            swap(array, parent, child);   
            parent = child;                
        }
        child = child * 2 + 1; 
    }
}

void Right_Rotation(int& x);

void BuildHeap(List* array, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) { 
        Down(array, i, size);               
    }
}
void Protection(int& x, bool flag);
void Insert(int& x, ll val);
int Remove(int& x, ll val);
int Get_Min();
int Get_Max();
int Predor(int& x, int y, long long val);
int Succecced(int& x, int y, long long val);
int Find_the_K(int& x, int k);
int Rank(int& x, int val);

void HeapSort(List* array, int size) {
    
    BuildHeap(array, size); 
   
    for (int i = size - 1; i > 0; i--) {
        swap(array, 0, i); 
                           
        Down(array, 0, i); 

      
    }
}
int main() {
    int n;
    int  cx=0, cy=0,Root_counter=0, Root_fixer = 0;
    cin >> n;
    while (n--) {
        scanf("%d %lld", &operation, &num);
        result = 0;
        if (cx)
        {
            Root_counter++;
        }
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
        if (cx)
        {
            Root_fixer++;
        }
        if (cy)
        {
            Root_counter++;
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
        if (cx)
        {
            Root_counter++;
        }
    }
    cout << answer << endl;
    return 0;
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

int Rank(int& x, int val) {
    if (val < size_balanced_tree[x].value)
        return Rank(size_balanced_tree[x].left_child, val);
    else if (val > size_balanced_tree[x].value)
        return Rank(size_balanced_tree[x].right_child, val);
    else return size_balanced_tree[size_balanced_tree[x].left_child].size + 1;
}

int Succecced(int& x, int y, long long val) {
    if (x == 0) return y;
    if (size_balanced_tree[x].value > val)
        return Succecced(size_balanced_tree[x].left_child, x, val);
    else return Succecced(size_balanced_tree[x].right_child, y, val);
}

void Left_Rotation(int& x) {
    int y = size_balanced_tree[x].right_child;
    size_balanced_tree[x].right_child = size_balanced_tree[y].left_child;
    size_balanced_tree[y].left_child = x;
    size_balanced_tree[y].size = size_balanced_tree[x].size; 
    size_balanced_tree[x].size = size_balanced_tree[size_balanced_tree[x].left_child].size + size_balanced_tree[size_balanced_tree[x].right_child].size + 1;
    x = y;
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

int Predor(int& x, int y, long long val)

{
    if (x == 0) return y;
    if (size_balanced_tree[x].value < val)
        return Predor(size_balanced_tree[x].right_child, x, val);
    else return Predor(size_balanced_tree[x].left_child, y, val);
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

int Get_Max() {
    int x;
    for (x = Root_of_Tree; size_balanced_tree[x].right_child; x = size_balanced_tree[x].right_child);
    return size_balanced_tree[x].value;

}
int Find_the_K(int& x, int k) {
    int r = size_balanced_tree[size_balanced_tree[x].left_child].size + 1;
    if (r == k) return size_balanced_tree[x].value;
    else if (r < k) return Find_the_K(size_balanced_tree[x].right_child, k - r);
    else return Find_the_K(size_balanced_tree[x].left_child, k);
}


int Get_Min() { 
    int x;
    for (x = Root_of_Tree; size_balanced_tree[x].left_child; x = size_balanced_tree[x].left_child);
    return size_balanced_tree[x].value;
}