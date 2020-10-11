#define HEADER_FILE
#include <stdlib.h>

struct Stack {
	int len;
	int *dat;
	int size;
};
int error = 0;
const char error_msg[][50] = {
	"",
	"Stack duuren!",
	"Stack xooson!"
};

void init(struct Stack *p, int n)
{
	p->len = n;
	p->size = 0;
	p->dat = (int *) malloc(sizeof(int) * n);
}

void release(struct Stack *p)
{
	free(p->dat);
	p->dat = NULL;
}
void prin(struct Stack *p){
	printf("%d  ", p->size);
	printf("%d\n\n", p->dat[p->size]);
}
/* p-ийн зааж буй Stack хоосон бол 1 үгүй бол 0-ийг буцаана */
int empty(struct Stack *p)
{
	/* Энд хоосон эсэхийг шалгах үйлдлийг хийнэ */
	if (p->size <= 0)return 1;
	else return 0; 
	
}

/* p-ийн зааж буй Stack-д x утгыг хийнэ */
void push(struct Stack *p, int x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
	p->dat[p->size] = x;
	p->size++;
}

/* p-ийн зааж буй Stack-с гарган буцаана */
int pop(struct Stack *p)
{
	if (p->size <= 0 )
	{
		error = 2;
	}
	
	/* Энд гаргах үйлдлийг хийнэ үү */
	int removed_el = p->dat[p->size-1];
	p->size--;
	if(p->size < 0) p->size = 0;
	return  removed_el;
}

/* p-ийн зааж буй Stack-н орой элементийг буцаана утгуудыг хэвлэнэ */
int top(struct Stack *p)
{
	if(p->size <= 0 )error=2;
	/* Энд орой элементийг буцаах үйлдэл хийнэ */
	return p->dat[p->size-1];
}


/* p-ийн зааж буй Stack-д хэдэн элемент байгааг буцаана.
   Queue-д өөрчлөлт оруулахгүй.
 */
int size(struct Stack *p)
{
	if (p->size < 0)
	{
		return 0;
	}else	return p->size;
}
