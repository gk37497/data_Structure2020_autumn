#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};

struct List
{
	struct Node *root;
};
int error = 0;
const char error_msg[][50] = {
	"",
	"List xooson!",
	"Bairlald oruulax bolomjgui!",
	"Bairlaas gargax bolomjgui!"};
void init(struct List *p, int n)
{
	p->root = NULL;
}

void release(struct List *p)
{
	free(p->root);
	p->root = NULL;
}
/* p-ийн зааж буй List хоосон бол 1 үгүй бол 0-ийг буцаана */
int empty(struct List *p)
{
	/* Энд хоосон эсэхийг шалгах үйлдлийг хийнэ */
	if (p->root == NULL)
	{
		return 1;
	}
	return 0;
}
/* p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
   pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
 */
void insert(struct List *p, int x, int pos)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
	Node *temp = new Node;
	Node *pointer = p->root;
	int counter = 0;
	temp->data = x;
	if (p->root == NULL)
	{
		if (pos > 0)
		{
			error = 2;
			return;
		}

		p->root = temp;
		temp->next = NULL;
	}
	else
	{
		if (pos == 0)
		{
			p->root = temp;
			temp->next = pointer;
		}
		while (pointer != NULL)
		{
			pointer = pointer->next;
			counter++;
		}
		if (counter + 1 <= pos)
		{
			error = 2;
			return;
		}
		else
		{
			counter = 0;
			pointer = p->root;
			while (counter != pos - 1)
			{
				pointer = pointer->next;
				counter++;
			}
			temp->next = pointer->next;
			pointer->next = temp;
		}
	}
}

/* p-ийн зааж буй List-н pos байралаас гарган буцаана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
 */
int removes(struct List *p, int pos)
{
	int counter = 0;
	Node *pointer = p->root;
	Node *temp;
	Node *saver = new Node;

	if (pointer == NULL)
	{
		return error = 1;
	}
	while (pointer->next != NULL)
	{
		pointer = pointer->next;
		counter++;
	}
	if (pos >= counter + 1)
	{
		return error = 3;
	}
	else
	{
		counter = 0;
		pointer = p->root;
		if (pos == 0)
		{
			temp = pointer;
			// temp = NULL;
			p->root = p->root->next;
			delete pointer;
			return temp->data;
		}
		else
		{
			while (counter != pos - 1)
			{
				pointer = pointer->next;
				counter++;
			}
			temp = pointer->next;
			saver = pointer->next;
			pointer->next = pointer->next->next;
			saver = NULL;
			delete saver;
			return temp->data;
		}
	}
}
/* p-ийн зааж буй List-н утгуудыг хэвлэнэ */
void print(struct List *p)
{
	Node *temp = p->root;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
/* p-ийн зааж буй List-с x тоог хайн олдсон байрлалаыг буцаана.
   Олдохгүй бол -1 утгыг буцаана.
 */
int find(struct List *p, int x)
{
	Node *temp = p->root;
	int pos = 0;
	while (temp != NULL)
	{
		if (temp->data == x)
		{
			return pos;
		}
		temp = temp->next;
		pos++;
	}
	return -1;
}

#endif
