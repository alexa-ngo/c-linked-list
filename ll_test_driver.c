#include "linked_list.h"

// Makes a linked list and returns a head node
Node* makeLinkedList() {

	int start_label = 1;
	Node* head_node = createNodeFromNumber(start_label);
	for(int i = start_label + 1; i < 10; i++) {	
		addNumberNode(head_node, i);
	}
	return head_node;
}

// Loop to free all nodes
void freeAllNodes(Node* headNode) {

	if (headNode == NULL) {
		return;
	}

	Node* curr = headNode;
	Node* temp = curr->next;
	
	while (curr != NULL) {
		Node* to_free = curr;

		free(to_free->data);
		free(to_free);

		curr = temp;
		if (curr == NULL) {
			break;
		}
		temp = temp->next;
	}
}

// Tests to get the value at an index
void getAtAnIndexTests() {

	printf("After getting at index less than 0:\n");
	Node* head_node1 = makeLinkedList();
	Node* get_node1 = getAtIndex(head_node1, -11);
	printNodes(get_node1);
	freeAllNodes(head_node1);
	
	printf("After getting at index 0:\n");
	Node* head_node2 = makeLinkedList();
	Node* get_node2 = getAtIndex(head_node2, 0);
	printNodes(get_node2);
	freeAllNodes(get_node2);

	printf("After getting at index middle:\n");
	Node* head_node3 = makeLinkedList();
	Node* getNode3 = getAtIndex(head_node3, 3);	
	printNodes(getNode3);
	freeAllNodes(head_node3);

	printf("After getting at index last node:\n");
	Node* head_node4 = makeLinkedList();		
	Node* getNode4 = getAtIndex(head_node4, 8);
	printNodes(getNode4);
	freeAllNodes(head_node4);
	printf("\n");

	printf("After getting at index out of range:\n");
	Node* head_node5 = makeLinkedList();
	Node* getNode5 = getAtIndex(head_node5, 15);
	printNodes(getNode5);
	freeAllNodes(head_node5);
}

// Remove at first occurrence 
void removeAtFirstTimeOccurTests() {

	printf("Remove data does not exist:\n");
	Node* head_node = makeLinkedList();
	Node* ll = removeAtFirstOccur(head_node, "CAT");
	printNodes(ll);
	freeAllNodes(ll);
	
	printf("Remove the first occurrence of 2:\n");
	Node* head_node1 = makeLinkedList();
	Node* list1 = removeAtFirstOccur(head_node1, "2");
	printNodes(list1);
	freeAllNodes(list1);

	printf("Remove at middle occurrence of 5:\n");
	Node* head_node2 = makeLinkedList();
	Node* list2 = removeAtFirstOccur(head_node2, "5");
	printNodes(list2);
	freeAllNodes(list2);
	
	printf("Remove the second, third, and fourth occurrence of 5:\n");
	Node* head_node3 = makeLinkedList();
	head_node3 = addNodeToPosition(head_node3, "5", 4);
	head_node3 = addNodeToPosition(head_node3, "5", 4);
	// Linked List: [1-2-3-4-5-5-5-6-7-8-9]
	head_node3 = removeAtFirstOccur(head_node3, "5");
	// Linked List: [1-2-3-4-5-5-6-7-8-9]
	printNodes(head_node3);
	freeAllNodes(head_node3);

	printf("Remove 8 from the linked list:\n");
	Node* head_node4 = makeLinkedList();
	head_node4 = addNodeToPosition(head_node4, "5", 4);
	head_node4 = addNodeToPosition(head_node4, "5", 4);
	// Linked List: [1-2-3-4-5-5-5-6-7-8-9]
	head_node4 = removeAtFirstOccur(head_node4, "8");
	// Linked List: [1-2-3-4-5-5-5-6-7-9]
	printNodes(head_node4);
	freeAllNodes(head_node4);
	
	printf("Remove -16 (which doesn't exist):\n");
	Node* head_node5 = makeLinkedList();
	Node* list5 = removeAtFirstOccur(head_node5, "-16");
	printNodes(list5);
	freeAllNodes(list5);
} 

// Add a node to the linked list
void addTests() {

	Node* head_node = makeLinkedList();
	printf("Add a negative number (-12):\n");
	head_node = add(head_node, "-12");
	printNodes(head_node);
	freeAllNodes(head_node);

	Node* head_node2 = makeLinkedList();
	printf("Add 0:\n");
	head_node2 = add(head_node2, "0");
	printNodes(head_node2);
	freeAllNodes(head_node2);	
}

