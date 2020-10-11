#define HEADER_FILE
#include <stdlib.h>

struct Queue {
	int len;
	int *dat;
	int size;
};
void prin(struct Queue *p){
	printf("%d  ", p->size);
	printf("%d\n", p->dat[p->size]);
}
int error = 0;
const char error_msg[][50] = {
	"",
	"Queue duuren!",
	"Queue xooson!"
};

void init(struct Queue *p, int n)
{
	p->len = n;
	p->size = 0;
	p->dat = (int *) malloc(sizeof(int) * n);
}

void release(struct Queue *p)
{
	free(p->dat);
	p->dat = NULL;
}
/* p-ийн зааж буй Queue хоосон бол 1 үгүй бол 0-ийг буцаана */
int empty(struct Queue *p)
{
	/* Энд хоосон эсэхийг шалгах үйлдлийг хийнэ */
	if (p->size <= 0)return 1;
	else return 0;
	
}

/* p-ийн зааж буй Queue-д x утгыг хийнэ */
void enqueue(struct Queue *p, int x)
{
	if(p->size == p->len)error = 2;
	/* Энд оруулах үйлдлийг хийнэ үү */
	p->dat[p->size] = x;
	p->size++;
	
}

/* p-ийн зааж буй Queue-с гарган буцаана */
int dequeue(struct Queue *p)
{
	if (p->size <= 0){
		error = 2;
	}
	
	/* Энд гаргах үйлдлийг хийнэ үү */
	int removed_el = p->dat[0];
	for (int i = 0; i < p->size; i++)
	{
		p->dat[i] = p->dat[i+1];
	}	
	p->size--;
	if(p->size < 0)p->size = 0;
	return removed_el;
}

/* p-ийн зааж буй Queue-н утгуудыг хэвлэнэ */
void print(struct Queue *p)
{
	/* Энд хэвлэх үйлдлийг хийнэ үү */
	for (int i = 0; i < p->size; i++)
	{
		printf("%d   ",p->dat[i]);
	}
	printf("\n");
	
}

/* p-ийн зааж буй Queue-н хамгийн эхний элементийн утгыг буцаана.
   Гаргах үйлдэл хийхгүй.
 */
int front(struct Queue *p)
{
	if(p->size <= 0)error = 2;
	return p->dat[0];
}
/* p-ийн зааж буй Queue-н хамгийн сүүлийн элементийн утгыг буцаана.
   Queue-д өөрчлөлт оруулахгүй.
 */
int back(struct Queue *p)
{
	if(p->size <= 0)error = 2;
	return p->dat[p->size-1];
}
/* p-ийн зааж буй Queue-д хэдэн элемент байгааг буцаана.
   Queue-д өөрчлөлт оруулахгүй.
 */
int size(struct Queue *p)
{
	if(p->size <= 0)error = 2;
	return p->size;
}
