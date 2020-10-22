#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};

struct Queue
{
	struct Node *head;
	struct Node *tail;
};
int error = 0;
const char error_msg[][50] = {
	"",
	"Queue xooson!"};
void init(struct Queue *q)
{
	q->head = NULL;
	q->tail = NULL;
}
void release(struct Queue *q)
{
	free(q->head);
	q->head = NULL;
	free(q->tail);
	q->tail = NULL;
}
/* q-ийн зааж буй Queue хоосон бол 1 үгүй бол 0-ийг буцаана */
int empty(struct Queue *q)
{
	/* Энд хоосон эсэхийг шалгах үйлдлийг хийнэ */
	if (q->head == NULL && q->tail == NULL)
	{
		return 1;
	}
	else
		return 0;
}
/* q-ийн зааж буй Queue-д x утгыг хийнэ */
void enQueue(struct Queue *q, int x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
	struct Node *temp = new Node;
	temp->data = x;
	temp->next = NULL;
	if (q->head == NULL && q->tail == NULL)
	{
		q->head = q->tail = temp;
	}
	if (q->head == NULL)
	{
	}

	else
	{
		q->tail->next = temp;
		q->tail = temp;
	}
}

/* q-ийн зааж буй Queue-с гарган буцаана */
int deQueue(struct Queue *q)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
	if (q->head == NULL)
	{
		return error = 1;
	}
	struct Node *temp = q->head;
	struct Node *haha = temp;
	q->head = q->head->next;
	delete temp;
	return haha->data;
}

/* q-ийн зааж буй Queue-н утгуудыг хэвлэнэ */
void print(struct Queue *q)
{
	struct Node *temp = q->head;
	while (temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

/* q-ийн зааж буй Queue-н хамгийн эхний элементийн утгыг буцаана.
   Гаргах үйлдэл хийхгүй.
 */
int front(struct Queue *q)
{
	if (q->tail == NULL && q->head == NULL)
	{
		return error = 1;
	}
	return q->head->data;
}
/* q-ийн зааж буй Queue-н хамгийн сүүлийн элементийн утгыг буцаана.
   Queue-д өөрчлөлт оруулахгүй.
 */
int back(struct Queue *q)
{
	if (q->tail == NULL && q->head == NULL)
	{
		return error = 1;
	}

	return q->tail->data;
}
/* q-ийн зааж буй Queue-д хэдэн элемент байгааг буцаана.
   Queue-д өөрчлөлт оруулахгүй.
 */
int size(struct Queue *q)
{
	int size;
	Node *temp = q->head;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return size;
}
/* q-ийн зааж буй queue-с x тоог хайн олдсон байрлалаыг буцаана.
   Олдохгүй бол -1 утгыг буцаана.
 */
int find(struct Queue *q, int x)
{
	Node *temp = q->head;
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
