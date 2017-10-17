const int defaultValue = 20;
template<class Elem>
class Stack {
public:
    virtual void clear() = 0;
    virtual bool push(Elem &ele) = 0;
    virtual bool pop(Elem &ele) = 0;
    virtual bool topValue(Elem &ele) = 0;
    virtual int length() = 0; 
}

template<class Elem>
class ArrayStack: public Stack<Elem> {
private:
    int size;
    int top;
    Elem* arrayStack;
public:
    ArrayStack(int mSize = defaultValue) {
        size = mSize;
        arrayStack = new Elem[size];
        top = 0;
    }
    void clear() {
        top = 0;
    }
    bool push(Elem &ele) {
        if(top==0) return false;
        arrayStack[top++] = ele;
        return true;
    }
    bool pop(Elem &ele) {
        if(top==0) return false;
        arrayStack[top--] = ele;
        return true;
    }
    bool topValue(Elem &ele) {
        if(top==0) return false;
        ele = arrayStack[top];
        return true;
    }
    int length() {
        return top;
    }
}