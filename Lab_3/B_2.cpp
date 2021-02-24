#include <iostream>
#include <vector>
#include <iterator>
#include<cstdio>
#include<cstdlib>
using namespace std;
 
int min(int x, int y){
    return (x < y) ? x : y;
}
 
vector<int> Merge(vector<int> &data, int begin, int mid, int end){    
    int n1 = mid - begin + 1;
    int n2 = end - mid;
    int left[n1], right[n2];
    for(int i = 0; i < n1; i++){
        left[i] = data[begin+i];
    }
    for(int i = 0; i < n2; i++){
        right[i] = data[mid + i + 1];
    }
    int i = 0, j = 0, k = begin;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            data[k++] = left[i++];
        }else{
            data[k++] = right[j++];
        }
    }
    while(i < n1){
        data[k++] = left[i++];
    }
    while(j < n2){
        data[k++] = right[j++];
    }
    return data;
}
 
vector<int> MergeSort(vector<int> data){
    vector<int> res;
    if(data.empty()){
        return res;
    }
    unsigned int i = 1;
    while(i < data.size()){
        for(unsigned int begin = 0; begin < data.size(); begin += 2*i){
            int mid = begin + i - 1;
            int end = min(begin + 2 * i -1, data.size()-1);
            res = Merge(data, begin, mid, end);
        }
        i = 2 * i;
    }
    return res;
}
 
void printVec(vector<int> &vec){
    if(vec.empty()){
        return ;
    }
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
        cout<< *it << " ";
    }
    cout << endl;
}
 
int main()
{
    int i,n, k,*aa,*bb;
	cin >> n >> k;
	aa = (int*)calloc(n, sizeof(int));
	for (i = 0; i < n; i++)
		cin >> aa[i];
    vector<int> vec(aa, aa + 6);
    vector<int> res;
    res = MergeSort(vec);
    cout << res[k-1];
    return 0;
}
