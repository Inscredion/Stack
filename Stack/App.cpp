#include "App.h"
#include "linkStack.h"
#include <stdio.h>
#include <stdlib.h>

void Calculator(char* s, int len) {
	int a, b;
	Stack S = CreateStack();
	for (int i = 0;i < len;i++) {
		if (s[i] < 9 && s[i] > 0)
			Push(S, s[i]);
		else {
			a = TopAndPop(S);
			b = TopAndPop(S);
			Push(S, Operator(s[i], b, a));
		}
	}
	printf("%d", Top(S));
}

int Operator(char s, int a, int b) {
	switch (s)
	{
	case '+':
		return a + b;
		break;
	case '-':
		return a - b;
		break;
	case '*':
		return a * b;
		break;
	case '/':
		return a / b;
		break;
	default:
		exit(0);
	}
}

int ArrayLength(char *s) {
	int i = 0;
	while (s[i] != '\0')
		++i;
	return i;
}

bool Match(char* c) {
	Stack S = CreateStack();
	for (int i = 0;i < 4;i++) {
		if (c[i] == '(' || c[i] == '[' || c[i] == '{')
			Push(S, c[i]);
		else if (c[i] == ')' || c[i] == ']' || c[i] == '}') {
			if (c[i] == ')' && TopAndPop(S) != '(')
				return false;
			if (c[i] == ']' && TopAndPop(S) != '[')
				return false;
			if (c[i] == '}' && TopAndPop(S) != '{')
				return false;
		}
	}
	return true;
}