#pragma once

typedef int SDataType;
typedef struct Stack
{
	SDataType* _array;//ָ��һ�οռ��������ջ��Ԫ��
	int _top;//ջ��������ЧԪ�صĸ���
	int _capacity;//����
}Stack;

void StackInit(Stack* ps);//ջ�ĳ�ʼ��
void StackDestory(Stack* ps);//����ջ

void StackPush(Stack* ps, SDataType data);//��ջ
void StackPop(Stack* ps);//��ջ
SDataType StackTop(Stack* ps);//�鿴ջ��Ԫ��
int StackEmpty(Stack* ps);//ջ�Ƿ�Ϊ��
int StackSize(Stack* ps);//ջ�е���ЧԪ�ظ���
void TeatStack();