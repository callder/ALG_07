#include <iostream>;
#include <cmath>

using namespace std;
template <class T>
bool maxHepify(T first, T second){
    return first > second;
}
template <class T>
bool minHepify(T first, T second){
    return !(first > second);
}

void countingSort(int array[], int n){
    int max = array[0];
    for (int i = 0; i < n; ++i) {
        if (array[i] > max) max = array[i];
    }

    int*count = new int[max+1]();

    for (int i = 0; i < n; ++i) {
        count[array[i]]++;
    }
    int k = 0;
    for (int i = 0; i <= max; ++i) {
        while(count[i] > 0){
            array[k] = i;
            count[i]--;
            k++;
        }
    }

    delete[] count;
}


class MaxHeap {
private:
    int *heap;
    int capacity;
    int last;

    int getParent(int i) { return (i - 1) / 2; }

    int getLeftChild(int i) { return 2 * i + 1; }

    int getRightChild(int i) { return 2 * i + 2; }

    void heapUp(int i) {
        if (i > 0 && heap[i] > heap[getParent(i)]) {
            swap(heap[i], heap[getParent(i)]);
            i = getParent(i);
            heapUp(i);
        }
    }

    void heapDown(int i) {
        while (true) {
            int leftChild = getLeftChild(i);
            int rightChild = getRightChild(i);
            int largest = i;

            if (leftChild < last && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }

            if (rightChild < last && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

public:
    MaxHeap(int capacity) {
        heap = new int[capacity];
        this->capacity = capacity;
        last = 0;
    }

    MaxHeap(int array[], int capacity) {
        heap = new int[capacity];
        this->capacity = capacity;
        last = 0;
        for (int i = 0; i < capacity; ++i) {
            add(array[i]);
        }

    }

    ~MaxHeap() { delete[] heap; }

    void sort(){
        for (int i = last - 1; i > 0; --i) {
            swap(heap[0], heap[i]);
            --last;
            heapDown(0);
        }
        last = capacity;
    }
    void show() {
        for (int i = 0; i < last; ++i) {
            cout << heap[i] << "\t";
        }
        cout << endl;
    }
    void add(int element) {
        if (last == capacity) {
            cout << "Heap is full" << endl;
            return;
        }
        heap[last] = element;
        heapUp(last);
        last++;
    }
    int del() {
        if (last == 0) {
            cout << "Heap is empty" << endl;
            return int();
        }

        int root = heap[0];
        heap[0] = heap[last - 1];
        last--;
        heapDown(0);
        return root;
    }
};

template <class T>
class DynamicArray{
private:
    int size;
    T * array;
    float increase = 2.0;
public:
    int lenght;

    DynamicArray(){
        size = 10;
        array = new T[10];
        lenght = 0;
    }
    ~DynamicArray(){
        delete array;
    }
    bool sizeControl(){
        return size*0.9 < lenght;
    }
    void sizeIncrease(){
        size = size*increase;
        auto *newArray = new T[size];
        for (int i = 0; i < lenght; ++i) {
            newArray[i] = array[i];
        }
        delete [] array;
        array = newArray;
    }
    void add(T s){
        if (sizeControl())
            sizeIncrease();
        array[lenght] = s;
        lenght++;
    }
    void erase(){
        delete [] array;
        this->size = 10;
        this->lenght = 0;
    }
    void modify(int ind, T s){
        if (lenght<=ind){
            cout << "Nieprawidlowy index" << endl;
            return;
        }
        array[ind] = s;
    }
    void bubbleSort(bool(*cmp)(T, T)){
        for(int i = 0; i<lenght;i++){
            for(int j = 0; j<lenght-i-1; j++){
                if(cmp(array[j],array[j+1])){
                    int temp = array[j];
                    array[j] =  array[j+1];
                    array[j+1] = temp;
                }
            }
        }
    }
    void return_min(){
        return array[0];
    }
    void return_max(){
        return array[lenght];
    }
    T  * index(int index){
        if(lenght<= index){
            //  cout<<"Index out of range!";
            return nullptr;
        }
        return &array[index];
    }

    void info(){
        cout << "Size" << this->size << "Length" << this->lenght << endl;
    }
    void search(int ind){
        if(lenght<= ind){
            cout<<"Index out of range!";
            return;
        }
        cout << array[ind] << endl;
    }
    void show(){
        for (int i = 0; i < lenght; ++i) {
            cout << array[i] << endl;
        }
    }

};

