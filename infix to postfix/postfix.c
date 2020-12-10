#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100
/*
List-ийн хэрэгжүүлэлтийг Token төрлийн өгөгдөл хадгалдаг болгож өөрчилж бич
List, Stack-ийг хэрэгжүүлсэн header файлуудыг холбох

List -ийн толгой файлд жагсаалтын төгсгөлд нэмэх void push_back(List *p, struct Token x) функцыг нэмэж тодорхойл
*/

struct Token {
	int flag;        	/*
				  flag = 1 бол уг объект тооны мэдээлэл val-д хадгална
				  flag = 0 бол уг объект op-д тэмдэгт хадгална
				 */
	int val;
	char op;
};

int convert_to_int(const char s[])
{
	int len = strlen(s);
	int t = 0, i;
	for (i = 0; i < len; i++)
		t = t * 10 + s[i] - '0';
	return t;
}
void tokenize(const char s[], struct List *p_list)
{
	char tmp[LEN];
	int i, j, k, len;
	j = 0;
	struct Token x;
	len = strlen(s);
	for (i = 0; i < len; i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			/* цифр орж ирлээ */
			tmp[j] = s[i];
			j++;
		} else {
			/* тэмдэгт орж ирлээ */
			if (j != 0) { /* Хөрвүүлэх тоо байгаа эсэх */
				tmp[j] = '\0';
				j = 0;
				/* хадгалсан цифрийн цувааг int-рүү хөрвүүл */
				k = convert_to_int(tmp);
				x.flag = 1;
				x.val = k;
				/*
				  Жагсаалтанд x элемнтийг оруулах
				  Жагсаалтын төгсгөлд нэмэх үйлдэл хийнэ
				*/
				push_back(p_list, x);
			}
			/*
			  тэмдэгтийг жагсаалтанд оруулах
			  Жагсаалтын төгсгөлд нэмэх үйлдэл хийнэ
			 */
			if (s[i] == ' ' || s[i] == '\n') /* хоосон зай, шинэ мөрийг хаяна. */
				continue;
			x.flag = 0;
			x.op = s[i];
			push_back(p_list, x);
		}
	}

	/* Тэмдэгтэн цуваанаас салгасан тэгшитгэлийг хэвлэх
	   Жагсаалтын print функцыг дуудна.
	 */
	print(p_list);
}

/*
  p_tk - жагсаалтад байгаа тэгштгэлийг postfix-рүү хөрвүүлнэ
 */
void convert_to_postfix(struct List *p_tk, struct List *p_pf)
{
	
}

int solve(struct List *p_pf)
{
	
}

int main()
{
	char s[LEN];
	printf("Tegshitgel oruul:");
	fgets(s, LEN, stdin);

	/* Тэгшитгэлд байгаа хоосон зайнуудыг байхгүй болгоно */
	int i, j, len;

	List tokens, postfix;
	
	/* List-ийг эхлүүлнэ */
	init(&tokens);
	init(&postfix);
	tokenize(s, &tokens);

	/* tokens жагсаалтад хадгалсан тэгшитгэлээ postfix-рүү хөрвүүлэх */
	convert_to_postfix(&tokens, &postfix);

	/* postfix жагсаалтад хадгалсан postfix хэлбэрийг тэгштгэлийг
	   бодоод хариуг нь буцаах функц
	 */
	int res;
	res = solve(&postfix);
	printf("Xariu: %d\n", res);
	return 0;
}
