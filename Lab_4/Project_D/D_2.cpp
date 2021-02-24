#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<vector>
#include <functional>


using namespace std;

int aa[300000];
int bb[300000];

class MedianFinder {
public:
	void addNum(int num);
	int find_median();
private:
	priority_queue<int,vector<int>,less<int>> max_heap;
	priority_queue<int,vector<int>,greater<int>> min_heap;
};

void MedianFinder::addNum(int num) {
	if (max_heap.empty()) {
		max_heap.push(num);
		return;
	}
	if (max_heap.size() == min_heap.size()) {
		if (num < max_heap.top()) {
			max_heap.push(num);
		}
		else {
			min_heap.push(num);
		}
	}
	else if (max_heap.size() < min_heap.size()) {
		if (num < max_heap.top()) {
			max_heap.push(num);
		}
		else {
			max_heap.push(min_heap.top());
			min_heap.pop();
			min_heap.push(num);
		}
	}
	else {
		if (num < max_heap.top()) {
			min_heap.push(max_heap.top());
			max_heap.pop();
			max_heap.push(num);
		}
		else {
			min_heap.push(num);
		}
	}
}
int MedianFinder::find_median() {
	if (max_heap.size() == min_heap.size()) {
		return (max_heap.top() + min_heap.top()) / 2;
	}
	else if (max_heap.size() < min_heap.size()) {
		return min_heap.top();
	}
	return max_heap.top();
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		MedianFinder a;
		int i, n;
		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%d", &aa[i]);
			a.addNum(aa[i]);
			bb[i] = a.find_median();
		}
		for (i = 0; i < n; i += 2)
		{
			printf("%d ", bb[i]);
		}
		printf("\n");
	}
	return 0;
}