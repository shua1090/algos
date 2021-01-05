#include <cstdlib>
#include <iostream>

template <class c>
class stack{
    private:
        int length;
        c* head;
        int current;
    public:
        stack(c length);
        ~stack();
        int size();
        int push(c element);
        c pop();
        c operator[] (int index) const;
        operator std::string() const;
};

template <class c>
stack<c>::stack(c length) {
    this->head = (c*) calloc(length, sizeof(c));
    this->length = length;
    current = 0;
}

template <class c>
stack<c>::~stack() {
    free(this->head);
}

template <class c>
int stack<c>::size() {
    return this->length;
}

template <class c>
int stack<c>::push(c element) {
    if (this->current >= this->length){
        return 1;
    } else {
        *(this->head+this->current) = element;
        current += 1;
    }
    return 0;
}

template <class c>
c stack<c>::pop() {
    printf("Popping");
    c result = head[--current];
    head[this->current] = (c) NULL;
    return result;
}

template <class c>
c stack<c>::operator[] (int index) const {
    if (index > this->current || index < 0){
        throw std::out_of_range("Unfortunately, your given Index was out of the valid range");
    } else {
        return head[index];
    }
}

template <class c>
stack<c>::operator std::string() const {
    return "Test";
}

// Testing only
int main(){
    stack<int> f(10);
    printf("%d\n", f.size());
    f.push(5);
    f.push(10);
    for (int i = 0; i < f.size()-1; i++){
        printf("%d element is %d\n", i, f[i]);
    }

    printf("Popped value is %d\n", f.pop());

    printf("After Pop\n");
    for (int i = 0; i < f.size()-1; i++){
        printf("%d element is %d\n", i, f[i]);
    }

    return 0;
}