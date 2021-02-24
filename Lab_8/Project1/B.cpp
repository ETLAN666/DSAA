
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


// ��С��������
void Down(List*array, int i, int n) { // ��������Ǵ󶥶�
    int parent = i;                    // ���ڵ��±�
    int child = 2 * i+1 ;            // �ӽڵ��±�
    while (child < n) {
        if (array[child].data < array[child + 1].data && child + 1 < n) { // �ж��ӽڵ��Ǹ��󣬴���븸�ڵ�Ƚ�
            child++;
        }
        if (array[parent].data < array[child].data) { // �жϸ��ڵ��Ƿ�С���ӽڵ�
            swap(array, parent, child);     // �������ڵ���ӽڵ�
            parent = child;                 // �ӽڵ��±� ���� ���ڵ��±�
        }
        child = child * 2 + 1; // ���У��Ƚ�����ĸ��ڵ���ӽڵ�
    }
}

void BuildHeap(List *array, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) { // �����ڶ��ſ�ʼ, �����󶥶ѣ�����������ϱȽ�
        Down(array, i, size);                 // �����еĲ����ϴ󶥶Ѷ���
    }
}

void HeapSort(List *array, int size) {
    //printf("��ʼ�����飺");
    BuildHeap(array, size); // ��ʼ����
    //display(array, size);   // �鿴��ʼ�����
    for (int i = size - 1; i > 0; i--) {
        swap(array, 0, i); // ��������͵� i ������
                           // ��Ϊֻ��array[0]�ı䣬���������ϴ󶥶ѵĶ��壬���Կ��Դ����������½���
        Down(array, 0, i); // ���½����󶥶�

        //printf("��������飺");
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

