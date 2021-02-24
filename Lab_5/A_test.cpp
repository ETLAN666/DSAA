#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define	 STA_SIZE	50	//栈的大小
#define	 BUF_SIZE	50	//输入字符串的大小

//栈的声明
struct stack {
	char sta[STA_SIZE];
	int top;
};
//判断栈是否为空
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
//初始化栈
void init_stack(struct stack* psta)
{
	psta->top = -1;
	memset(psta->sta, 0,sizeof(char) * STA_SIZE);
}

//入栈操作
int push_stack(struct stack* psta, char data)
{
	if (if_full(psta)) {
		printf("stack is full. \n");
		exit(1);
	}
	(psta->top)++;
	psta->sta[psta->top] = data;
}
//出栈操作
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
//查看栈顶元素
char get_top_data(struct stack* psta)
{
	if (if_empty(psta) == 0) {
		return -1;
	}
	char tmp = psta->sta[psta->top];

	return tmp;
}
//括号匹配函数
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
	printf("请输入要检测的不超过50个字符的字符串：\n");
	fgets(buf, BUF_SIZE, stdin);
	int ret = bracket_match(&sta, buf);
	if (ret == 0)
		printf("括号检测匹配... \n");
	else
		printf("括号检测不匹配... \n");

	return 0;
}

