#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

//�ǵݹ�
void MergeSortNonRecursion(int arr[],int length)//length��ʾ���鳤��
{
	int i,j,*tmp;
	tmp = (int*)calloc(length, sizeof(int));
	int step=1;
	
	while(step<length)//���ڲ���С��length�������ı�Ȼ����
	{
		 i=0;//��������仯
		int left,right,leftToPos,rightToPos;
		while(i<length)
		{
			left=i;leftToPos=left+step-1;
			right=leftToPos+1;//��֤ʣ�µĲ��ֲ���low+stepʱ��ʣ�ಿ��
			rightToPos=right+step-1>length-1?length-1:right+step-1;
			int p=left;int q=right;int k=left;
			while(p<=leftToPos&&q<=rightToPos)
			{
				if(arr[p]>arr[q])//����
				{
					tmp[k++]=arr[q++];
				}else
				{
					tmp[k++]=arr[p++];
				}
			}
			if(p<=leftToPos)
			{
				while(p<=leftToPos)
					tmp[k++]=arr[p++];
			}
			if(q<=rightToPos)
			{
				while(q<=rightToPos)
					tmp[k++]=arr[q++];
			}
			//������arr
			for( j=left;j<=rightToPos;j++)
			{
				arr[j]=tmp[j];
			}
			i+=2*step;
		}
		step*=2;
	}
	free(tmp);
}

int main()
{
	int i,n, k,*aa,*bb;
	cin >> n >> k;
	aa = (int*)calloc(n, sizeof(int));
	for (i = 0; i < n; i++)
		cin >> aa[i];
	//MergeSort(aa, 0, n-1);
	MergeSortNonRecursion(aa,n);
	cout << aa[k - 1];
	return 0;


}
