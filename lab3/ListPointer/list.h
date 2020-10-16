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
	temp->data = x;
	if (p->root == NULL)
	{
		p->root = temp;
	}
	else
	{
		int counter = 0;
		while (counter != pos)
		{
			pointer = pointer->next;
			counter++;
		}
		temp->next = pointer->next;
		pointer = temp;
	}

	// struct Node *temp = new Node;
	// temp->data = x;
	// p->root = temp;
	// for (int i = 0; i < pos; i++)
	// {
	// 	temp = temp->next;
	// }
	// temp = temp->next->next;
}

/* p-ийн зааж буй List-н pos байралаас гарган буцаана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
 */
int removes(struct List *p, int pos)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
	return 0;
}
/* p-ийн зааж буй List-н утгуудыг хэвлэнэ */
void print(struct List *p)
{
	Node *temp = p->root;
	/* Энд хэвлэх үйлдлийг хийнэ үү */
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
	int pos = 1;
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
