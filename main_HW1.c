#include<stdlib.h>
#include<stdio.h>
#include"ADT_stack.h"



int main() {
	STACK* stack1 = createStack();

	int a1 = 1;
	int a2 = 2;
	int a3 = 3;
	int a4 = 4;
	int a5 = 5;

	pushStack(stack1, &a1);
	pushStack(stack1, &a2);
	pushStack(stack1, &a3);
	pushStack(stack1, &a4);
	pushStack(stack1, &a5);

	int* bottom = stackBottom(stack1);
	printf("bottom value : %d\n\n", *bottom);
}