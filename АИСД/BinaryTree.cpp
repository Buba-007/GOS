/*
*				  Ср       Лучш
* Расход памяти	 O(n)		O(n)
* Поиск	         O(log n)	O(n)
* Вставка	     O(log n)	O(n)
* Удаление	     O(log n)	O(n)
*/

#include <stdio.h>
#include <stdlib.h>


struct Node {
	int key;
	char value;
	struct Node* left;
	struct Node* right;
};

struct Node* CreateNode(int key, char value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->key = key;
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

struct Node* Find(struct Node* node, int key) {
	if (node == NULL) return NULL;

	if (key < node->key)
		node->left = Find(node->left, key);
	else if (key > node->key)
		node->right = Find(node->right, key);
	else
		return node;
}

struct Node* Insert(struct Node* node, int key, char value) {
	if (node == NULL) return CreateNode(key, value);

	if (key < node->key)
		node->left = Insert(node->left, key, value);
	else if (key > node->key)
		node->right = Insert(node->right, key, value);
	else
		node->value = value;

	return node;
}

struct Node* FindMin(struct Node* node) {
	if (node->left != NULL) {
		FindMin(node->left);
	}
	else {
		return node;
	}
}

struct Node* Remove(struct Node* node, int key) {
	if (node == NULL) return node;

	if (key < node->key)
		node->left = Remove(node->left, key);
	else if (key > node->key)
		node->right = Remove(node->right, key);
	else {
		if (node->left == NULL) {
			struct Node* temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL) {
			struct Node* temp = node->left;
			free(node);
			return temp;
		}
		struct Node* temp = FindMin(node->right);
		node->key = temp->key;
		node->value = temp->value;
		node->right = Remove(node->right, temp->key);
	}
	return node;
}

void InfixTraverse(struct Node* root) {
	if (root != NULL) {
		InfixTraverse(root->left);
		printf("{key: %d, value: %c}, ", root->key, root->value);
		InfixTraverse(root->right);
	}
}
void PrefixTraverse(struct Node* root) {
	if (root != NULL) {
		printf("{key: %d, value: %c}, ", root->key, root->value);
		PrefixTraverse(root->left);
		PrefixTraverse(root->right);
	}
}
void PostfixTraverse(struct Node* root) {
    if (root != NULL) {
		PostfixTraverse(root->left);
		PostfixTraverse(root->right);
		printf("{key: %d, value: %c}, ", root->key, root->value);
    }
}

int main() {
	struct Node* root = NULL;
	root = Insert(root, 4, 'a');
	Insert(root, 1, 'b');
	Insert(root, 7, 'c');
	Insert(root, 6, 'd');
	Insert(root, 6, 'e');
	Insert(root, 3, 'f');
	Insert(root, 9, 'g');

	printf("Binary tree infix: ");
	InfixTraverse(root);
	printf("\nBinary tree prefix: ");
	PrefixTraverse(root);
	printf("\nBinary tree postfix: ");
	PostfixTraverse(root);

	struct Node* find = NULL;
	find = Find(root, 1);

	if (find == NULL) {
		printf("\n\nNot found");
	}
	else {
		printf("\n\nFind at %d value %c", find->key, find->value);
	}

	struct Node* delt = NULL;
	delt = Remove(root, 6);
	printf("\n\nWithout removed: ");
	InfixTraverse(root);

	return 0;
}