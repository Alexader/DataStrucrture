#include <iostream>
using std::cout;
using std::endl;

void Assert(bool statement, const char* str) {
    if(statement) cout<<str<<endl;
}
//queue ADT
template<class E>
class Queue {
public:
    Queue() {}
    virtual ~Queue() {}
    virtual void clear() = 0;
    virtual void enqueue(E ele) = 0;
    virtual void dequeue(E& temp) = 0;
    virtual int length() = 0;
};
//queue based on array
template<class E>
class AQueue:public Queue<E> {
private:
    E* queue;
    int front;
    int rear;
    int maxSize;

public:
    AQueue(int size) {
        maxSize = size+1;
        queue = new E[maxSize];
        front = 1;
        rear = 0;
    }
    ~AQueue() {
        delete[] queue;
    }
    void clear(){
        front = 1;
        rear = 0;
    }
    void enqueue(E ele) {
        Assert((rear+2)%maxSize == front, "queue is full");
        rear = (rear+1)%maxSize;
        queue[rear] = ele;   
    }
    void dequeue(E& temp) {
        Assert((rear+1)%maxSize == front, "queue is empty");
        temp = queue[front];
        front = (front+1)%maxSize;
    }
    int length() {
        return (rear-front+1+maxSize)%maxSize;
    }
    void print() {
        if((rear+1)%maxSize == front) { cout<<"queue is empty now"<<endl; return; }
        cout<<"current element in queue:"<<endl;
        for (int i = front; i < this->length(); i=(i+1)%maxSize)
            cout<<queue[i]<<" ";
        cout<<endl;
    }
};
//queue based on linked list
// template<class E>
// class Node<class E> {
// private:
//     E ele;
//     Node* next;
// public:
//     Node(E& element, Node* nextPtr = NULL) {
//         ele = element;
//         next = nextPtr;
//     }
// };
// template<class E>
// class LQueue:public Queue {
// private:
//     Node* top;
//     Node* bottom;
//     int size;
// public:
//     LQueue() {
//         size = 0;
//         head = bottom = NULL;
//     }
//     ~LQueue() {
//         clear();
//     }
//     void clear() {
//         Node* temp = bottom;
//         while(temp!=NULL) {
//             bottom = bottom->next;
//             delete temp;
//             temp = bottom;
//         }
//         top = NULL;
//     }
//     void enqueue(E &ele) {
//         Assert(bottom==NULL, "queue is empty");
//         bottom = new Node(ele, bottom);
//         size++;
//     }
//     E& dequeue() {
//         Assert(bottom==NULL, "queue is empty");
//         Node* temp = bottom;
//         while(temp->next!=top) {
//             temp = temp->next;
//         }
//         E tempEle;
//         tempEle = top->ele;
//         delete top;
//         top = temp;
//         size--;
//         return tempEle;
//     }
//     int length() {
//         return size;
//     }
// };

int main(int argc, char const *argv[])
{
    AQueue<int> q(10);
    for(int i=1;i<7;i++) {
        cout<<i<<" times"<<endl;
        q.enqueue(i);
    }
    cout<<"queue length is :"<<q.length()<<endl;
    q.print();
    int temp;
    for(int i=1;i<7;i++) {
        q.dequeue(temp);
        cout<<temp<<" is enqueued"<<endl;
    }
    q.print();
    return 0;
}
