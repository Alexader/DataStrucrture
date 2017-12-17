template<typename E>
class GTNode
{
private:
	E ele;
	GTNode* par;
	GTNode* leftMost;
	GTNode* bro;
public:
	GTNode(E& element, GTNode* parent, GTNode* leftMost=NULL, GTNode* Bro=NULL) {
		ele = element;
		par = parent;
		leftMost = leftMost;
		bro = Bro;
	}
	public void setVlaue(E value) { ele = value; }
	public GTNode* LeftMost() { return leftMost; }
	public GTNode* getBro() { return bro; }
	public void insertLeftChild(GTNode* lfmost) { leftMost = lfmost; }
	public void insertBro(GTNode* Bro) { bro= Bro; }
};

class GTree
{
private:
	GTNode* root;
public:
	GTree() { root = NULL; }
	GTree(GTNode* root) { root = root; }
	public void clear() {
		
	}
	public void print();
	~GTree();
	
};