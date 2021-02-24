#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

const int MAX = 200000 + 1000;

#define OK 1
#define ERROR 0

int main()
{
	int array[MAX];
	int T,i,j,temp,day;
	scanf("%d",&T);
	while (T--) {
		int n1;
		scanf("%d", &n1);
		for (i = 0; i < n1; i++) 
			scanf("%d", &array[i]);
		int n2;
		scanf("%d", &n2);
		int* p;
		p = (int*)malloc(n2 * (sizeof(int)));
		//if (p)
			//exit(-1);
		for (i = 0; i < n2; i++) {
			scanf("%d", &p[i]);
		}
		for (i = 0; i < n2; i++) {
			day= p[i];
			temp = array[day - 1];
			if (day == n1) {
				p[i] = -1;
			}
			for (j = day; j < n1; j++) {
				if (array[j] > temp) {
					p[i] = j - day + 1;
					break;
				}
				else
					p[i] = -1;
			}	
		}
		for (i = 0; i < n2; i++) {
			printf("%d\n", p[i]);
		}
		free(p);	
	}
	return 0;
}
