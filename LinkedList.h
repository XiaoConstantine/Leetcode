/*************************************************************************
    > File Name: LinkedList.h
    > Author: Xiao Cui
    > Mail: xc432@nyu.edu 
    > Created Time: Sat Oct  6 17:17:00 2012
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	Node* next;
	int data;
	Node(int x): data(x), next(NULL){
	}
};

Node* initilizeList(int start, int end){
	Node *head, *curr;
	head = NULL;
	for( int i = end; i>start; i--){
		curr = (Node*)malloc(sizeof(Node));
		curr->data = i;
		curr->next = head;
		head = curr;
	}

	return head;
}

void printList(Node* head){
	Node* curr = head;
	while(curr){
		printf("Data: %d\n", curr->data);
		curr = curr->next;
	}
}

