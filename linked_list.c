#include "linked_list.h"
#include "string.h"

/*
This program implements the functions for the linked list
such as: 
	- add
	- addNodeToPosition
	- addNumberNode
	- createNode
	- createNodeFromNumber
	- deleteAtIndex
	- getAtIndex
	- num2str
	- printNodes
	- removeAtFirstOccur
*/ 

/*
The createNode function creates a node to be used in the linked list.

Args: 
	- strData: the string that will become the data of the node

Returns:
	- node: returns the node used to build the linked list
*/ 
Node* createNode(char* strData) {
	Node* node = (Node*) malloc(sizeof(Node));	
	node->data = strdup(strData);
	node->length = strlen(strData);
	node->next = NULL;
	return node;
}

/*
The num2Str function converts an integer to a string

Args: 
	- num: the integer to be converted to a string

Returns:
	- buffer: buffer of the character pointer to the integer
*/
char* num2str(int num) {
	// Memory is malloc'd and also freed in here
	// so don't use strdup!!
	int idx = 0;
	char* buffer = malloc(sizeof(char) * 5);		// just enough for 5 digits
	
	int quotient = num;
	while (quotient > 0) {
		int digit = quotient % 10;

		char v = '0' + digit;
		buffer[idx] = v;
		idx++;

		quotient = quotient / 10;
	}
	buffer[idx] = '\0';		// don't forget the null terminating character
	
	// reverse the string because the "number" is now backwards.
	int buffer_length = idx;
	for (int i = 0, j = buffer_length -1; i < j; i++, j--) {
		char t = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = t;
	}
	return buffer;
}

/*
The createNodeFromNumber uses the input of an integer, and returns a node.

Args:
	- num: the integer used as data to be entered into a node

Returns:
	- node: a node with the integer is returned
*/ 
Node* createNodeFromNumber(int num) {
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = num2str(num);
	node->length = strlen(node->data);
	node->next = NULL;	

	return node;
}

/* 
The add function adds a node to the back of the linked list.

Args: 
	- headNode: head of the linked list the node will be added to
	- data: character or string to include into the node

Returns: 
	- headNode: head node of the linked list after the new node is added
*/
Node* add(Node* headNode, char* data) {

	Node* temp = headNode;
	Node* newNode = createNode(data);
	
	// Add node as the second node
	if (temp->next == NULL) {
		temp->next = newNode;
		return headNode; 
	}

	// Get to the end of the linked list
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;

	return headNode;
}

/* 
The addNumberNode adds a node to the end of the linked list.

Args:
	- headNode: head node of the linked list to add the new node to
	- data: the integer to create a node from

Returns:
	- headNode with the added node
*/ 
Node* addNumberNode(Node* headNode, int data) {

	Node* temp = headNode;
	Node* newNode = createNodeFromNumber(data);
	
	// Add node as the second node
	if (temp->next == NULL) {
		temp->next = newNode;
		return headNode; 
	}

	// Get to the end of the linked list
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;

	return headNode;
}

/* 
The addNodeToPosition adds a node to a position in the linked list

Args:
	- node: node to be added to the linked list
	- data: data used to create a node to be added
	- indexPosition: the position to add the new node to

Returns: 
	- node: the newly created node
*/
Node* addNodeToPosition(Node* node, char* data, int indexPosition) {

	Node* temp = node;

	// If out of range
	if (indexPosition < 0) {
		printf("Index out of range.\n");
		return node;
	}

	// Add the node as the new head
	if (indexPosition == 0) { 
		Node* newNode = createNode(data);
		newNode->next = node;
		node = newNode;
		return node;
	}

	// Keeps track of current position of linked list
	int currPosition = 0;
	int positionBeforeNode = indexPosition - 1;
	
	while (currPosition < positionBeforeNode) {
		if (temp->next == NULL) {
			printf("Index out of range.\n");
			return node;
		} else {
			temp = temp->next;
			currPosition += 1;
		}
	}

	// Stores the working node
	Node* storedWorkingNode = temp->next;
	Node* newNode = createNode(data);
	temp->next = newNode;
	newNode->next = storedWorkingNode;
	return node;
}

/* 
The getAtIndex function gets a node at an index and 
returns the linked list starting from that node.

Args:
	- node: the node of the linked list to start searching from
	- indexToGetFrom: starting index to get the linked list from

Returns:
	- node: the head node of the linked list 
*/ 
Node* getAtIndex(Node* node, int indexToGetFrom) {

	Node* temp = node;
	int currPosition = 0;
	
	// If index is less than 0
	if (indexToGetFrom < 0) {
		printf("Index is less than 0\n");
		return node;
	}

	// Add 1 to the current position
	currPosition += 1;
	temp = temp->next;

	while (currPosition <= indexToGetFrom) {

		// If the index is out of range
		if (temp == NULL) {
			return node;
		}

		if (currPosition == indexToGetFrom) {
			node = temp;
			return node;
		} else {
			
			temp = temp->next;
			currPosition += 1;
		}
	}
	return node;
}

