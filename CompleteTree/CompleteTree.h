#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
struct Tree
{
	int len;  // Нийт багтаамж
	int size; // Одоогийн хэмжээ
	int *dat; // Өгөгдөл хадгалах хүснэгтийг заах хаяг
};

int error = 0;
const char error_msg[][50] = {
	"",
	"Mod duuren!",
	"Mod hooson!",
};

void init(struct Tree *p, int n)
{
	p->len = n;
	p->size = 0;
	p->dat = (int *)malloc(sizeof(int) * n);
}

void release(struct Tree *p)
{
	free(p->dat);
	p->dat = NULL;
}
// void printLEN(struct Tree *p)
// {
// 	printf("len =  %d \n", p->len);
// 	printf("size =  %d \n", p->size);
// }
/* p-ийн зааж буй Tree-с x тоог хайн олдсон байрлалыг буцаана.
   Олдохгүй бол -1 утгыг буцаана.
 */
int find(struct Tree *p, int x)
{
	for (int i = 0; i < p->len; i++)
	{
		if (x == p->dat[i])
		{
			return i;
		}
	}
	return -1;
}

/* p-ийн зааж буй модноос idx-ээр root хийсэн дэд модны  Tree-ийн өндрийг буцаана */
int height(struct Tree *p, int idx)
{
	int hei = 0;
	while (idx > 0)
	{
		idx = (idx - 1) / 2;
		hei++;
	}
	return hei;
}

/* p-ийн зааж буй Tree-д x утгыг оруулна */
void add(struct Tree *p, int x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
	p->dat[p->size] = x;
	p->size++;
}

/* p-ийн зааж буй Tree-с idx дугаартай зангилаанаас доошхи бүх навчийг олно */
void leaves(struct Tree *p, int idx)
{
	/* Энд навчуудыг үйлдлийг хийнэ үү */

	int pos = idx;
	if (idx < p->size)
	{
		if (idx * 2 + 1 > p->size)
		{
			printf("%d \n", p->dat[idx]);
		}
		leaves(p, idx * 2 + 1);
		leaves(p, idx * 2 + 2);
	}
}

/* p-ийн зааж буй Tree-д idx зангилаанаас доошхи бүх үр садыг хэвлэнэ  */
void descendants(struct Tree *p, int idx)
{
	if (idx < p->len)
	{
		printf("%d \n", p->dat[idx]);
		descendants(p, idx * 2 + 1);
		descendants(p, idx * 2 + 2);
	}
	/* Энд үр садыг олох үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй Tree-д idx зангилаанаас дээшхи бүх өвөг эцэгийг олох үйлдлийг хийнэ */
void ancestors(struct Tree *p, int idx)
{
	if (idx == 0)
	{
		printf("%d\n", p->dat[0]);
	}
	else
	{
		printf("%d->", p->dat[idx]);
		ancestors(p, idx = (idx - 1) / 2);
	}
}

/* p-ийн зааж буй Tree-д idx дугаартай зангилааны ах, дүүгийн зангилааны дугаарыг буцаана
   (Нэг эцэгтэй зангилаа). Байхгүй бол -1-г буцаана
 */
int sibling(struct Tree *p, int idx)
{
	if (0 == idx % 2)
		return idx - 1;
	if (0 != idx % 2 && idx + 1 < p->size)
		return idx + 1;
	else
		return -1;
}

/* p-ийн зааж буй Tree-д idx дугаартай зангилааны хүүхдүүдийн утгыг хэвлэ.
 */
void children(struct Tree *p, int idx)
{
	// /* Энд хүүхдүүдийн утгыг хэвлэх үйлдлийг хийнэ үү */
	int k = idx * 2;
	if (k + 1 > p->len)
	{
		printf("Huuhedgui !!!\n");
	}
	else if (k + 2 >= p->len && k + 1 <= p->len)
	{
		printf("%d\n", p->dat[k + 1]);
	}
	else
	{
		printf("%d\n", p->dat[k + 1]);
		printf("%d\n", p->dat[k + 2]);
	}
}
/* p-ийн зааж буй Tree-д idx дугаартай зангилааны эцгийн утгыг хэвлэ.
 */
void parent(struct Tree *p, int idx)
{
	if (idx == 0)
		printf("Etseggui !!!\n");
	else
		printf(" etseg ni  = %d \n", p->dat[(idx - 1) / 2]);
}

/* p-ийн зааж буй Tree-г idx дугаартай зангилаанаас эхлэн preorder-оор хэвлэ */
void preorder(struct Tree *p, int idx)
{
	if (idx < p->len)
	{
		printf(" %d\n", p->dat[idx]);
		preorder(p, idx * 2 + 1);
		preorder(p, idx * 2 + 2);
	}
}

/* p-ийн зааж буй Tree-г idx дугаартай зангилаанаас эхлэн in-order-оор хэвлэ */
void inorder(struct Tree *p, int idx)
{
	/* Энд in-order-оор хэвлэх үйлдлийг хийнэ үү */
	if (idx < p->len)
	{
		inorder(p, idx * 2 + 1);
		printf("%d\n", p->dat[idx]);
		inorder(p, idx * 2 + 2);
	}
}

/* p-ийн зааж буй Tree-г idx дугаартай зангилаанаас эхлэн post-order-оор хэвлэ */
void postorder(struct Tree *p, int idx)
{
	/* Энд post-order-оор хэвлэх үйлдлийг хийнэ үү */
	if (idx < p->len)
	{
		postorder(p, idx * 2 + 1);
		postorder(p, idx * 2 + 2);
		printf("%d\n", p->dat[idx]);
	}
}

/* p-ийн зааж буй Tree-д idx дугаартай зангилаанаас үндэс хүртэлх оройнуудын тоог буцаана.
   x тоо олдохгүй бол -1-г буцаана.
 */
int level(struct Tree *p, int idx)
{
	return 0; //hiigeegui
}
#endif
