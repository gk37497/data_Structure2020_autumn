#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *left_child;
	struct Node *right_child;
};

/* өгөгдсөн data утга бүхий шинэ Node үүсгэж буцаана */
struct Node *create_node(int data)
{
	struct Node *n = (struct Node *)malloc(sizeof(struct Node));
	n->data = data;
	n->left_child = NULL;
	n->right_child = NULL;
	return n;
}
/* өгөгдсөн дэд модыг устгах */
void delete_tree(struct Node *n)
{
	if (n != NULL)
	{
		delete_tree(n->left_child);
		delete_tree(n->right_child);
		free(n);
		n = NULL;
	}
}

/* root-ийн зааж буй дэд модноос x тоог хайн, олдсон node-ийн хаягийг буцаана.
   Олдохгүй бол null утгыг буцаана.
 */
struct Node *find(struct Node *root, int d)
{
	if (root->data == d)
	{
		return root;
	}

	if (root->data < d)
	{
		return find(root->right_child, d);
	}
	else
	{
		return find(root->left_child, d);
	}
}
/* root-ийн зааж буй зангилаагаар үндсээ хийсэн модны өндрийг буцаана */
int height(struct Node *root)
{
	/* Энд өндрийг олох үйлдлийг хийнэ */
	return 0;
}
/* root-ийн зааж буй зангилаагаар үндэсээ хийсэн дэд модонд d утгыг орууж шинээр үүссэн дэд модыг буцаана */
struct Node *insert(struct Node *root, int d)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
	if (root->data = NULL)
	{
		return create_node(d);
	}
	if (d <= root->data)
	{
		root->left_child = insert(root->left_child, d);
	}
	else if (d >= root->data)
	{
		root->right_child = insert(root->right_child, d);
	}
	return root;
}
/* root-ийн зааж буй зангилаагаар үндэсээ хийсэн дэд модоос d утгыг устгаж шинээр үүссэн дэд модыг буцаана */
struct Node *removeE(struct Node *root, int d)
{
	return 0;
}
/* root-ийн зааж буй Tree-г in-order-оор хэвлэ */
void inorder(struct Node *root)
{
	/* Энд in-order-оор хэвлэх үйлдлийг хийнэ үү */
	inorder(root->left_child);
	printf("%d , ", root->data);
	inorder(root->right_child);
}
#endif
