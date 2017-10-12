template<typename Elem>
class ArrayList() {
private:
    int* list;
    int size;
    int listLengh;
    int rightLengh;
    int leftLengh;
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