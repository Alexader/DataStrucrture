//queue ADT
template<class E>
class Queue {
public:
    virtual void clear() = 0;
    virtual void enqueue(E &ele) = 0;
    virtual E dequeue() = 0;
    virtual int length() = 0;
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
//queue based on linked list
template<class E>
class Node<class E> {
private:
    E ele;
    Node* next;
public:
    Node(E& element, Node* nextPtr = NULL) {
        ele = element;
        next = nextPtr;
    }
}
template<class E>
class LQueue:public Queue {
private:
    Node* top;
    Node* bottom;
    int size;
public:
    LQueue() {
        size = 0;
        head = bottom = NULL;
    }
    ~LQueue() {
        clear();
    }
    void clear() {
        Node* temp = bottom;
        while(temp!=NULL) {
            bottom = bottom->next;
            delete temp;
            temp = bottom;
        }
        top = NULL;
    }
    void enqueue(E &ele) {
        Assert(bottom==NULL, "queue is empty");
        bottom = new Node(ele, bottom);
        size++;
    }
    E& dequeue() {
        Assert(bottom==NULL, "queue is empty");
        Node* temp = bottom;
        while(temp->next!=top) {
            temp = temp->next;
        }
        E tempEle;
        tempEle = top->ele;
        delete top;
        top = temp;
        size--;
        return tempEle;
    }
    int length() {
        return size;
    }
}