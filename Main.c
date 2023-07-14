
/* Please be aware that the code in its current state is in the initial phase and has undergone minimal testing. It is strongly recommended to thoroughly test and make any necessary modifications before utilizing it. */
/* I cannot be held responsible for any issues or difficulties arising from using the code without making appropriate modifications. */
/* basic stack implementation in C */
/*
basic stack implementation in C
File: Main.c
Author: Malkoot Khan
Date: 14/07/2023
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true }bool;

struct Stack {
	int capacity;
	int top;
	int* data;
};

struct Stack* createStack(int cap) {
	struct Stack* stk = (struct Stack*)malloc(sizeof(struct Stack));
	stk->capacity = cap;
	stk->top = -1;
	stk->data = (int*)malloc(sizeof(int) * stk->capacity);
	return stk;
}
bool isFull(struct Stack* stk) {
	if (stk->top == stk->capacity - 1)
		return true;
	return false;
}
bool isEmpty(struct Stack* stk) {
	if (stk->top == -1)
		return true;
	return false;
}
void push(struct Stack* stk, int item) {
	if (isFull(stk)) {
		printf(" stack overflow!\n");
		return;
	}
	stk->top++;
	stk->data[stk->top] = item;
}
void pop(struct Stack* stk) {
	if (isEmpty(stk)) {
		printf("stack underflow!\n");
		return;
	}
	stk->data[stk->top];
	stk->top--;
}
void display(struct Stack* stk) {
	int top = stk->top;
	if (isEmpty(stk)) {
		printf("stack underflow!\n");
		return;
	}
	while (top >= 0) {
		printf("%d ",stk->data[top]);
		top--;
	}
	printf("\n");
}
int PEEK(struct Stack* stk) {
	if (isEmpty(stk)) {
		printf("stack underflow!\n");
		return -1;
	}
	return stk->data[stk->top];	
}
void release(struct Stack* stk) {
	free(stk->data);
	free(stk);
}
int main() {
	struct Stack* stk = createStack(10);
	push(stk, 10);
	push(stk, 20);
	push(stk, 30);
	push(stk, 40);
	display(stk);
	printf("The top element: %d\n", PEEK(stk));
	pop(stk);
	display(stk);
	pop(stk);
	display(stk);
	release(stk);

	return 0;
}

