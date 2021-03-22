#include "dataStructs.hpp"


template <class cls>
stack<cls>::stack(cls length) {
    this->head = (cls*) calloc(length, sizeof(cls));
    this->length = length;
    current = 0;
}

template <class cls>
stack<cls>::~stack() {
    free(this->head);
}

template <class cls>
int stack<cls>::size() {
    return this->length;
}

template <class cls>
int stack<cls>::push(cls element) {
    if (this->current >= this->length){
        throw std::out_of_range("Pushing is impossible due to lack of allocated storage; Please reallocate the stack or pop.");
        return 1;
    } else {
        this->head[current]= element;
        current += 1;
    }
    return 0;
}

template <class cls>
cls stack<cls>::pop () {
    printf("Popping");
    cls result = this->head[--current];
    this->head[this->current] = (cls) NULL;
    return result;
}

// template <class cls>
// cls stack<cls>::peek(int index) const {
//     if (index > this->length || index < 0) {
//         throw std::exception("Unfortunately, your given Index was out of the valid range");
//     } else {
//         return this->head[index];
//     }
// }

template <class cls>
cls stack<cls>::operator[] (int index) const {
    peek(index);
}

template <class cls>
int stack<cls>::search(cls obj) const{
    for (int i = 0; i < this->current; i++){
        if (head[i] == obj){
            return i;
        } else {
            continue;
        }
    }
    return -1; // Could not find the object with current method.
}
