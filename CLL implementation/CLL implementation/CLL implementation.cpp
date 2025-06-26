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

    void deleteSingleNode() 
    {
        delete headNode;
        headNode = nullptr;
        size = 0;
    }

    Node* getLastNode() 
    {
        if (!headNode)
        {
            return nullptr;
        }

        Node* temp = headNode;

        while (temp->next != headNode) 
        {
            temp = temp->next;
        }

        return temp;
    }

public:
    CircularLinkedList() : headNode(nullptr), size(0) {}

    void insertAtEnd(int value) 
    {
        Node* newNode = new Node(value);
        if (!headNode) 
        {
            headNode = newNode;
            headNode->next = headNode;
        }
        else 
        {
            Node* last = getLastNode();
            last->next = newNode;
            newNode->next = headNode;
        }

        size++;
    }

    void insertAtBeginning(int value) 
    {
        Node* newNode = new Node(value);
        if (!headNode) 
        {
            headNode = newNode;
            headNode->next = headNode;
        }
        else 
        {
            Node* last = getLastNode();
            last->next = newNode;
            newNode->next = headNode;
            headNode = newNode;
        }
        size++;
    }

    void deleteFromEnd() {
        if (!headNode) return;

        if (headNode->next == headNode) 
        {
            deleteSingleNode();
            return;
        }

        Node* current = headNode;
        Node* prev = nullptr;
        while (current->next != headNode) 
        {
            prev = current;
            current = current->next;
        }

        prev->next = headNode;

        delete current;

        size--;
    }

    void deleteFromBeginning() 
    {
        if (!headNode) return;

        if (headNode->next == headNode) {
            deleteSingleNode();
            return;
        }

        Node* last = getLastNode();
        Node* temp = headNode;
        headNode = headNode->next;
        last->next = headNode;
        delete temp;
        size--;
    }

    void insertAtIndex(int index, int value) 
    {
        if (index < 0 || index > size) 
        {
            std::cout << "Index out of range" << std::endl;
            return;
        }

        if (index == 0) 
        {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* current = headNode;

        for (int i = 0; i < index - 1; ++i) 
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        size++;
    }

    void deleteFromIndex(int index) 
    {
        if (index < 0 || index >= size) 
        {
            std::cout << "Index out of range" << std::endl;
            return;
        }

        if (index == 0) 
        {
            deleteFromBeginning();
            return;
        }

        Node* current = headNode;

        for (int i = 0; i < index - 1; ++i) 
        {
            current = current->next;
        }

        Node* temp = current->next;

        current->next = temp->next;

        delete temp;

        size--;
    }

    void findTheMiddle() 
    {
        if (!headNode) return;

        Node* slow = headNode;
        Node* fast = headNode;

        while (fast->next != headNode && fast->next->next != headNode) 
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        std::cout << "Middle element: " << slow->data << std::endl;
    }

    void reverse() 
    {
        if (!headNode || headNode->next == headNode) return;

        Node* prev = nullptr;
        Node* current = headNode;
        Node* nextNode;

        do {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        } while (current != headNode);

        // Fix the circular link
        headNode->next = prev;
        headNode = prev;
    }

    void deleteAllNodes() {
        if (!headNode) return;

        Node* current = headNode->next;

        while (current != headNode) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        delete headNode;
        headNode = nullptr;
        size = 0;
    }

    void traverse() 
    {
        if (!headNode) 
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

    ~CircularLinkedList() 
    {
        deleteAllNodes();
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
    cll.insertAtIndex(1, 9);
    cll.traverse();             
    cll.deleteFromIndex(1);
    cll.traverse();             
    cll.reverse();
    cll.traverse();             
    cll.deleteAllNodes();
    cll.traverse();             
    return 0;
}