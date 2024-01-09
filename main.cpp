#include "adder.h"
#include <random>


template <class T>
void bucketSort(DynamicArray<T>* array){
    T max_value = *array->index(0);
    T min_value = *array->index(0);

    for(int i =0; i < array->lenght; i++){
        T temp = *array->index(i);
        if(maxHepify(temp,max_value)){
            max_value = temp;
        }
        if(maxHepify(min_value,temp)){
            min_value = temp;
        }
    }

    auto* bucket = new DynamicArray<DynamicArray<T>>();

    int bucketAmount = ceil((max_value-min_value)/10);

    for (int i = 0; i <= bucketAmount; ++i) {
        bucket->add(* new DynamicArray<T>());
    }

    for (int i = 0; i < array->lenght; ++i) {
        T temp = * array->index(i);
        int numbBucket = floor((temp-min_value)/10);
        bucket->index(numbBucket)->add(temp);
    }

    int  k = 0;
    for (int i = 0; i <= bucketAmount; ++i) {
        bucket->index(i)->bubbleSort(maxHepify);
        for (int j = 0; j < bucket->index(i)->lenght; ++j) {
            array->modify(k,*bucket->index(i)->index(j));
            k++;
        }
    }
}


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

    auto* array1 = new DynamicArray<float>();
    for (int i = 0; i <10 ; ++i) {
        array1->add((float)(rand()) / (float)(rand()));
    }
    bucketSort(array1);

    array1->show();

    return 0;
}
