#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *left_child;
	struct Node *right_child;
	int height;
};
int max(int a, int b);
/* өгөгдсөн data утга бүхий шинэ Node үүсгэж буцаана */
struct Node *create_node(int data)
{
	struct Node *n = (struct Node *)malloc(sizeof(struct Node));
	n->data = data;
	n->left_child = NULL;
	n->right_child = NULL;
	n->height = 1;
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
/* root-ийн зааж буй зангилаагаар үндсээ хийсэн модны өндрийг буцаана */
int height(struct Node *root)
{
	/* Энд өндрийг олох үйлдлийг хийнэ */
	if (root == NULL)
		return 0;
	else
	{
		int leftTree = height(root->left_child);
		int rightTree = height(root->right_child);

		if (leftTree > rightTree)
			return (leftTree + 1);
		else
			return (rightTree + 1);
	}
}
/* root-ийн зааж буй дэд модноос x тоог хайн, олдсон node-ийн хаягийг буцаана.
   Олдохгүй бол null утгыг буцаана.
 */
struct Node *find(struct Node *root, int d)
{
	// while (root != NULL)
	// {
	// 	if (root->data == d)
	// 		break;
	// 	else if (root->data > d)
	// 		find(root->left_child, d);
	// 	else
	// 		find(root->right_child, d);
	// 	return root;
	// }
	if (root == NULL || root->data == d)
		return root;
	if (root->data <= d)
		return find(root->right_child, d);
	else
		return find(root->left_child, d);
}

/* root-ийн зааж буй зангилаагаар үндэсээ хийсэн дэд модонд d утгыг орууж шинээр үүссэн дэд модыг буцаана */
struct Node *insert(struct Node *root, int d)
{
	if (root == NULL)
		return create_node(d);
	else if (root->data < d)
		root->right_child = insert(root->right_child, d);
	else
		root->left_child = insert(root->left_child, d);
	return root;
}
/* root-ийн зааж буй зангилаагаар үндэсээ хийсэн дэд модоос d утгыг устгаж шинээр үүссэн дэд модыг буцаана */
struct Node *find_min(struct Node *root)
{
	if (root == NULL)
		return NULL;
	else if (root->left_child != NULL)
		return find_min(root->left_child);
	return root;
}
struct Node *removeE(struct Node *root, int d)
{
	if (root == NULL)
		return root;
	if (root->data < d)
		root->right_child = removeE(root->right_child, d);
	else if (root->data > d)
		root->left_child = removeE(root->left_child, d);
	else
	{
		if (root->left_child == NULL && root->right_child == NULL)
		{
			delete_tree(root);
			return NULL;
		}
		else if (root->left_child == NULL || root->right_child == NULL)
		{
			struct Node *temp;
			if (root->left_child == NULL)
				temp = root->right_child;
			else
				temp = root->left_child;
			delete_tree(root);
			return temp;
		}
		else
		{
			struct Node *temp = find_min(root->right_child);
			root->data = temp->data;
			root->right_child = removeE(root->right_child, temp->data);
		}
	}
	return root;
}
/* root-ийн зааж буй Tree-г in-order-оор хэвлэ */
void inorder(struct Node *root)
{
	/* Энд in-order-оор хэвлэх үйлдлийг хийнэ үү */
	if (root != NULL)
	{
		inorder(root->left_child);
		printf("%d , ", root->data);
		inorder(root->right_child);
	}
}
#endif
