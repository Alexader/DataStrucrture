/*
Description

给定集合类的模板抽象类如下：

template<class Elem>

class Set

{

public:

    //在集合中插入一个元素 e

    virtual void Insert(const Elem& e) = 0;

    //在集合中删除一个值等于e的元素，如果删除成功则返回true，否则返回false

virtual bool Remove(const Elem& e) = 0;

//获取最早加入到集合第一个元素，该元素的值记录在参数e中返回。如果集合为空，则函数返回false,否则返回true。   

virtual bool GetFirstElement(Elem& e) = 0;

//获取最晚加入到集合的元素，该元素的值记录在参数e中返回。 如果集合为空，则函数返回false,否则返回true。   

    virtual bool GetLastElement(Elem& e) = 0;

    //获取集合的元素的个数

    virtual int GetSize() = 0;

    //获取集合所有元素的值记录在参数array中返回。函数返回集合元素的个数

    virtual int GetElements(Elem array[ ]) = 0;

  //按进入集合的次序，依次打印输出集合中的元素

    virtual void Print() = 0;

    //将集合s中的元素合并到当前集合中

    virtual void operator += (Set<Elem> & s) = 0;

};

 

请实现一个继承上述抽象类的集合类ASet，并利用该集合类完成集合操作。

Input

 输入数据有三行，每一行对应一个整数集合的元素，排列的顺序是各个元素进入到集合中的先后顺序。这三个整数集合依次记为集合S1、S2和S3。集合的元素的个数不超过1000个，每个元素的取值范围是1～65536。

Output

输出结果分为5行，第1行输出集合S1中第一个元素和最后一个元素；第2行输出集合S2的元素的个数；第3行按进入集合的先后顺序输出S3中的所有元素；第4行，将集合S2合并到S1后，按进入集合的先后次序打印输出S1中的元素；第5行，将集合S2减去集合S3后，按进入集合的先后次序打印输出S2中的元素。

Sample Input

1 3 4 5 6 7 8
2 3 4 10 12
1 3 4 100 101
Sample Output

1 8
5
1 3 4 100 101
1 3 4 5 6 7 8 2 10 12
2 10 12
*/
#include<iostream>
using namespace std;

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
    //实现集合的减法
    virtual void operator-=(Elem &B) = 0;
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
            array[i] = set[i];
        }
        return length;
    }
    void Print() {
        for(int i=0;i<length;i++) {
            cout<<set[i]<<' ';
        }
        cout<<endl;
    }
    void operator+=(Set<Elem> & B) {
        Elem array = new Elem[B.GetSize()];
        B.GetElements(array);        
        for(int i=0;i<B.GetSize();i++) {
            insert(array[i]);
        }
    }
    void operator-=(Set<Elem> &B) {
        Elem array = new Elem[B.GetSize()];
        B.GetElements(array);
        for(int i=0;i<B.GetSize();i++) {
            remove(array[i]);
        }        
    }
}

int main() {
    int a;
    int[] array = new int[3][1000];
    for(int i=0;i<3;i++) {
        int j = 0;
        while(cin>>a) {
            array[i][j] = a;            
            j++;
        }
    }

    Set<int>A(array[0]);
    Set<int>B(array[1]);
    Set<int>C(array[2]);    
    cout<<A.GetFirstElement()<<' '<<A.GetLastElement()<<endl;
    cout<<B.GetSize()<<endl;
    C.Print();
    A+=B;
    A.Print();
    B-=C;
    B.Print();
}