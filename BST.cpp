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
};

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
        clearHelp(subroot->getLetfChild());
        clearHelp(subroot->getRightChild());
        delete subroot;
    }
    bool findHelper(BinNode<E> *subroot, E &ele)
    {
        if (root == NULL)
            return false;
        else if (ele == root->getValue())
            return true;
        else if (ele < root->getValue())
            findHelper(root->getLetfChild(), ele);
        else if (ele > root->getValue())
            findHelper(root->getRightChild(), ele);
        else { return false; }
    }
    BinNode<E>*& insertHelper(BinNode<E>* subroot, E &ele) {
        if(ele == subroot->getValue()) {subroot->setValue(removeMin(subroot));}
        if(ele > subroot->getValue()) insertHelper(subroot->getLetfChild(), ele);
        else insertHelper(subroot->getRightChild(), ele);
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
    BinNode<E>*&  insert(E ele) { insertHelper(root, ele); }
    E& remove(E eel) { }
    traversal();
};