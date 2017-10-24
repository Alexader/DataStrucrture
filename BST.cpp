//node in the tree ADT
template <class E>
class BinNode
{
  private:
    E ele;
    BinNode *lc;
    BinNode *rc;

  public:
    BinNode(E &element, BinNode *&left, BinNode *&right)
    {
        ele = element;
        lc = left;
        right = rc;
    }
    E &getValue() { return ele; }
    bool setValue(E& element) { ele = element; }
    BinNode *&getLetfChild() { return lc; }
    BinNode *&getRightChild() { return rc; }
}

//this is a BST(binary search tree)
template <class E>
class BST
{
  private:
    BinNode<E> *root;
    int nodeCount;
    //some helper to do the right thing
    void clearHelp(BinNode<E> *subroot)
    {
        if (subroot == NULL)
            return;
        clearHelp(subroot->lc);
        clearHelp(subroot->rc);
        delete subroot;
    }
    bool findHelper(BinNode<E> *subroot, E &ele)
    {
        if (root == NULL)
            return false;
        if (ele == root->ele)
            return true;
        if (ele < root->ele)
            find(root->lc, ele);
        if (ele > root->ele)
            find(root->rc, ele);
        return false;
    }
    BinNode<E>*& insertHelper(BinNode<E>* subroot, E &ele) {
        if(ele==subroot->ele) {subroot->setValue(removeMin(subroot));}
        if(ele>subroot->ele) insertHelper(subroot->lc, ele);
        else insertHelper(subroot->rc, ele);
    }

  public:
    BST()
    {
        root = NULL;
        nodeCount = 0;
    }

    void clear()
    {
        clearHelp(root);
        root = NULL;
        nodeCount = 0;
    }
    bool find(E &ele) { return findHelper(root, ele); }
    BinNode*&  insert(E ele) { insertHelper(root, ele); }
    E& remove(E eel) { }
    traversal();
}