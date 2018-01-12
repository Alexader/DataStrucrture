#include<iostream>
#include <queue>
#include<vector>
using namespace std;
const int EMPTY = -1;
const int UNVISITED = 0;
const int VISITED = 1;
class Graph
{
protected:
	int** adjacencyList;// represent edge value
	int * vertex;// represent vertex value
	int* mark;
	int n;// node number
public:
	// return the first vertex node is connected.
	virtual int first(const int node) = 0;
	// return the first vertex after w
	virtual int next(const int node, const int w) = 0;
	virtual int size() = 0;
	virtual void setMark(int node, int mark) = 0;
	virtual int getMark(int node) = 0;
};
class ArrayGraph : public Graph
{
public:
	ArrayGraph(vector<vector<int>> matrix, int* value, const int number) {
		n = number;
		mark = new int[n];
		vertex = new int[n];
		for (int i = 0; i < n; i++) {
			mark[i] = UNVISITED;
			vertex[i] = value[i];
		}
		// number in the matrix is the weight of each edge
		adjacencyList = new int*[n];
		for (int i = 0; i<n; i++) {
			adjacencyList[i] = new int[n];
			for (int j = 0; j<n; j++)
				// copy two dimensional array into graph
				adjacencyList[i][j] = matrix[i][j];
		}
	}
	~ArrayGraph();

	int first(const int node) {
		int i;
		for (i = 0; i<n; i++)
			if (adjacencyList[node][i] != 0) return i;
		return EMPTY;
	}

	int next(const int node, const int after_node) {
		int i;
		//the next vertex of `after_node` in the vertex `node` exclude `after_node`
		for (i = after_node+1; i<n; i++)
			if (adjacencyList[node][i] != 0) return i;
		return EMPTY;
	}

	void setClear() {
		for(int i=0;i<n;i++)
			mark[i] = UNVISITED;
	}
	void setMark(int node, int mk) {
		mark[node] = mk;
	}

	int getMark(int node) {
		return mark[node];
	}

	int operator[](int nodeNum) {
		return adjacencyList[nodeNum][0];
	}

	int size() { return n; }
	int getValue(int node) { return vertex[node]; }
};

void visit(ArrayGraph* graph, int node) {
	cout << "this is node " << node << " value:" << graph->getValue(node) << endl;
}

void DFS(ArrayGraph* graph, int startNode) {
	// get start with the startNode, choose the first node and do the same
	// to the first node
	visit(graph, startNode);
	graph->setMark(startNode, VISITED);
	int w;
	for (w = startNode; w != EMPTY; w = graph->next(startNode, w))
		if (graph->getMark(w) == UNVISITED)
			DFS(graph, w);
}

void BFS(ArrayGraph* graph, queue<int>* queue, int startNode) {
	// BFS don't use recurse. you just put every neighbor into queue
	visit(graph, startNode);
	graph->setMark(startNode, VISITED);
	queue->push(startNode);
	int temp;

	while(queue->size()!=0) {
		temp = queue->front();
	    queue->pop();

	    // get every neighbor node of startNode
	    for(int w=graph->first(temp);w!=EMPTY;w=graph->next(temp, w)){
	    	if (graph->getMark(w)==UNVISITED)
	    	{
	    		visit(graph, w);
	    		graph->setMark(w, VISITED);
	    		queue->push(w);
	    	}
	    }
	}
}

vector<vector<int>> buildMatrix(int* array, int iRow, int iCol) {
	auto retVec = vector<vector<int>>(iRow, vector<int>(iCol));
	for (int i = 0; i < iRow; i++) {
		for (int j = 0; j < iCol; j++)
			retVec[i][j] = array[i*iCol + j];
	}
	return retVec;
}
int main()
{
	int array[] = { 0, 3, 6, 3, 0, 4, 6, 4, 0 };
	auto matrix = buildMatrix(array, 3, 3);
	auto q = new queue<int>();
	int value[3] = { 3, 5, 9 };
	ArrayGraph* graph = new ArrayGraph(matrix, value, 3);
	int temp = graph->size();
	cout << temp << endl;
	cout << graph->first(2) << endl;
	cout<<"this is DFS result:"<<endl;
	DFS(graph, 0);
	cout<<"This is BFS result:"<<endl;
	graph->setClear();
	BFS(graph, q, 0);
	cout<<"it is over now"<<endl;
	return 0;
}