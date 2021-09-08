// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node {
public:
    int key;
    int data;
    Node* next;

    Node() {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int k, int d) {
        key = k;
        data = d;
    }
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = NULL;
    }

    SinglyLinkedList(Node* n) {
        head = n;
    }

    Node* nodeExists(int k) {
        Node* temp = NULL;
        Node* ptr = head;

        while(ptr != NULL) {
            if (k == ptr->key) {
                temp = ptr;

            }
            ptr = ptr->next;
        }
        return temp;
    }

    void appendNode(Node* n) {

        if (nodeExists(n->key) != NULL) {
            std::cout << "Node already exists with this key value" << std::endl;
        }
        else {

            if (head == NULL) {
                head = n;
            }
            else {
                Node* ptr = head;

                while (ptr->next != NULL) {
                    ptr = ptr->next;
                }

                ptr->next = n;
            }
            
        }
        
    }

    void prependNode(Node* n) {

        if (nodeExists(n->key) != NULL) {
            std::cout << "Node already exists with this key value" << std::endl;
        }
        else {

             n->next = head;
             head = n;
            
        }
        
    }

    void insertNodeAfter(int k, Node* n) {

        Node* ptr = nodeExists(k);

        if (nodeExists(k) == NULL) {
            std::cout << "No node with this key exists" << std::endl;
        }
        else {
            if (nodeExists(n->key) != NULL) {
                std::cout << "Node already exists with this key value" << std::endl;
            }
            else {

                n->next = ptr->next;
                ptr->next = n;
            }
        }
        
    }

    void deleteNodebyKey(int k) {
        if (head == NULL) {
            std::cout << "list is empty" << std::endl;
        }
     
        else {

            if (head->key == k) {
                head = head->next;
            }
            else {
                Node* ptr = nodeExists(k);

                if (nodeExists(k) == NULL) {
                    std::cout << "No node with this key exists" << std::endl;
                }

                Node* temp = head;

                while (temp->next->key != k) {
                    temp = temp->next;
                }

                temp->next = temp->next->next;
            }
            
        }
    }

    void updateNodeByKey(int k, int d) {
        Node* ptr = nodeExists(k);

        if (nodeExists(k) == NULL) {
            std::cout << "No node with this key exists" << std::endl;
        }

        else {
            ptr->data = d;
        }
    }

    void print() {
        Node* temp = head;

        while (temp != NULL) {
            std::cout << temp->data <<std::endl;
            temp = temp->next;

        }
    }
};

int main()
{
    SinglyLinkedList s;

    Node* n1 = new Node();// Node created in heap but pointer to node is on the stack
    n1->key = 1;
    n1->data = 10;

    s.appendNode(n1);
    //s.print();

    Node* n2 = new Node();
    n2->key = 2;
    n2->data = 20;

    s.appendNode(n2);
    //s.print();

    Node* n3 = new Node();
    n3->key = 3;
    n3->data = 30;
    s.prependNode(n3);



    Node* n4 = new Node();
    n4->key = 4;
    n4->data = 40;
    s.insertNodeAfter(2, n4);
    //s.print();

    s.updateNodeByKey(2, 21);
    //s.print();

    s.deleteNodebyKey(3);
    s.print();

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
