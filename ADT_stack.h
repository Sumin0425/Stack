#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct node {
	void* dataPtr;
	struct node* link;
}STACK_NODE;

typedef struct {
	int count;
	STACK_NODE* top;
}STACK;

STACK* createStack(void)
{
	STACK* stack;
	stack = (STACK*)malloc(sizeof(STACK));
	if (stack)
	{
		stack->count = 0;
		stack->top = NULL;
	}
	return stack;
}

bool pushStack(STACK* stack, void* In)
{
	STACK_NODE* new_node;
	new_node = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if (!new_node)
		return false;
	new_node->dataPtr = In;
	if (stack->count == 0)
	{
		stack->top = new_node;
		new_node->link = NULL;
		(stack->count)++;
	}
	else
	{
		new_node->link = stack->top;
		stack->top = new_node;
		(stack->count)++;
	}
	return true;
}



void* popStack(STACK* stack)
{
	if (stack->count == 0)
		return NULL;
	else {
		STACK_NODE* backup;
		backup = stack->top;
		void* dataout = stack->top->dataPtr;
		stack->top = stack->top->link;
		free(backup);
		(stack->count)--;
		return dataout;
	}
}


void* stackBottom(STACK* stack)
{
	if (stack->count == 0)
		return NULL;
	else
	{
		while (stack->count >= 2)
			popStack(stack);
	}

	void* dataout = stack->top->dataPtr;
	return dataout;
}

STACK* destroyStack(STACK* stack)
{
	STACK_NODE* temp;

	if (stack)
	{
		while (stack->top != NULL) {
			free(stack->top->dataPtr);
			temp = stack->top;
			stack->top = stack->top->link;
			free(temp);
		}
		free(stack);
	}
	return NULL;
}

bool emptyStack(STACK* stack)
{
	return(stack->count == 0);
}

