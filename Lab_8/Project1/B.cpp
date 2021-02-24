
#include <stdio.h>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;




typedef struct Node
{
    int data;
    int key;
}List;

void upAdjust(List *p,int low, int high)
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


void display(List *p, int size) {
    for (int i = 1; i <= size; i++) {
        printf("%d ", p[i].data);
    }
    printf("\n");
}

void swap(List* p, int x, int y) {
    int key1 = p[x].data;
    p[x].data =p[y].data;
    p[y].data = key1;
    int key2 = p[x].key;
    p[x].key = p[y].key;
    p[y].key = key2;
}

void Find(List *p,int n,int k,int& x)
{
    for (int i = 1; i <= n; i++)
    {
        if (p[i].key == k)
        {
            x = i;
            break;
        }
    }


}


// 从小到大排序
void Down(List*array, int i, int n) { // 最后结果就是大顶堆
    int parent = i;                    // 父节点下标
    int child = 2 * i+1 ;            // 子节点下标
    while (child < n) {
        if (array[child].data < array[child + 1].data && child + 1 < n) { // 判断子节点那个大，大的与父节点比较
            child++;
        }
        if (array[parent].data < array[child].data) { // 判断父节点是否小于子节点
            swap(array, parent, child);     // 交换父节点和子节点
            parent = child;                 // 子节点下标 赋给 父节点下标
        }
        child = child * 2 + 1; // 换行，比较下面的父节点和子节点
    }
}

void BuildHeap(List *array, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) { // 倒数第二排开始, 创建大顶堆，必须从下往上比较
        Down(array, i, size);                 // 否则有的不符合大顶堆定义
    }
}

void HeapSort(List *array, int size) {
    //printf("初始化数组：");
    BuildHeap(array, size); // 初始化堆
    //display(array, size);   // 查看初始化结果
    for (int i = size - 1; i > 0; i--) {
        swap(array, 0, i); // 交换顶点和第 i 个数据
                           // 因为只有array[0]改变，其它都符合大顶堆的定义，所以可以从上往下重新建立
        Down(array, 0, i); // 重新建立大顶堆

        //printf("排序的数组：");
        //display(array, size);
    }
}

int main() 
{

    int T,n,cx,cy;
    cin >> T;
    while (T--)
    {
        cin >> n;
        List* p=new List[n+1];
        cin >> p[1].data;
        p[1].key = 1;
        if (n > 1)
        {
            for (int i = 2; i <= n; i++)
            {
                cin >> p[i].data;
                p[i].key = i;
                upAdjust(p, 1, i);

            }

        }      
        //HeapSort(p, n);
        int k;
        cin >> k;
        Find(p, n, k, cx);
        int temp = cx,high,position;
        if (temp == 1)
        {
            high = 1, position=1;
        }
        else
        {
                int i = 1;
                while( (pow(2, i)-1 )< temp)
                {
                    i++;                 
                }                           
                    high = i;
                    position = temp - (pow(2, i - 1)-1);                                      
        }
        cout << high << " " << position << endl;
        //display(p, n);

        delete[]p;
        p = NULL;
    }
    return 0;
}

