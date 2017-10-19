//queue ADT
template<class E>
class Queue {
private:
    E* queue;
    int maxSize;

public:
    void clear() = 0;
    void enqueue(E &ele) = 0;
    E dequeue() = 0;
    int length() = 0;
}
//queue based on array
template<class E>
class AQueue:public Queue {
private:
    E* queue;
    int front;
    int rear;
    int maxSize;

public:
    AQueue(int size) {
        maxSize = size;
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
    void enqueue(E &ele) {
        Assert((rear+2)%maxSize == front, "queue is full");
        rear = (rear+1)%maxSize;
        queue[rear] = ele;       
    }
    E dequeue() {
        Assert((rear+1)%maxSize == front, "queue is empty");
        E temp = queue[front];
        front = (front+1)%maxSize;
        return temp;
    }
    int length() {
        return (rear-front+1+maxSize)%maxSize;
    }
}