#include<iostream>
using namespace std;
int defaultValue = 20;
template<class Elem>
class Stack {
public:
    virtual void clear() = 0;
    virtual bool push(const Elem ele) = 0;
    virtual bool pop(Elem &ele) = 0;
    virtual bool topValue(Elem &ele) = 0;
    virtual int length() = 0;
};

template<class Elem>
class ArrayStack: public Stack<Elem> {
private:
    int maxSize;
    int top;
    Elem* arrayStack;
public:
    ArrayStack(int size = defaultValue) {
        maxSize = size;
        arrayStack = new Elem[maxSize];
        top = -1;
    }
    ~ArrayStack() {
        delete[] arrayStack;
    }
    void clear() {
        top = -1;
    }
    bool push(Elem ele) {
        if(top==maxSize-1) return false;
        arrayStack[++top] = ele;
        return true;
    }
    bool pop(Elem& ele) {
        if(top==-1) return false;
        ele = arrayStack[top--];
        return true;
    }
    bool topValue(Elem &ele) {
        if(top==-1) return false;
        ele = arrayStack[top];
        return true;
    }
    int length() {
        return top;
    }
    void print() {
        for(int i=0;i<this->length();i++)
            cout<<arrayStack[i]<<" ";
        cout<<endl;
    }
};

int main() {
    ArrayStack<int> stack(10);
    for(int i=0;i<10;i++)
        if(!stack.push(i))
            cout<<"failure"<<endl;
    cout<<"this is stack length:"<<stack.length()<<endl;
    stack.print();
    int temp;
    for(int i=0;i<5;i++) {
        stack.pop(temp);
        cout<<temp<<" is poping out"<<endl;
    }
    stack.topValue(temp);
    cout<<"top value in stack is:"<<temp<<endl;
}