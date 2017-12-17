//element in tree node empty value
const EMPTY_KEY;
template<typename E>
class TTNode
{
private:
	TTNode* parent;
	TTNode* left;
	TTNode* middle;
	TTNode* right;
	E leftVal;
	E rightVal;
public:
	TTNode(E lfVal, E rtVal, TTNode* par=NULL, TTNode* lf=NULL, TTNode* md=NULL, TTNode* rt=NULL) {
		parent=par; left=lf; right=rt; middle=md; 
		leftVal = lfVal;
		rightVal = rtVal;
	}
	void setLeftVal(E lfVal) { leftVal = lfVal; }
	void setRightVal(E rtVal) { rightVal = rtVal; }
	E& getLeftVal() { return leftVal; }
	E& getRightVal() { return rightVal; }
	void setLeft(TTNode* left) { left = left; }
	void setRight(TTNode* right) { right = right; }
	void setMiddle(TTNode* middle) { middle = middle; }
	TTNode* getLeft() { return left; }
	TTNode* getRight() { return right; }
	TTNode* getMiddle() { return middle; }
	bool isLeaf() { return left == EMPTY_KEY; }
	~TTNode();
	
};

template<typename E>
class TTTree
{
private:
	TTNode<E>* root;
	TTNode<E>* insertHelp(E ele, const TTNode<E>* root) {
		if(root==NULL) { root = new TTNode(ele, NULL); return root;}
		//less than root left, go to left
		if(ele<root->getLeftVal()) { insertHelp(ele, root->getLeft()); }
		if(ele>root) {}
		//TODO finish insert
	}
	
	//find where the node whose value has ele
	TTNode* findHelp(E ele, const TTNode<E>* root) {
		if(root==NULL) { return NULL; }
		//find in the root
		if(ele==root->getLeftVal()) { return root; }
		if(ele==root->getRightVal()) { return root; }
		//search in the left child tree
		if(ele<root->getLeftVal()) { return findHelp(ele, root->getLeft()); }
		else if(root->getRightVal()==EMPTY_KEY) { return NULL;}
		//search middle tree
		else if(ele<root->getRightVal()) { return findHelp(ele, root->getMiddle()); }
		//search right tree
		else if(ele>root->getRightVal()) { return findHelp(ele, root->getRight()); }
		else return NULL;
	}
public:
	TTTree(TTNode* root=NULL) { root = root; }
	TTNode* insert(E& ele) {
		return insertHelp(ele, root);
	}
	TTNode* find(const E ele) {
		return findHelp(ele, root);
	}
	~TTTree();
	
};