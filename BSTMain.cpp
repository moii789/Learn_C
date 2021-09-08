// BSTMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node() {
		data = 0;
		left = NULL;
		right = NULL;
	}

	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

class BST {
public:
	Node* head;

	BST() {
		head = NULL;
	}

	void insertNode(Node* n) {
		if (head == NULL) {
			head = n;
		}
		else {
			Node* prev = head;
			Node* curr = head;

			while (curr != NULL) {
				if (n->data < curr->data) {
					prev = curr;
					curr = curr->left;
				}
				else {
					prev = curr;
					curr = curr->right;
				}
			}
			if (n->data < prev->data) {
				prev->left = n;
			}
			else {
				prev->right = n;
			}

		}
	}

	bool searchNode(Node* n) {

		if (head == NULL) {
			return NULL;
		}

		Node* temp = head;

		while (temp != NULL) {

			if (n->data == temp->data) {
				return true;
			}

			else if (n->data < temp->data) {
				temp = temp->left;
			}

			else {
				temp = temp->right;
			}

		}

		return false;

	}
	void preOrder() {
		preOrderSupport(head);
	}

	void preOrderSupport(Node* temp) {

		if (temp == NULL) {
			return;
		}
		std::cout << temp->data << std::endl;
		preOrderSupport(temp->left);
		preOrderSupport(temp->right);

	}

	void inOrder(Node* temp) {

		if (temp == NULL) {
			return;
		}
			inOrder(temp->left);
			std::cout << temp->data << std::endl;
			inOrder(temp->right);
		

	}

	void postOrder(Node* temp) {

		if (temp == NULL) {
			return;
		}
		postOrder(temp->left);
		postOrder(temp->right);
		std::cout << temp->data << std::endl;


	}

	Node* findInOrderSuccesor(Node* n) {

		if (!searchNode(n)) {
			return NULL;
		}
		Node* temp = n;

		while (temp->left != NULL) {
			temp = temp->left;
		}
		return temp;
	}

	Node* deleteNode(Node* n) {

		return deleteSupport(n, head);
	}

	Node* deleteSupport(Node* n, Node* curr) {
		if (n->data < curr->data) {
			curr->left = deleteSupport(n, curr->left);
		}
		else if (n->data > curr->data) {
			curr->right = deleteSupport(n, curr->right);
		}

		else {

			if (curr == NULL) {
				return NULL;
			}

			if (curr->left == NULL and curr->right == NULL) {
				return NULL;
			}

			else if (curr->left == NULL) {
				Node* temp = curr->right;
				free(curr);
				return temp;
			}

			else if (curr->right == NULL) {
				Node* temp = curr->left;
				free(curr);
				return temp;
			}
			else {

				Node* temp = findInOrderSuccesor(curr->right);

				curr->data = temp->data;

				curr->right = deleteSupport(temp, curr->right);
			}
			
			
		}
		return curr;
	}


};

int main()
{
	BST bst = BST();

	Node* n1 = new Node(5);
	bst.insertNode(n1);


	Node* n2 = new Node(8);
	bst.insertNode(n2);


	Node* n3 = new Node(1);
	bst.insertNode(n3);

	Node* n4 = new Node(22);
	bst.insertNode(n4);


	Node* n5 = new Node(3);
	bst.insertNode(n5);

	//bst.preOrder();

	Node* n7 = new Node(23);

	std::cout << bst.searchNode(n7) << std::endl;

	bst.deleteNode(n4);
	//bst.preOrder();

	bst.deleteNode(n3);
	//bst.preOrder();

	bst.deleteNode(n1);
	//bst.preOrder();

	

	Node* n8 = new Node(2);
	bst.insertNode(n8);


	Node* n9 = new Node(4);
	bst.insertNode(n9);

	bst.preOrder();


	bst.deleteNode(n5);
	bst.preOrder();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
