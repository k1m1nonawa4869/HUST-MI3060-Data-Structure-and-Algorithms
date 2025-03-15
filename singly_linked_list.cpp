#include <iostream>
using namespace std;

class Node {// initial structure of a node(data, next)
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {//basic method on a linked list
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    Node* getHead() {//return where linked_list started
        return head;
    }

    void appendFirst (int data) {//insert to the 1st position
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void appendLast (int data) {//insert to the last position
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        
        temp->next = newNode;
    }

    void removeFirst() {//remove the first node from linked_list
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void removeLast() {//remove the final node from linked_list
        if (head == nullptr) {
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }
};

class LinkedListOperations {//complex operation on a linked list
public:
    static void print (Node* head) {// for display the linked list
        Node* tmp = head;

        while (tmp != nullptr) {
            cout << tmp->data << " -> ";
            tmp = tmp->next;
        }

        cout << "nullptr\n";
    }

    static void sizeOf (Node* head) {// display length of linked list
        Node* tmp = head;

        int count = 0;
        while (tmp != nullptr) {
            count +=1 ;
            tmp = tmp->next;
        }

        cout << count << "\n";
    }

    static void reverse (Node* head) {// reverse a linked list using appendFirst
        SinglyLinkedList reversedList;
        Node* current = head;

        while (current != nullptr) {
            reversedList.appendFirst(current->data);
            current = current->next;
        }
        
        print(reversedList.getHead());
    }
};

int main() {
    //Test1
    SinglyLinkedList list;

    int a[] {1, 2, 3, 4, 5, 6};
    int lengthA = sizeof(a) / sizeof(a[0]);
    for (int i=0; i<lengthA; i++) {
        list.appendFirst(a[i]);
    }

    int b[] {7, 8, 9};
    int lengthB = sizeof(b) / sizeof(b[0]);
    for (int i=0; i<lengthB; i++) {
        list.appendLast(b[i]);
    }

    list.removeFirst();
    list.removeLast();

    cout << "Linked_List: "; LinkedListOperations::print(list.getHead());
    cout << "Length: "; LinkedListOperations::sizeOf(list.getHead());
    cout << "Reversed_Linked_List: "; LinkedListOperations::reverse(list.getHead());
}