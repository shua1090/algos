#include "dataProc.hpp"
#include <cstdio>

template<class myType>
int sequentialSearch(myType arr[], int length, myType value){
    for (int i = 0; i < length; i++){
        if (arr[i] == value){
            return i;
        }
    }
    return -1;
}

int main(){
    printf("best\n");

    int arr[] = {
        1, 3, 8, 7, 10, 14, 30, 27, 12, 5
    };

    int a = sequentialSearch<int>(arr, sizeof(arr), 5);

    printf("It's index: %d", a);

    return 0;
}