#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

void StackInit(Stack* ps) {
	assert(ps);
	ps->_array = (SDataType*)malloc(sizeof(SDataType)*3);
	if (ps->_array == NULL) {
		assert(0);
		return;
	}
	ps->_capacity = 3;
	ps->_top = 0;
}

void StackDestory(Stack* ps) {
	assert(ps);
	if (ps->_array) {
		free(ps->_array);
		ps->_capacity = 0;
		ps->_top = 0;
	}
}

void CheckCapacity(Stack* ps) {
	assert(ps);
	if (ps->_capacity == ps->_top) {
		int newCapacity = ps->_capacity * 2;
		SDataType* pTemp = (SDataType*)malloc(sizeof(SDataType)*newCapacity);
		if (pTemp == NULL) {
			assert(0);
			return;
		}
		for (int i = 0; i < ps->_top; ++i) {
			pTemp[i] = ps->_array[i];
		}
		free(ps->_array);
		ps->_array = pTemp;
		ps->_capacity = newCapacity;
	}
}

void StackPush(Stack* ps, SDataType data) {
	CheckCapacity(ps);
	ps->_array[ps->_top++] = data;
}
void StackPop(Stack* ps) {
	assert(ps);
	if (StackEmpty(ps))
		return;
	ps->_top--;
}
SDataType StackTop(Stack* ps) {
	assert(ps);
	return ps->_array[ps->_top - 1];
}
int StackEmpty(Stack* ps) {
	assert(ps);
	return ps->_top == 0;
}
int StackSize(Stack* ps) {
	assert(ps);
	return ps->_top;
}

void TeatStack() {
	Stack s;
	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	printf("size=%d\n", StackSize(&s));
	printf("top=%d\n", StackTop(&s));
	StackPush(&s, 4);
	StackPush(&s, 5);
	printf("size=%d\n", StackSize(&s));
	printf("top=%d\n", StackTop(&s));

	StackPop(&s);
	StackPop(&s);
	printf("size=%d\n", StackSize(&s));
	printf("top=%d\n", StackTop(&s));

}

