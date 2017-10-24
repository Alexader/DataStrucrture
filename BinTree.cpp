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
    E &getValue()
    {
        return ele;
    }
    BinNode *&getLetfChild()
    {
        return lc;
    }
    BinNode *&getRightChild()
    {
        return rc;
    }
}

//binary tree
template <class E>
class Tree
{
  private:
    BinNode *root;
  public:
    Tree(BinNode *rt) { root = rt; }
    void traversal() {
        preorder(root);
        //choose whatever method you want to complete this(like postorder);
    }
    //three kind of methods to traveral the tree
    void preorder(BinNode *subRoot)
    {
        if (subRoot == NULL)
            return;
        Visit(subRoot); //here in the Visit function, you can do something to operate the node
        preorder(subRoot->lc);
        preorder(subRoot->rc);
    }
    inorder(BinNode *subRoot)
    {
        if (subRoot == NULL)
            return;
        inorder(subRoot->lc);
        Visit(subRoot);
        inorder(subRoot->rc);
    }
    postorder(BinNode *subRoot)
    {
        if (subRoot == NULL)
            return;
        postorder(subRoot->lc);
        postorder(subRoot->rc);
        Visit(subRoot);
    }
}