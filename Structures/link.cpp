#include <iostream>

struct Node {
    int value;
    Node* next;
    Node() = default;
    Node(int value, Node* next=nullptr) : value(value), next(next) {}
    ~Node() { delete next; }
};

struct LinkedList {
    Node* head;
    size_t size;
    LinkedList(Node* head) {
        this->head = head;
        this->size = 1;
    }
    LinkedList(int first) {
        this->head = new Node(first);
        this->size = 1;
    }
    ~LinkedList() { delete head; }
    void print() {
        Node* n = this->head;
        if (n == nullptr) {
            std::cout << "[]" << std::endl;
            return;
        }
        std::cout << "[";
        std::cout << n->value << " ";
        while (n->next != nullptr) {
            n = n->next;
            std::cout << n->value << " ";
        }
        std::cout << "]" << std::endl;
    }
    Node* iterate(int i=-1) const {
        if (this->head == nullptr)
            return this->head;

        Node* n = this->head;
        if (i == -1) {
            while (n->next != nullptr)
                n = n->next;
        }
        else {
            for (int k = 0; k < i; k++)
                n = n->next;
        }
        return n;
    }
    void append(int value) {
        Node* next = new Node(value);
        Node* tail = iterate();
        tail->next = next;
        this->size++;
    }
    void extend(const LinkedList& other) {
        Node* tail = iterate();
        tail = other.head;
        this->size += other.size;
    }
    void insert(int index, int value) {
        if (index < 0 || index > this->size)
            throw std::exception();
        if (index == 0) {
            Node* next = new Node(value, this->head);
            this->head = next;
        }
        else if (index == this->size) {
            append(value);
        }
        else {
            Node* left = iterate(index - 1);
            Node* right = left->next;
            Node* next = new Node(value, right);
            left->next = next;
        }
        this->size++;
    }
    int& operator[](int i) const {
        if (i < 0 || i >= this->size)
            throw std::exception();
        Node* out = iterate(i);
        return out->value;
    }
};

int main() {
    Node* head = new Node(10);
    LinkedList nums(head);
    nums.print();

    nums.append(5);
    nums.append(500);
    nums.append(25);
    nums.insert(4, 12);

    nums.print();

    std::cout << nums[1] << std::endl;
}