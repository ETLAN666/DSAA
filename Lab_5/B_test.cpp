#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

#define OK 1
#define ERROR 0

typedef struct LNode{
	int Data;
	struct LNode* next;
}Node;

typedef struct LinkQueue{
	Node* front;
	Node* rear;
}LinkQueue;

void LinkQueueInit(LinkQueue* Q){
	(*Q).front = (*Q).rear = (Node*)malloc(sizeof(Node));
	if ((*Q).front == NULL)
		exit(-1);
	(*Q).front->next = NULL;
}
int IsEmpty(LinkQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
int EnQueue(LinkQueue* Q, int e) {
	Node* q = NULL;
	q = (Node*)malloc(sizeof(Node));
	if (q == NULL)
		exit(-1);
	q->Data = e;
	q->next = NULL;
	(*Q).rear->next = q;
	(*Q).rear = q;
	return OK;
}

int DeQueue(LinkQueue* Q) {
	Node* q = NULL;
	if (IsEmpty(*Q) == true)
		return ERROR;
	q = (*Q).front->next;
	(*Q).front->next = q->next;
	if ((*Q).rear == q)
		(*Q).rear = (*Q).front;
	free(q);
	return OK;
}

void Print_Queue(LinkQueue Q) {
	Node* p=NULL;
	p = Q.front->next;
	while (p->next) {
		printf("%d ", p->Data);
		p = p->next;
	}
	printf("%d", p->Data);

}

int main()
{
	LinkQueue Q;
	LinkQueueInit(&Q);
	int n,e,count=0;
	scanf("%d",&n);
	char ch[2];
	while (n--) {
		scanf("%s",&ch);
		switch (ch[0]) {
		case 'E':
			scanf("%d",&e);
			EnQueue(&Q, e);
			break;
		case 'A':
			if (IsEmpty(Q) == true)
				count++;
			else
				printf("%d\n", Q.front->next->Data);
			break;
		case 'D':
			DeQueue(&Q);
			break;
		}
	}
	if (IsEmpty(Q) == true)
		count++;
	else {
		Print_Queue(Q);
	}
	return 0;
}
