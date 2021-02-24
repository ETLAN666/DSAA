#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define	 STA_SIZE	50	//ջ�Ĵ�С
#define	 BUF_SIZE	50	//�����ַ����Ĵ�С

//ջ������
struct stack {
	char sta[STA_SIZE];
	int top;
};
//�ж�ջ�Ƿ�Ϊ��
int if_empty(struct stack* psta)
{
	if (psta->top == -1)
		return 0;
	else
		return 1;
}

int if_full(struct stack* psta)
{
	if (psta->top == STA_SIZE - 1)
		return 1;
	else
		return 0;
}
//��ʼ��ջ
void init_stack(struct stack* psta)
{
	psta->top = -1;
	memset(psta->sta, 0,sizeof(char) * STA_SIZE);
}

//��ջ����
int push_stack(struct stack* psta, char data)
{
	if (if_full(psta)) {
		printf("stack is full. \n");
		exit(1);
	}
	(psta->top)++;
	psta->sta[psta->top] = data;
}
//��ջ����
char pop_stack(struct stack* psta)
{
	if (if_empty(psta) == 0) {
		printf("stack is empty. \n");
		exit(1);
	}
	char tmp = psta->sta[psta->top];
	(psta->top)--;

	return tmp;
}
//�鿴ջ��Ԫ��
char get_top_data(struct stack* psta)
{
	if (if_empty(psta) == 0) {
		return -1;
	}
	char tmp = psta->sta[psta->top];

	return tmp;
}
//����ƥ�亯��
int bracket_match(struct stack* sta, char* string)
{
	char* ps = string;
	while (*ps != '\0') {
		switch (*ps) {
		case '(':
		case '{':
		case '[':
		case '<':
			push_stack(sta, *ps);
			break;
		case ')':
			if ('(' == (get_top_data(sta))) {
				pop_stack(sta);
				break;
			}
			else
				goto err;
		case '}':
			if ('{' == (get_top_data(sta))) {
				pop_stack(sta);
				break;
			}
			else
				goto err;
		case ']':
			if ('[' == (get_top_data(sta))) {
				pop_stack(sta);
				break;
			}
			else
				goto err;
		case '>':
			if ('<' == (get_top_data(sta))) {
				pop_stack(sta);
				break;
			}
			else
				goto err;
		default:
			break;
		}
		ps++;
	}
	if (if_empty(sta) == 0)
		ok:
	return 0;
	else
		err:
	return 1;
}
int main(int argc, char* argv[])
{
	struct stack sta;

	init_stack(&sta);

	char buf[BUF_SIZE] = { 0 };

	//	char* buf = "he({ljfs})jfkdjs";
	printf("������Ҫ���Ĳ�����50���ַ����ַ�����\n");
	fgets(buf, BUF_SIZE, stdin);
	int ret = bracket_match(&sta, buf);
	if (ret == 0)
		printf("���ż��ƥ��... \n");
	else
		printf("���ż�ⲻƥ��... \n");

	return 0;
}

