/*this is completion for huffman code tree based on a heap */

//class type for max heap
template<typename E>
class Heap {
private:
    E* heap;
    int num;
    int size;
    void swap(const E* heap, const int swap1, const int swap2) {
        E temp = heap[swap1];
        heap[swap1] = heap[swap2];
        heap[swap2] = temp;
    }
    void siftDown(int root) {
        //this algrithm is based on the assumption that the left and right child
        //of this root already satisfy being a max heap
        int j = root;
        while(!isLeaf(j)) {
            j = leftChild(root);
            if(j<rightChild(root)) j = rightChild(root);//j always point to the larger child
            swap(heap, root, j);
            root = j;
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
    int Parent(int pos) { return (pos-1)/2; }
    int leftChild(int pos) { return pos*2+1; }
    int rightChild(int pos) { return pos*2+2; }
    bool isLeaf(int pos) { return getLetfChild(pos)>=num; }

    void buildHeap() {
        //bulid from the bottom
        for(int i=num/2 - 1; i>0;i--) siftdown(i);
    }
    E getMax() { return heap[0]; }//time complexity is O(1)
    E removeMax() {//time complexity is O(log(n))
        Assert(num!=0, "none to remove")
        swap(heap, 0, num--)
        siftdown(0);
        return heap[num-1];
    }
    void insert(const E& ele) {//time complexity is O(log(n))
        Assert(num<maxSize, "heap is full");
        heap[num++] = ele;
        int head = num;
        while(head!=0) {
            if(heap[head]>heap[Parent(head)]) {
                //to find a apropriate position for new element
                swap(heap, head, Parent(head));
                head = Parent(head);
            }
            else break;
        }
    }
    
};