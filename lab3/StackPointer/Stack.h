#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};

struct Stack
{
	struct Node *top;
};
int error = 0;
const char error_msg[][50] = {
	"",
	"Stack xooson!"};
void init(struct Stack *s)
{
	s->top = NULL;
}
void release(struct Stack *s)
{
	free(s->top);
	free(s);
}
/* s Stackiig hooson esehiig shalgah. hooson bol 1-iig, hooson bish bolл 0-iig butsaana */
int empty(struct Stack *s)
{
	if (s->top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* s Stackd x utgiig nemeh */
void push(struct Stack *s, int x)
{
	Node *temp = new Node;
	temp->data = x;
	temp->next = s->top;
	s->top = temp;
}

/* s Stackees element utgah, ustaj bui elementiin utgiig butsaah */
int pop(struct Stack *s)
{
	Node *temp = s->top;
	if (temp == NULL)
	{
		error = 1;
		return 0;
	}
	s->top = temp->next;
	return temp->data;
}

/* s Stackiin oroi elementiin utgiig butsaah */
int top(struct Stack *s)
{
	if (s->top == NULL)
	{
		error = 1;
		return 0;
	}
	Node *temp = s->top;
	return temp->data;
}

/* s Stack niit heden elementteig tootsoolon butsaah */
int size(struct Stack *s)
{
	int size = 0;
	Node *temp = s->top;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}

	return size;
}
/* s Stackiin bukh elementiin utgiig hevleh */
void printStack(Stack *s)
{
	if (s->top == NULL)
	{
		error = 1;
	}

	Node *temp = s->top;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
/* q-ийн зааж буй Stack-с x тоог хайн олдсон байрлалаыг буцаана.
   Олдохгүй бол -1 утгыг буцаана.
 */
int find(struct Stack *s, int x)
{
	Node *temp = s->top;
	int pos = 0;
	while (temp != NULL)
	{
		pos++;
		if (temp->data == x)
		{
			return pos;
		}
		temp = temp->next;
	}
	return -1;
}

#endif
