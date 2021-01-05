/*
Stack Class for LIFO
*/
template <class c>
class stack{
    private:
        int length;
        c* head;
        int current;
    public:
        stack(c length);
        ~stack();
        int size(); // Return the predetermined size of stack

        // Official Stack Methods
        int push(c element); // Push an element to the stack
        c pop(); // Pop off the end of the stack

        // Getting without Popping
        c peek(int index) const;
        c operator[] (int index) const;

        // Search Methods
        int search(c obj) const; // Simple Search. ~ Linear Time.

        // Overloads
        std::string toString() const;
};