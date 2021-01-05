/*
Stack Class for LIFO
*/
template <class cls>
class stack{
    private:
        int length; // Amount of elements in the stack; Currently immutable
        cls* head; // Starting Memory Address of the stack
        int current; // Current "node"
    public:
        stack(cls length); // Constructor
        ~stack(); // Destructor
        int size(); // Return the predetermined size of stack

        // Official Stack Methods
        int push(cls element); // Push an element to the stack
        cls pop(); // Pop off the end of the stack

        // Getting without Popping
        cls peek(int index) const;
        cls operator[] (int index) const;

        // Search Methods
        int search(cls obj) const; // Simple Search. ~ Linear Time.

        // Overloads
        std::string toString() const;
};

template <class keycls, class valcls>
class HashTable{
    private:
        int hashFunction(keycls c);
    public:
        HashTable();
        ~HashTable();
};