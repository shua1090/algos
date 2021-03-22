#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <cstdlib>
#include <cstdio>

template <class T>
class ArrayList{
private:
    T* mHead;
    int mCapacity;
    int mSize;

    void swap(T* r, T* s) {
        T temp = *r;
        *r = *s;
        *s = temp;
    }

    int bottomsUp(int index){
        if (index < 0){
            index = this->mSize + index;
        }
        return index;
    }

public:

    ArrayList() {
        this->mCapacity = 1;
        this->mHead = (T *) calloc(this->mCapacity, sizeof(T));
        this->mSize = 0;
    }

    ArrayList(int initialSize) {
        this->mCapacity = initialSize;
        this->mHead = (T *) calloc(this->mCapacity, sizeof(T));
        this->mSize = 0;
    }

    ArrayList(const ArrayList& other) {
        mSize = other.mSize;
        mCapacity = other.mCapacity;
        mHead = (T*) calloc(mCapacity, sizeof(T));
        for (int i = 0; i < other.mSize; i++){
            mHead[i] = other.mHead[i];
        }
    }

    ~ArrayList() {
        printf("Destroying\n");
        free(this->mHead);
    }

    int getCapacity() const {
        return this->mCapacity;
    }

    int getSize() const {
        return this->mSize;
    }

    int setCapacity(int newcap) {
        if (newcap > mCapacity) {
            this->mHead = (T*) realloc(this->mHead, this->mCapacity * sizeof(T) * 2);
            return 0;
        }
        return -1;
    }

    int optimize(){
        for (int i = 1; i < this->getSize(); i++){
            if (this->get(i) != 0 && this->get(i-1) == 0){
                swap(&this->mHead[i], &this->mHead[i-1]);
                i = 0;
            }
        }
        return 0;
    }


    void sort() {
        for (int i = 0; i < this->mSize; i++){
            int ind = i;
            for (int j = i; j < this->mSize; j++){
                if (this->get(j) < this->get(ind)) {
                    ind = j;
                }
            }
            swap(&this->mHead[i], &this->mHead[ind]);
        }
        return;
    }

    void sort(int(*func)(T, T)) {
        for (int i = 0; i < this->mSize; i++){
            int ind = i;
            for (int j = i; j < this->mSize; j++){
                if (func(this->get(j), this->get(ind)) == -1){
                    ind = j;
                }
            }
            swap(&this->mHead[i], &this->mHead[ind]);
        }
        return;
    }

    int append(T val) {
        if (mSize >= mCapacity) {
            this->mHead = (T*) realloc(this->mHead, this->mCapacity * sizeof(T) * 2);
            if (this->mHead == nullptr){
                //printf("\n%d ", this->mSize);
                //printf("%d ", this->mCapacity*sizeof(T));
                printf("SHOOT ITS NULL");
                exit(-1);
            }
            mCapacity = mSize * 2;
        }
        // printf("Appending");
        mHead[mSize] = val;
        this->mSize++;
        return 0;
    }

    static ArrayList<T> combine(const ArrayList<T>& list1, const ArrayList<T>& list2) {
        ArrayList<T> out(list1.getSize() + list2.getSize());

        for (int i = 0; i < list1.getSize(); i++){
            out.append(list1.get(i));
        }

        for (int j = 0; j < list2.getSize(); j++){
            out.append(list2.get(j));
        }

        return out;
    }

    ArrayList<T> combine(const ArrayList<T>& list1) {
        ArrayList<T> out(list1.getSize() + this->getSize());

        for (int i = 0; i < this->getSize(); i++){
            out.append(this->get(i));
        }

        for (int j = 0; j < list1.getSize(); j++){
            out.append(list1.get(j));
        }

        return out;
    }

    void fill(T obj){
        for (int i = 0; i < this->getCapacity(); i++){
            this->set(i, obj);
        }
        this->mSize = this->getCapacity();
    }
    void clear(){
        for (int i = 0; i < mCapacity; i++){
            this->mHead[i] = 0;
        }
        this->mSize = 0;
    }

    int set(int index, T item){

        index = bottomsUp(index);
        if (index < 0) return -1;

        if (index > this->mSize) {
            mSize = index;
        }

        mHead[index] = item;
        return 0;
    }

    int remove(int index){

        index = bottomsUp(index);
        if (index < 0) return -1;
        if (index > this->mSize) {
            return -1;
        }

        else if (index == this->mSize -1) this->mSize--;
        this->mHead[index] = 0;

        return 0;
    }

    int search(T val) const {
        for (int i = 0; i < mSize; i++){
            if (val == this->get(i)){
                return i;
            }
        }
        return -1;
    }

    int binSearch(T val){
        int pivot = static_cast<int>(this->mSize / 2);
        T pivotVal = this->get(pivot);
        while (pivotVal != val){
            if (pivot == 0 || pivot == this->mSize){
                return -1;
            }

            if (pivotVal < val){
                pivot = this->mSize + (this->mSize - pivot)/2;
                pivotVal = this->get(pivot);
            } else if (pivotVal > val){
                pivot = (pivot)/2;
                pivotVal = this->get(pivot);
            }

        }
        return pivot;
    }

    int binSearch(T val, int(*func)(T, T)){
        int pivot = static_cast<int>(this->mSize / 2);
        T pivotVal = this->get(pivot);
        while ( func(pivotVal, val) != 0){

            if (pivot == 0 || pivot == this->mSize){
                return -1;
            }

            if (func(pivotVal, val) == -1){
                pivot = this->mSize + (this->mSize - pivot)/2;
                pivotVal = this->get(pivot);
            } else if (func (pivotVal, val) == 1) {
                pivot = pivot/2;
                pivotVal = this->get(pivot);
            }
        }
        return pivot;
    }

    T pop() {
        if (this->mSize >= 1){
            this->mSize--;
        } else {
            printf("Cannot pop element, nothing left on stack.");
            exit(-1);
        }

        T val = this->get(this->mSize);
        if ( remove(this->mSize) == -1 ){
            printf("Tried removing an element that doesn't even exist");
            exit(-1);
        }

        return val;
    }

    T get(int index)  {

        index = bottomsUp(index);
        if (index < 0) return -1;

        if (index > this->mSize) return -1;

        return this->mHead[index];
    }

    ArrayList<T> subArray(int startIndex, int endIndex) {

        startIndex = bottomsUp(startIndex);
        endIndex = bottomsUp(endIndex);

        if (startIndex >= endIndex) return 0;
        if (endIndex >= this->getSize()) return 0;
        if (startIndex < 0) return 0;

        ArrayList<T> a(endIndex-startIndex);
        for (int i = startIndex; i < endIndex; i++){
            a.append(this->get(i));
        }

        return a;
    }

    T& operator[](int index){
        if (index > this->mSize){
            printf("Index Out of Bounds");
            exit(-1);
        }
        return this->mHead[index];
    }

    const T& operator[](int index) const {

        index = bottomsUp(index);
        if (index < 0) return 0;

        if (index > this->mSize){
            printf("Index Out of Bounds\n");
            exit(-1);
        }
        return this->mHead[index];
    }

    void operator << (T val){
        this->append(val);
    }

    void operator >> (T &val) {
        val = this->pop();
    }

    ArrayList<T> operator + (const ArrayList<T>& list2){
        return combine(list2);
    }

    void print() {

        printf("[");

        for (int i = 0; i < this->mSize; i++){
            printf("%d", this->get(i));
            if (i != this->mSize-1){
                printf(", ");
            }
        }

        printf("]\n");
    }

};

#endif