void addToPositionTests() {
	
	printf("Add 1000 to Position -11:\n");
	Node* head_node = makeLinkedList();
	head_node = addNodeToPosition(head_node, "1000", -11);
	printNodes(head_node);
	freeAllNodes(head_node);
	
	printf("Add 1000 to Position 0:\n");
	Node* head_node1 = makeLinkedList();
	head_node1 = addNodeToPosition(head_node1, "1001", 0);
	printNodes(head_node1);
	freeAllNodes(head_node1);

	printf("Add 1002 to Position 5:\n");
	Node* head_node2 = makeLinkedList();
	head_node2 = addNodeToPosition(head_node2, "1002", 5);
	printNodes(head_node2);
	freeAllNodes(head_node2);
	
	printf("Add 1003 to Position 8:\n");
	Node* head_node3 = makeLinkedList();
	head_node3 = addNodeToPosition(head_node3, "1003", 8);
	printNodes(head_node3);
	freeAllNodes(head_node3);
 
	printf("Add 1004 to the last index:\n");
	Node* head_node4 = makeLinkedList();
	head_node4 = addNodeToPosition(head_node4, "1004", 9);
	printNodes(head_node4);
	freeAllNodes(head_node4);

	printf("Add 1005 to a position out of range:\n");
	Node* head_node5 = makeLinkedList();
	head_node5 = addNodeToPosition(head_node5, "1005", 25);
	printNodes(head_node5);
	freeAllNodes(head_node5);
}

// Deletes a node
void deleteAnodeTests() {

	// Delete if there isn't a linked list 
	printf("Deleting a head node if there isn't one:\n");
	Node* head_node = NULL;
	head_node = deleteAtIndex(head_node, -1);
	printNodes(head_node);
	freeAllNodes(head_node);
	printf("\n");
	
	// Delete at negative node 
	printf("Deleting a negative index:\n");
	Node* head_node0 = makeLinkedList();
	head_node0 = deleteAtIndex(head_node0, -1);
	printNodes(head_node0);
	freeAllNodes(head_node0);
	printf("\n");

	// Delete at first node
	printf("Deleting the first node:\n");
	Node* head_node1 = makeLinkedList();
	head_node1 = deleteAtIndex(head_node1, 0);	
	printNodes(head_node1);
	freeAllNodes(head_node1);
 
	// Delete at middle node 
	printf("Deleting index 4:\n");
	Node* head_node2 = makeLinkedList();
	head_node2 = deleteAtIndex(head_node2, 4);
	printNodes(head_node2);
	freeAllNodes(head_node2);

	// Delete at last node
	printf("Delete index 8:\n");
	Node* head_node3 = makeLinkedList();
	head_node3 = deleteAtIndex(head_node3, 8);
	printNodes(head_node3);
	freeAllNodes(head_node3);

	// Delete at node out of range
	printf("Delete index 20:\n");
	Node* head_node4 = makeLinkedList();
	head_node4 = deleteAtIndex(head_node4, 20);
	printNodes(head_node4);
	freeAllNodes(head_node4);
}

// Runs a stress test to execute all the functions
void stressTest() {

	int start_label = 1;
	int add_10_nodes = 10;

	// Create a linked list and add 11 nodes
	Node* head_node = createNodeFromNumber(start_label);
	for(int i = start_label + 1; i < add_10_nodes + 1; i++) {	
		addNumberNode(head_node, i);
	}
	
	// Print all the nodes: [1-2-3-4-5]
	printNodes(head_node);

	// Delete all but 1 node in the linked list
	for(int i = 0; i < add_10_nodes - 1; i++) {
		head_node = deleteAtIndex(head_node, 0);
	}

	// The linked list is an empty linked list
	printf("The only node left:\n");
	printNodes(head_node);
	printf("\n");

	// Make the linked list again using 10 nodes
	//Node* head = createNodeFromNumber(start_label);
	int existing_nodes = 2;
	int add_5_nodes = 5;
	for(int i = start_label; i < add_5_nodes + existing_nodes; i++) {	
		addNumberNode(head_node, i);
	}

	// Add a node with the value of 6 
	// Linked list is [1-2-3-4-5-6]
	head_node = addNumberNode(head_node, 6);
	
	// Tests when the index is out of range
	// Node* head_node3 = getAtIndex(head_node2, 15);
	
	// Return the linked list starting from index 2
	Node* index_list = getAtIndex(head_node, 2);
	printNodes(index_list);   // [2-3-4-5-6-6]  

	// Add two nodes with value of 4 to index 2
	head_node = addNodeToPosition(head_node, "4", 2);
	head_node = addNodeToPosition(head_node, "4", 2);

	printNodes(head_node); // linked list: [3-4-4-4-5-6]
	
	// Delete all the nodes in the linked list
	int other_added_nodes = 2;
	for(int i = 0; i < add_5_nodes + other_added_nodes; i++) {
		head_node = deleteAtIndex(head_node, 0);
	}

	// Add back two nodes
	head_node = add(head_node, "80");
	head_node = add(head_node, "81");

	printNodes(head_node); // linked list: [5-6-6-80-81]

	// Remove the remaining nodes
	int remaining_nodes = 4;
	int loop_offset = 1;
	for(int i = 0; i < remaining_nodes + loop_offset; i++) {
		head_node = deleteAtIndex(head_node, 0);
	}
	
	printNodes(head_node);
}

int main(int argc, char* argv[]) {

	addTests();
	addToPositionTests();
	deleteAnodeTests();
	getAtAnIndexTests();
	removeAtFirstTimeOccurTests();
	stressTest();
	
	return 0;
}

