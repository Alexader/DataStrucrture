template<typename Elem>
class Node() {
private:
    Elem element;
    Node* next;
    Node* prev;
public:
    Node(Node* nextPtr = NULL, Node* prevPtr = NULL) {
        next = nextPtr;
        prev = prevPtr;
    }
    Node(Elem &e, Node* nextPtr = NULL, Node* prevPtr = NULL) {
        element = e;
        next = nextPtr;
        prev = prevPtr;
    }
}
//class for double lineked list
template<typename Elem>
class LinkedList() {
private:
    Node* head;
    Node* tail;
    Node* fence;
    int listLength;
    int rightLength;
    int leftLength;
public:
    LinkedList();
    ~LinkedList();
    void clear();
    bool setStart();
    bool setEnd();
    int insert(Elem elem);
    int leftLength() const {return leftLength;}
    int rightLength() const {return rightLength;}
    bool getValue(Elem &e);
    bool remove(Elem elem);
    bool append(Elem elem);
    bool setPosition(int pos);
}

template<typename Elem>
void LinkedList::clear() {
    while(head!=NULL) {
        fence = head;
        head = head->next;
        delete fence;
    }
}
template<typename Elem>
LinkedList::LinkedList() {
    head = fence = tail = new Node();
    listLengh = rightLength = leftLength = 0;
}

template<typename Elem>
void LinkedList::setStart() {
    fence = head;
    leftLength = 0;
    rightLength = listLengh;
}

template<typename Elem>
void LinkedList::setEnd() {
    fence = tail;
    rightLength = 0;
    leftLength = listLengh;
}

template<typename Elem>
bool LinkedList::getValue() {
    if(fence==head) return false;
    it = fence->next->element;
    return true;
}
template<typename Elem>
int LinkedList::insert(Elem &e) {
    if(fence == tail) {
        fence->next = new Node(e, NULL, fence);
    }
    else {
        fence->next = fence->next->prev = new Node(e, fence->next, fence);        
    }
    rightLength++;
    listLength++;
    return leftLength;
}

template<typename Elem>
bool LinkedList::remove(Elem &e) {
    if(fence==tail) return false;
    fence->next->next->prev = fence;
    Node* temp = fence->next->next;
    e = temp->prev->element;
    delete fence->next;
    fence->next = temp;
    rightLength--;
    listLength--;
    return true;    
}

template<typename Elem>
void LinkedList::append(Elem &e) {
    tail->next = new Node(e, NULL, tail);
    listLength++;
    rightLength++;
}

template<typename Elem>
bool LinkedList::setPosition(int pos) {
    if(pos>listLength || pos<0) return false;
    fence = head;
    for(int i=0;i<pos;i++) {
        fence = fence->next;
    }
    leftLength = pos;
    rightLength = listLength-leftLength;
    return true;
}
