template<typename Elem>
class Node() {
private:
    Elem element;
    Node* next;
public:
    Node(Node* ptr = NULL) {
        next = ptrt;
    }
    Node(Elem &e, Node* ptr = NULL) {
        element = e;
        next = ptr;
    }
}
template<typename Elem>
class LinkedList() {
private:
    Node* head;
    Node* fence;
    int listLength;
    int rightLength;
    int leftLength;
public:
    LinkedList();
    ~LinkedList();
    int setStart();
    int setEnd();
    int insert(Elem elem);
    int remove(Elem elem);
    int append(Elem elem);
    int setPosition(int pos);
}

template<typename Elem>
LinkedList::LinkedList() {
    head = fence = new Node();
    listLengh = rightLength = leftLength = 0;
}

template<typename Elem>
int LinkedList::setStart() {
    fence = head;
    leftLength = 0;
    rightLength = listLengh;
}

template<typename Elem>
int LinkedList::setEnd() {
    fence = listLengh;
    rightLength = 0;
    leftLength = listLengh;
}

template<typename Elem>
int LinkedList::insert(Elem &e) {
    Node* tempNode = head;
    while(temp<fence) {
        tempNode = tempNode->next;
    }
}

template<typename Elem>
int LinkedList::remove() {

}

template<typename Elem>
int LinkedList::append() {

}

template<typename Elem>
int LinkedList::setPosition() {

}