#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 14

typedef struct node* treepointer;
typedef struct node {
	int data;
	treepointer leftchild, rightchild;
};

// Circular Queue 생성
treepointer queue[MAX_QUEUE_SIZE];
int front = 0, rear = 0;

void addq(treepointer node);                    // Queue에 요소를 삽입하는 함수
treepointer deleteq();                          // Queue의 요소를 리턴(삭제)하는 함수
void level_order_traversal(treepointer root);   // level order traversal의 결과를 출력하는 함수

int main(void)
{
	// 주어진 binary tree 생성
	struct node node1 = { 1, NULL, NULL }; struct node node2 = { 3, NULL, NULL };
	struct node node3 = { 6, NULL, NULL }; struct node node4 = { 7, NULL, NULL };
	struct node node5 = { 11, NULL, NULL }; struct node node6 = { 12, NULL, NULL };
	struct node node7 = { 2, &node1, &node2 }; struct node node8 = { 5, &node3, &node4 };
	struct node node9 = { 10, &node5, &node6 }; struct node node10 = { 13, NULL, NULL };
	struct node node11 = { 4, &node7, &node8 }; struct node node12 = { 9, &node9, &node10 };
	struct node node13 = { 8, &node11, &node12 }; // root

	treepointer root = &node13;

	// level order traversal의 결과 출력
	printf("Level order traversal의 결과: ");
	level_order_traversal(root);

	return 0;
}

void addq(treepointer node)
{
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	if (front == rear) // QueueFull 처리
		return;

	queue[rear] = node;
}

treepointer deleteq()
{
	treepointer node = NULL;
	if (front == rear) // QueueEmpty 처리
		return node;

	front = (front + 1) % MAX_QUEUE_SIZE;
	node = queue[front];
	return node;
}

void level_order_traversal(treepointer root)
{
	treepointer ptr;

	if (root == NULL) // Empty Tree 처리
		return;

	addq(root);
	while (1) {
		ptr = deleteq();
		if (ptr == NULL)
			break;

		printf("%d ", ptr->data);

		if (ptr->leftchild != NULL)
			addq(ptr->leftchild);

		if (ptr->rightchild != NULL)
			addq(ptr->rightchild);
	}
}