#pragma once

typedef int SDataType;
typedef struct Stack
{
	SDataType* _array;//指向一段空间用来存放栈的元素
	int _top;//栈顶或者有效元素的个数
	int _capacity;//容量
}Stack;

void StackInit(Stack* ps);//栈的初始化
void StackDestory(Stack* ps);//销毁栈

void StackPush(Stack* ps, SDataType data);//入栈
void StackPop(Stack* ps);//出栈
SDataType StackTop(Stack* ps);//查看栈顶元素
int StackEmpty(Stack* ps);//栈是否为空
int StackSize(Stack* ps);//栈中的有效元素个数
void TeatStack();