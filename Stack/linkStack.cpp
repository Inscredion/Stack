//
// Created by zc on 2020/1/19.
//
#include "linkStack.h"
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    ElemType Ele;
    PtrNode Next;
};

int IsEmpty(Stack S) {
    return S->Next == NULL;
}

Stack CreateStack(void){
    Stack S = (Stack)malloc(sizeof(Node));
    if (S == NULL) {
        printf("ERROR! Stack is null!");
        exit(1);
    }
    S->Next = NULL;
    return S;
}

void MakeEmpty(Stack S) {
    if (S == NULL) {
        printf("ERROR! Stack is null !");
        exit(1);
    }
    while (!IsEmpty(S))
    {
        Pop(S);
    }
}

void Push(Stack S,ElemType X) {
    PtrNode TmpCell;
    TmpCell = (PtrNode)malloc(sizeof(Node));
    if (TmpCell == NULL) {
        printf("ERROR!,allocate failed!");
    }
    TmpCell->Ele = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}

void Pop(Stack S) {
    PtrNode Tmp = S->Next;
    S->Next = S->Next->Next;
    free(Tmp);
}

ElemType Top(Stack S) {
    if (!IsEmpty(S))
        return S->Next->Ele;
    else
    {
        printf("ERROR! S is a empty stack");
        return 0;
    }
}

ElemType TopAndPop(Stack S) {
    ElemType Res = Top(S);
    Pop(S);
    return Res;
}

void Visit(Stack S) {
    if (IsEmpty(S)) {
        printf_s("ERROR! The Stack is empty!");
        exit(1);
    }
    printf("±éÀú¿ªÊ¼£º");
    Stack Tmp = S->Next;
    while (Tmp != NULL)
    {
        printf("%d ", Tmp->Ele);
        Tmp = Tmp->Next;
    }
    printf("\n");
}

int StackSize(Stack S) {
    if (IsEmpty(S)) {
        printf_s("ERROR! The Stack is empty!");
        return 0;
    }
    Stack Tmp = S->Next;
    int len = 0; 
    while (Tmp != NULL)
    {
        len++;
        Tmp = Tmp->Next;
    }
    return len;
}