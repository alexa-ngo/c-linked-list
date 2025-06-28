#ifndef LINKED_LIST_H
#define LINKED_LIST_H

	//printf("Adding to Position 5\n");
#include <stdio.h>
#include <stdlib.h>

/*
Functions with the arguments
*/ 

typedef struct _node {
	char* data;
	int length;
	struct _node* next;
} Node;

Node* createNode(char* data);

Node* createNodeFromNumber(int num);

Node* add(Node* node, char* data);

Node* addNumberNode(Node* headNode, int data);

Node* addNodeToPosition(Node* node, char* data, int indexPosition);

Node* deleteAtIndex(Node* head, int indexToRemoveFrom);

void freeAllNodes(Node* headNode);

Node* getAtIndex(Node* head, int indexToGetFrom);

char* num2str(int num);

Node* removeAtFirstOccur(Node* node, char* dataToRemove);

void printNodes(Node* node);

#endif
