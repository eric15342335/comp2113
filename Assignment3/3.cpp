#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Node {
	int value;
	Node * nextptr;
};

void build_sorted_linkedlist(Node *& headptr1, int input) {
	// insert a new item 'input' into an existing sorted linked list
	// with head pointer headptr1
	Node * previous = headptr1;
	if (previous != nullptr) {
		if (previous->value < input) {
			while (previous->nextptr != nullptr) {
				if (previous->nextptr->value < input) {
					previous = previous->nextptr;
				}
				else
					break;
			}
			Node * next = previous->nextptr;
			Node * current = new Node;
			previous->nextptr = current;
			current->value = input;
			current->nextptr = next;
		}
		else {
			// the input is smaller than the first item in the linked list
			headptr1 = new Node;
			headptr1->value = input;
			headptr1->nextptr = previous;
			// the input becomes the new headptr
		}
	}
	else {
		// the first linked list is blank, so we create one
		// since we need to insert something
		headptr1 = new Node;
		headptr1->value = input;
		headptr1->nextptr = nullptr;
	}
}

void linkedlist_int(Node *& headptr1) {
	// we expect headptr1 to be nullptr
	// otherwise, we will have memory leak!
	string line;
	getline(cin, line);
	istringstream line_in(line);
	// the first input
	int x;
	if (line_in >> x) {
		headptr1 = new Node;
		headptr1->value = x;
		headptr1->nextptr = nullptr;
		// subsequent inputs
		int input;
		while (line_in >> input) {
			build_sorted_linkedlist(headptr1, input);
		}
	}
	return;
}

void print_linked_list(Node * headptr1) {
	// print all stuffs
	Node * current_node = headptr1;
	while (current_node != nullptr) {
		cout << current_node->value;
		current_node = current_node->nextptr;
		if (current_node == nullptr) {
			break;
		}
		cout << " ";
	}
	cout << endl;
}

void remove_dups_negative_nums(Node *& headptr1) {
	// headptr1 linked list must be sorted ascendingly
	Node * current = headptr1;
	while (current != nullptr && current->nextptr != nullptr) {
		if (current->value == current->nextptr->value) {
			// 1 2 x x 6 7
			// remove the second occurrence of x as duplicate
			Node * next = current->nextptr;
			current->nextptr = next->nextptr;
			delete next;
		}
		else {
			current = current->nextptr;
		}
	}
	// since the list is sorted, the negative values are
	// located at the beginning of the list
	while (headptr1 != nullptr) {
		if (headptr1->value < 0) {
			Node * next = headptr1;
			headptr1 = headptr1->nextptr; // set the new head pointer
			delete next;                  // free up memory
		}
		else {
			break;
		}
	}
}

Node * last_node_greater_than(Node * currentptr, int input) {
	if (currentptr != nullptr) {
		if (currentptr->nextptr != nullptr) {
			if (currentptr->nextptr->value > input) {
				return currentptr;
			}
			else {
				Node * result =
					last_node_greater_than(currentptr->nextptr, input);
				if (result == nullptr) {
					return currentptr;
				}
				else {
					return result;
				}
			}
		}
		else {
			if (currentptr->value <= input) {
				return currentptr;
			}
			else {
				return nullptr; // currentptr->value is greater than input
				// so last_node_greater_than should be previous node
			}
		}
	}
	else {
		return nullptr; // uninitialized linked list
	}
}

void recursive_remove_dups(Node * headptr1) {
	// headptr1 linked list must be sorted ascendingly
	if (headptr1 == nullptr) {
		return;
	}
	if (headptr1->nextptr != nullptr) {
		if (headptr1->value == headptr1->nextptr->value) {
			headptr1->nextptr = headptr1->nextptr->nextptr;
			recursive_remove_dups(headptr1);
		}
		else {
			recursive_remove_dups(headptr1->nextptr);
		}
	}
}

int main() {
	Node * node1head = nullptr;
	Node * node2head = nullptr;
	linkedlist_int(node1head);
	print_linked_list(node1head);
	linkedlist_int(node2head);
	print_linked_list(node2head);
	// merge sort
	Node * current = node2head;
	while (current != nullptr) {
		build_sorted_linkedlist(node1head, current->value);
		current = current->nextptr;
	}
	remove_dups_negative_nums(node1head);
	// recursive_remove_dups(node1head);
	print_linked_list(node1head);
	return 0;
}
