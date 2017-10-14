template <class Elem>
class Set
{
  public:
    //在集合中插入一个元素 e
    virtual void Insert(const Elem &e) = 0;
    //在集合中删除一个值等于e的元素，如果删除成功则返回true，否则返回false
    virtual bool Remove(const Elem &e) = 0;
    //获取最早加入到集合第一个元素，该元素的值记录在参数e中返回。如果集合为空，则函数返回false,否则返回true。
    virtual bool GetFirstElement(Elem &e) = 0;
    //获取最晚加入到集合的元素，该元素的值记录在参数e中返回。 如果集合为空，则函数返回false,否则返回true。
    virtual bool GetLastElement(Elem &e) = 0;
    //获取集合的元素的个数
    virtual int GetSize() = 0;
    //获取集合所有元素的值记录在参数array中返回。函数返回集合元素的个数
    virtual int GetElements(Elem array[]) = 0;
    //按进入集合的次序，依次打印输出集合中的元素
    virtual void Print() = 0;
    //将集合s中的元素合并到当前集合中
    virtual void operator+=(Set<Elem> &s) = 0;
};

template<class Elem>
class ASet: public Set<Elem> {
private:
    int MaxSize;
    Elem* set;
    int length;

public:
    ASet(int size) {
        length =  0;
        MaxSize = size;
        set = new Elem[size];
    }
    void insert(const Elem &e) {
        if(length==MaxSize) return;
        for(int i=0;i<length;i++) {
            if(e == set[i]) return;
        }
        set[length-1] = e;
        length++;
    }
    void remove(const Elem &e) {
        if(length==0) return;
        for(int i=0;i<length;i++) {
            if(set[i]==e) {
                for(;i<length-1;i++){
                    set[i] = set[i+1];                     
                }
                return;
            }
        }
    }
    bool GetFirstElement(Elem &e) {
        if(length==0) return false;
        e = set[0];
        return true;
    }
    bool GetLastElement(Elem &e) {
        if(length==0) return false;
        e = set[length];
        return true;
    }
    int GetSize() {
        return length;
    }
    int GetElements(Ele array[]) {
        for(int i=0;i<length;i++) {
            insert(array[i]);
        }
        Print();
    }
    void Print() {
        for(int i=0;i<length;i++) {
            cout<<set[i]<<' ';
        }
        cout<<endl;
    }
    void operator+=(Set<Elem> & B) {
        Elem temp;
        for(int i=0;i<B.GetSize();i++) {
            insert(B.GetFirstElement());
            B.remove(B.GetFirstElement());
        }
    }
}
