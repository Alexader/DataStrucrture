//impletion for a hash table based dictionary
template<typename Key, typename E>
class KVpair<Key, E> {
private:
    Key key;
    E ele;
public:
    //Constructor
    KVpair(Key key, E e) { setPair(key, e); }
    //copy constructor
    KVpair(const KVpair<Key, E>& pair) {
        key = pair.key;
        ele = pair.ele;
    }
    Key getKey() { return key; }
    void setPair(Key key, E e) { 
        key = key;
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
    Key EMPTY_KEY;
    //to get the hash value of key of int type
    int hash(int key) const {
        return key % count;
    }
    //to get hash value of key of string
    int hash(char* str) {

    }
    int p(Key key, int pos) {
        return pos*2;
    }
public:
    Dictionary(const int maxSize) {
        HT = new KVpair<Key, E>[maxSize];
        count = current = 0;
    }

    void hashInsert(const Key& K, const E& ele) {
        int pos = home = hash(K);//home position for each key which may conflict
        for(int i=0;EMPTY_KEY != HT[pos].getKey();i++) {
            pos = (home+p(K, i)) % count;
            Assert(K != HT[pos].getKey(), "Duplicated not allowed");
        }
        KVpair<Key, E> temp(K, ele);
        HT[pos = temp;
    }
    bool hashSearch(const Key &K) {
        int home = pos = hash(K);
        //you have to be carefull when it goes to infinte loop
        for(int i=0;EMPTY_KEY != HT[pos].getKey();i++) {
            if(HT[pos].getKey() == K) return true;
            pos = (home + p(K, i)) % count;
            if(i>count) break;
        }
        else return false;
    }
    int size(){ return current; }
}