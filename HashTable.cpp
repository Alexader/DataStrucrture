#include<iostream>
#include<assert.h>
using namespace std;
//impletion for a hash table based dictionary
template<typename Key, typename E>
class KVpair {
private:
    Key key;
    E ele;
public:
    //Constructor
    KVpair() {
        key = -1; ele = E();
    }
    KVpair<Key, E>(Key key, E e) { setPair(key, e); }
    //copy constructor
    KVpair<Key, E>(const KVpair<Key, E>& pair) {
        key = pair.key;
        ele = pair.ele;
    }
    Key getKey() { return key; }
    void setPair(Key k, E e) {
        key = k;
        ele = e;
    }
};

//this dictionary is based on hash table
template<typename Key, typename E>
class Dictionary {
private:
    //KVpair object in a array as a hash table;
    KVpair<Key, E>* HT;
    int count;//count for the length of dictionary
    int current;
    Key EMPTY_KEY = -1;
    //to get the hash value of key of int type
    int hash(Key key) const {
        return (int)key % count;
    }
    //to get hash value of key of string
    int hash(char* str) {
        return 0;
    }
    int p(Key key, int pos) {
        return pos * 2;
    }
public:
    Dictionary(const int maxSize) {
        count = maxSize;
        HT = new KVpair<Key, E>[count];
        current = 0;
    }

    void hashInsert(const Key& K, const E& ele) {
        int pos, home, i;
        pos = home = hash(K);//home position for each key which may conflict
        for (i = 0; K != HT[pos].getKey() && EMPTY_KEY != HT[pos].getKey() && i<count; i++) {
            pos = (home + p(K, i)) % count;
        }
        if (K == HT[pos].getKey())
            cout << "This key already exist" << endl;
        else if (i == count)
            cout << "This hash table is full" << endl;
        else {
            cout << "Find a empty place and insert keyword " << K << endl;
            KVpair<Key, E> temp(K, ele);
            HT[pos] = temp;
            current++;
        }
    }
    bool hashSearch(const Key &K) {
        int pos, home;
        home = pos = hash(K);
        //you have to be carefull when it goes to infinte loop
        for (int i = 0; i<current && EMPTY_KEY != HT[pos].getKey(); i++) {
            if (HT[pos].getKey() == K) return true;
            pos = (home + p(K, i)) % count;
            if (i>count) break;
        }
        return false;
    }
    int size() { return current; }
};

int main() {
    Dictionary<int, int> dic(10);
    for (int i = 0; i<5; i++) {
        dic.hashInsert(i, i*i);
        cout << "done" << endl;
    }
    for (int i = 0; i < 10; i+=2) {
        if (dic.hashSearch(i))
            cout << "find keyword " << i << endl;
        else
            cout << "not found " << i << endl;
    }
}