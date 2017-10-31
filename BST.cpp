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
        if (subroot == NULL) return;
        clearHelp(subroot->getLetfChild());
        clearHelp(subroot->getRightChild());
        delete subroot;
    }
    //a helper for finding the smallest element in a tree specified by root
    E& removeMin(BinNode* root) {
        if(root->getLetfChild()==NULL) return root->getValue();
        removeMin(root->getLetfChild());
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
    //insert is relatively easy cause you just keep comparing till it is leaf
    BinNode<E>*& insertHelper(BinNode<E>* subroot, E &ele) {
        if(subroot==NULL) {
            subroot->setValue(ele);//this is the recursion export
            return subroot;
        }
        else if(ele >= subroot->getValue()) insertHelper(subroot->getRightChild(), ele);
        else insertHelper(subroot->getRightChild(), ele);
    }
    //to remove a node, you have to think about the situation when it is the node you want
    //to delete and you have rescale this tree.
    E& removeHelper(BinNode<E>* subroot, E &ell) {
        if(ele==subroot->getValue()) {
            E temp = subroot->getValue();
            subroot->setValue(removeMin(subroot->getRightChild()));
            return temp;
        }
        else if(ele>subroot->getValue()) { removeHelper(subroot->getRightChild(), ele); }
        else removeHelper(subroot->getLetfChild(), ele);
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
    BinNode<E>*&  insert(E ele) {
        insertHelper(root, ele);
        nodeCount++;
    }
    E& remove(E ele) {
        Assert(root==NULL, "tree is empty and cannot be removed")
        nodeCount--;
        return removeHelper(root, ele);
    }
    BinNode<E>*& insert(E& ele) {
        return insertHelper(subroot, ele);
    }
};
/*this kind of tree may encounter serious problem when the data entered in a sepcific way and
it will be extremely unbalanced and degenerate into a linked list.This is when B tree to help. */