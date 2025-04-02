#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* headNode;
    int size;

    void deleteSingleNode() {
        delete headNode;
        headNode = nullptr;
    }

public:
    CircularLinkedList() : headNode(nullptr) {}

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (headNode == nullptr) {
            headNode = newNode;
            newNode->next = headNode;
            return;
        }

        Node* temp = headNode;
        while (temp->next != headNode) {
            temp = temp->next;
        }
        size++;
        temp->next = newNode;
        newNode->next = headNode;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (headNode == nullptr) {
            headNode = newNode;
            newNode->next = headNode;
            return;
        }

        Node* temp = headNode;
        while (temp->next != headNode) {
            temp = temp->next;
        }
        size++;
        temp->next = newNode;
        newNode->next = headNode;
        headNode = newNode;
    }

    void deleteFromEnd() {
        if (headNode == nullptr) return;

        if (headNode->next == headNode) {
            deleteSingleNode();
            return;
        }

        Node* temp = headNode;
        Node* prev = nullptr;
        while (temp->next != headNode) {
            prev = temp;
            temp = temp->next;
        }
        size--;
        prev->next = headNode;
        delete temp;
    }

    void deleteFromBeginning() {
        if (headNode == nullptr) return;

        if (headNode->next == headNode) {
            deleteSingleNode();
            return;
        }

        Node* last = headNode;
        while (last->next != headNode) {
            last = last->next;
        }

        last->next = headNode->next;
        Node* temp = headNode;
        headNode = headNode->next;
        size--;
        delete temp;
    }

    void traverse() {
        if (headNode == nullptr)
        {
            std::cout << "No elements found on the list" << std::endl;
            return;
        }
            

        Node* temp = headNode;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != headNode);
        std::cout << std::endl;
    }

    void findTheMiddle() {
        if (headNode == nullptr) return;

        Node* slow = headNode;
        Node* fast = headNode;

        while (fast->next->next != headNode && fast->next != headNode)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        std::cout << "Middle element: " << slow->data << std::endl;
    }

    void insertAtIndex(int index, int value) {
        if (index == 0) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* current = headNode;
        int count = 0;

        while (current != headNode && count <= index) {
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            std::cout << "Index out of range" << std::endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteFromIndex(int index) 
    {
        if (index < 0 || index >= size) 
        {
            std::cout << "Index out of range" << std::endl;
            return;
        }
        if (index == 0) {
            deleteFromBeginning();
            return;
        }
        Node* current = headNode;
        Node* prev = nullptr;
        for (int i = 0; i < index; i++) 
        {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        delete current;
        size--;
    }

    void reverse() {
        if (headNode == nullptr || headNode->next == headNode) return;

        Node* prev = nullptr;
        Node* current = headNode;
        Node* nextNode = headNode->next;

        do {
            current->next = prev;
            prev = current;
            current = nextNode;
            nextNode = nextNode->next;

        } while (current != headNode);

        current->next = prev;
        headNode = prev;
    }

    void deleteAllNodes() {
        if (headNode == nullptr) return; 

        Node* current = headNode;
        Node* nextNode;

        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != headNode);

        headNode = nullptr; 
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(1);
    cll.insertAtEnd(2);
    cll.insertAtEnd(3);
    cll.insertAtBeginning(0);
    cll.insertAtEnd(4);
    cll.insertAtEnd(5);
    cll.insertAtEnd(6);
    cll.traverse();
    cll.findTheMiddle();
    cll.deleteFromEnd();
    cll.traverse();
    cll.deleteFromBeginning();
    cll.traverse();
    cll.insertAtIndex(1, 5);
    cll.traverse();
    cll.deleteFromIndex(1);
    cll.traverse();
    cll.reverse();
    cll.traverse();

    cll.deleteAllNodes();

    cll.traverse();

    return 0;
}
