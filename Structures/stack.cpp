#include <cstdlib>
#include <iostream>

template <class c>
class stack{
    private:
        int length;
        c* head;
    public:
        stack(c length);
        ~stack();
        int size();
};

template <class c>
stack<c>::stack(c length)
{
    this->head = (c*) calloc(length, sizeof(c));
    this->length = length;
}

template <class c>
stack<c>::~stack()
{
    free(this->head);
}

template <class c>
int stack<c>::size(){
    return this->length;
}

int main(){
    stack<int> f(10);
    printf("%d", f.size());
    return 0;
}