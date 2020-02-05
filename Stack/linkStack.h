//
// Created by zc on 2020/1/19.
//
#ifndef LINKSTACK_STACK_H
#define LINKSTACK_STACK_H

struct Node;
typedef Node* PtrNode;
typedef PtrNode Stack;

typedef int Status;
typedef int ElemType;

int IsEmpty(Stack S);
Stack CreateStack(void);
void MakeEmpty(Stack S);
void Push(Stack S,ElemType X);
void Pop(Stack S);
ElemType Top(Stack S);
ElemType TopAndPop(Stack S);
void Visit(Stack S);
int StackSize(Stack S);

#endif //LINKSTACK_STACK_H
