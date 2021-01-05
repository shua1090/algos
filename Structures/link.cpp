#include <iostream>

struct Node {
    int value;
    Node* next;
    Node() = default;
    Node(int value, Node* next=nullptr) : value(value), next(next) {}
    ~Node() { free(next); }
};

struct LinkedList {
    Node* head;
    size_t size;
    LinkedList(Node* head) {
        this->head = head;
        this->size = 0;
    }
    ~LinkedList() { 
        delete head; 
    }
    void print() {
        Node* n = this->head;
        std::cout << "[";
        std::cout << n->value << " ";
        while (n->next != nullptr) {
            n = n->next;
            std::cout << n->value << " ";
        }
        std::cout << "]" << std::endl;
    }
    Node* getTail() {
        Node* n = this->head;
        while (n->next != nullptr)
            n = n->next;
        return n;
    }
    void append(int value) {
        this->size++;
        Node* next = new Node(value);
        Node* tail = getTail();
        tail->next = next;
    }
    int operator[](int i) const {
        if (i >= this->size || i < 0) {
            std::cout << "INVALID INDEX" << std::endl;
            return -1;
        }
        Node* n = this->head;
        for (int k = 0; k < i; k++)
            n = n->next;
        return n->value;
    }
};

int main() {
    Node* head = new Node(10);
    LinkedList nums(head);
    nums.print();
    nums.append(5);
    nums.append(12);
    nums.append(25);
    std::cout << nums[1] << std::endl;
    nums.print();
}