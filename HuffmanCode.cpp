/*this is completion for huffman code tree based on a heap */
#include <iostream>
using namespace std;

//class type for max heap
template<typename E>
class Heap {
private:
    E* heap;
    int num;
    int size;
    void swap(E* heap, const int swap1, const int swap2) {
        E temp = heap[swap1];
        heap[swap1] = heap[swap2];
        heap[swap2] = temp;
    }
    void siftDown(int root) {
        //this algrithm is based on the assumption that the left and right child
        //of this root already satisfy being a max heap
        int j = root;
        while (!isLeaf(j)) {
            j = leftChild(root);
            if (rightChild(root)<num && heap[j]<heap[rightChild(root)]) j = rightChild(root);//j always point to the larger child
            if (heap[root] < heap[j]) {
                swap(heap, root, j);
                root = j;
            }
            else break;// already satisfy maxheap
        }
    }
public:
    Heap(E* arr, int number, int maxSize) {
        heap = arr;
        size = maxSize;
        num = number;
        buildHeap();
    }
    int heapSize() { return num; }
    int Parent(int pos) { return (pos - 1) / 2; }
    int leftChild(int pos) { return pos * 2 + 1; }
    int rightChild(int pos) { return pos * 2 + 2; }
    bool isLeaf(int pos) { return leftChild(pos) >= num; }

    void buildHeap() {
        //bulid from the bottom
        for (int i = num / 2 - 1; i >= 0; i--) siftDown(i);
    }
    E getMax() { return heap[0]; }//time complexity is O(1)
    E removeMax() {//time complexity is O(log(n))
        if (num == 0) {
            cout << "heap is empty" << endl;
            exit(1);
        }
        swap(heap, 0, num - 1);
        num--;
        siftDown(0);
        return heap[num];
    }
    void insert(E ele) {//time complexity is O(log(n))
        if (num >= size) {
            cout << "heap is full" << endl;
            exit(1);
        }
        heap[num++] = ele;
        int head = num - 1;
        while (head != 0) {
            if (heap[head]>heap[Parent(head)]) {
                //to find a apropriate position for new element
                swap(heap, head, Parent(head));
                head = Parent(head);
            }
            else break;
        }
    }
    void print() {
        for (int i = 0; i<num; i++)
            cout << heap[i] << " ";
        cout << endl;
    }

};

int main() {
    int arr[] = { 111,12,23,44,95,64,72,4,45,20 };

    Heap<int> heap(arr, 10, 20);
    heap.print();
    heap.insert(9);

    for (int i = 0; i<10; i++) {
        cout << heap.removeMax() << endl;
        heap.print();
    }
    cout << heap.heapSize() << endl;
}