/* 
The deleteAtIndex deletes the node at the specified index.

Args:
	- head_node: The starting node of the linked list to start searching from
	- indexToRemoveFrom: The index to remove the node from

Returns:
	- head_node: Returns a head of the head of the linked list
*/ 
Node* deleteAtIndex(Node* head_node, int indexToRemoveFrom) {

	Node* temp = head_node;
	int currPosition = 0;

	if (head_node == NULL) {
		printf("No head\n");
		return head_node;
	}

	// If out of range
	if (indexToRemoveFrom < 0) {
		printf("Index is less than 0\n");

		//temp = head_node->next;
		//free(head_node->data);
		//free(head_node);
		return head_node;
	}

	// Remove the head node
	if ((head_node != NULL) && indexToRemoveFrom == 0) {
		temp = head_node->next;
		free(head_node->data);
		free(head_node);
		return temp;
	}
	
	// Increment one because we already c
	currPosition += 1;

	// Iterate through the linked list
	while (currPosition < indexToRemoveFrom) {
		if (temp->next == NULL) {
			printf("Index out of range.\n");
			return head_node;
		} else {
			temp = temp->next;
			currPosition += 1;
		}
	}

	// Skip over the index to remove
	Node* tempToFree = temp->next;

	// Move to the next node
	temp->next = temp->next->next;

	// Free the data and the node to be deleted
	free(tempToFree->data);
	free(tempToFree);

	currPosition += 1;
	
	if (indexToRemoveFrom < currPosition) {
		printf("The index is out of range.\n");
		return head_node;
	};

	return head_node;
}

// Removes a node based on its first occurrence 
Node* removeAtFirstOccur(Node* head, char* dataToRemove) {

	Node* temp = head;
	
	int dataMatchResult = strcmp(dataToRemove, head->data);

	// Remove the only node is matching data
	if ((dataMatchResult == 0) && (temp->next == NULL)) {	
		free(temp->data);
		free(temp);
		return NULL;
	}

	// When there is one node with data not matching
	if ((dataMatchResult != 0) && (temp->next == NULL)) {
		printf("No nodes match");	
		return head;
	}

	// Remove the head with additional nodes afterwards
	if ((dataMatchResult == 0) && (temp->next != NULL)) {
		temp = temp->next;
		head = temp;
		return head;
	}

	if (dataMatchResult == 0) {
		temp = temp->next;
		return temp;
	}

	// Iterate through the rest of the linkedlist to find the first occurrence
	while (dataMatchResult != 0) {
		dataMatchResult = strcmp(dataToRemove, temp->data);

		// Skip over the matching data and continue the linked list
		if (strcmp(temp->next->data, dataToRemove) == 0) {
			Node* prevNode = temp;
			// Temp variable to hold the node to be freed
			Node* tempToFree = temp->next;

			temp->next = temp->next->next;
		
			free(tempToFree->data);
			free(tempToFree);

			return head;
		}

		// Need this chunk for error handling
		if (dataMatchResult != 0) {				
			temp = temp->next; 
		} else {
			if (dataMatchResult == 0) {
				temp->next = temp->next->next;
				return head;
			}
		}
		
		if (dataMatchResult == 0) {
			temp->next = temp->next->next;
			return head;
		}

		// Return the head 
		if (temp->next == NULL) {
			printf("Data not found.\n");
			return head;
		}
		if (temp == NULL) {
			printf("Ending now!\n");
			return head;
		}
	}

	// If the data is not found
	if (temp->next == NULL) {
		return head;
	}

	temp->next = temp->next->next;

	return head;
}


void printNodes(Node* node) {

	Node* temp = node;
	
	if (node == NULL) {
		printf("Empty Linked List\n");
		return;
	}

	if (temp->next == NULL) {
		printf("%s\n", temp->data);
		return;	
	}

	if (temp->next == NULL) {
		printf("Index out of range\n");
		return;
	} else {
		printf("Head: %s\n", temp->data);	
		if (temp->next == NULL) {
			return;
		}

		while (temp->next != NULL) {
			temp = temp->next;
			printf(">> %s\n", temp->data);
		}
	}
	printf("\n");
}

