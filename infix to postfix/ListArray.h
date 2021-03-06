#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
struct Token {
	int flag;        	/*
				  flag = 1 бол уг объект тооны мэдээлэл val-д хадгална
				  flag = 0 бол уг объект op-д тэмдэгт хадгална
				 */
	int val;
	char op;
};
struct List {
	int len;
	struct Token *dat;
	int size;
};
int error = 0;
const char error_msg[][50] = {
	"",
	"List duuren!",
	"List xooson!",
	"Bairlald oruulax bolomjgui!",
	"Bairlaas gargax bolomjgui!"
};

void init(struct List *p, int n)
{
	p->len = n;
	p->size = 0;
	p->dat = (struct Token *) malloc(sizeof(struct Token) * n);
}

void release(struct List *p)
{
	free(p->dat);
	p->dat = NULL;
}
/* p-ийн зааж буй List хоосон бол 1 үгүй бол 0-ийг буцаана */
int empty(struct List *p)
{
	/* Энд хоосон эсэхийг шалгах үйлдлийг хийнэ */
}
/* p-ийн зааж буй List дүүрсэн бол 1 үгүй бол 0-ийг буцаана */
int isFull(struct List *p){
    /*энд жагсаалт дүүрсэн эсэхийг шалгах үйлдлийг хийнэ*/
    
}
/* p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
   pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
 */
void insert(struct List *p, struct Token x, int pos)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
}
/* p-ийн зааж буй List-ийн төгсгөлд x утгыг нэмнэ */
void push_back(struct List *p, struct Token x){
	
}
/* p-ийн зааж буй List-н pos байралаас гарган буцаана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
 */
struct Token remove(struct List *p, int pos)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй List-н утгуудыг хэвлэнэ. 
Хэвлэхдээ token-ий flag-аас хамаарч тоо бол val оператор бол op-ийн утгыг хэвлэнэ */
void print(struct List *p)
{
	/* Энд хэвлэх үйлдлийг хийнэ үү */
}
#endif
