#include "adder.h"

int main() {
    int array[] = {3,8,5,2,9,1};
    int size = sizeof(array)/4;

    countingSort(array,size);

    for (int i = 0; i < size; ++i) {
        std::cout << array[i] <<"\t";
    }

    auto* heap = new MaxHeap(array,size);
    cout << endl;
    heap->show();
    cout << endl;
    heap->sort();
    heap->show();

    return 0;
}
