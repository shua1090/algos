#include <cstdlib>
#include <iostream>
#include "dataStructs.hpp"

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
        throw std::out_of_range("Pushing is impossible due to lack of allocated storage; Please reallocate the stack or pop.");
        return 1;
    } else {
        *(this->head+this->current) = element;
        current += 1;
    }
    return 0;
}

template <class c>
c stack<c>::pop () {
    printf("Popping");
    c result = head[--current];
    head[this->current] = (c) NULL;
    return result;
}

template <class c>
c stack<c>::peek(int index) const {
    if (index > this->length || index < 0) {
        throw std::out_of_range("Unfortunately, your given Index was out of the valid range");
    } else {
        return head[index];
    }
}

template <class c>
c stack<c>::operator[] (int index) const {
    peek(index);
}

template <class c>
int stack<c>::search(c obj) const{
    for (int i = 0; i < this->current; i++){
        if (head[i] == obj){
            return i;
        } else {
            continue;
        }
    }
    return -1; // Could not find the object with current method.
}

// template <class c>
// std::string stack<c>::toString () const {
//     return std::string("Stack object with head at ") + std::string(this->head) + std::string(" and size of ") + std::to_string(this->length);
// }

// Testing only
int main(){
    stack<int> f(10);
    for (int i = 1; i < 11; i++){
        f.push(i);
    }

    return 0;
}