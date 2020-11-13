#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
struct Heap
{
	int len;  // Нийт багтаамж
	int size; // Одоогийн хэмжээ
	int *dat; // Өгөгдөл хадгалах хүснэгтийг заах хаяг
};

int error = 0;
const char error_msg[][50] = {
	"",
	"Heap duuren!",
	"Heap hooson!",
};

void init(struct Heap *p, int n)
{
	p->len = n;
	p->size = 0;
	p->dat = (int *)malloc(sizeof(int) * n);
}

void release(struct Heap *p)
{
	free(p->dat);
	p->dat = NULL;
}
/* a хүснэгтийн i болон j дугаар элементийн байрыг солих */
void swap(int *a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
/*p-ийн зааж буй Heap-д шинээр нэмэгдсэн idx зангилааны элементийг эцэгтэй нь жишиж байрыг солих замаар зөв байрлалд оруулах*/
void heap_Up(struct Heap *p, int idx)
{
	if (idx > 0)
	{
		if (p->dat[idx] > p->dat[(idx - 1) / 2])
		{
			swap(p->dat, idx, ((idx - 1) / 2));
			heap_Up(p, (idx - 1) / 2);
		}
	}
}
/*p-ийн зааж буй Heap-ийн idx элементийг хүүхдүүдтэй нь жишиж байрыг солих замаар зөв байрлалд оруулах*/
void heap_Down(struct Heap *p, int idx)
{
	if (((idx * 2 + 1) < p->size && p->dat[idx] < p->dat[idx * 2 + 1]) || (p->dat[idx] < p->dat[idx * 2 + 2] && p->size > (idx * 2 + 2)))
	{
		if (p->dat[idx * 2 + 1] < p->dat[idx * 2 + 2] && p->size > idx * 2 + 2)
		{
			swap(p->dat, idx, idx * 2 + 2);
			heap_Down(p, idx * 2 + 2);
		}
		else if (p->size > idx * 2 + 1)
		{
			swap(p->dat, idx, idx * 2 + 1);
			heap_Down(p, idx * 2 + 1);
		}
	}
}

/* p-ийн зааж буй Heap-д x утгыг нэмэн Heap_up үйлдлийн туслажтай зөв байрлалд оруул */
void add(struct Heap *p, int x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
	p->dat[p->size] = x;
	heap_Up(p, p->size);
}
/* p-ийн зааж буй Heap-д а хүснэгтийн бүх элементийг add үйлдлийн туслажтай нэм*/
void build_heap(struct Heap *p, int *a, int n)
{
	if (p->size > n)
		error = 1;
	else
	{
		for (int i = 0; i < n; i++)
		{
			add(p, a[i]);
			p->size++;
		}
	}
}
/* p-ийн зааж буй Heap-ийн үндэс элементийг устган 
(үндэс элементийг heap-ийн хамгийн сүүлийн элементтэй байрыг солино) 
heap_Down үйлдлийн туслажтай heap-ийг зас*/
/*  */
void removeE(struct Heap *p)
{
	swap(p->dat, 0, p->size - 1);
	p->size--;
	heap_Down(p, 0);
}
/* p-ийн зааж буй Heapийн элементүүдийг устгах (removeE үйлдлийг ашиглан) замаар эрэмбэлэх үйлдэлийг гүйцэтгэ*/
void sort_heap(struct Heap *p)
{
	for (int i = 0; i < p->len; i++)
		removeE(p);
}
/* n элементтэй а хүснэгтийн утгыг хэвлэ */
void print_array(int *a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
/* p-ийн зааж буй Heap -ийн элементүүдэд түвшинээр гүйн хэвлэ */
void breadth_first(struct Heap *p)
{
	if (p->size > 0)
		print_array(p->dat, p->size);
	else
		error = 2;
}
#endif
