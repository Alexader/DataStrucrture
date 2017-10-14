template<typename Elem>
class ArrayList() {
private:
    Elem* list;
    int maxSize;
    int listLength;
    int rightLength;
    int leftLength;
    int fence;
public:
    ArrayList();
    ~ArrayList();
    int setStart();
    int setEnd();
    int insert(Elem elem);
    int remove(Elem elem);
    int append(Elem elem);
    int setPosition(int pos);
}

ArrayList::ArrayList(int init_size) {
    maxSize = init_size;
    list = new Elem[maxSize];
    fence = listLength = rightLength = leftLength = 0;
}

int ArrayList::setStart() {
    fence = 0;
}

int ArrayList::setEnd() {
    fence = listLengh;
}
