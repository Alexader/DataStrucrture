#include <iostream>
using namespace std;
const int EMPTY = -1;
class Graph
{
private:
	int** adjacencyList;
	int* mark;
	int n;// node number
public:
	Graph();
	// return the first vertex node is connected. 
	virtual int first(int node) = 0;
	// return the first vertex after w
	virtual int next(int node, int w) = 0;
	virtual int getValue(int node) = 0;
	virtual int size() =  0;
	virtual void setMark(int node) = 0;
	virtual int getMark(int node) = 0;
};
void visit(Graph* graph, int node) {
	cout<<"this is node "<<node<<" value:"<<graph[node]<<endl;
}
void DFS(Graph* graph, int startNode) {
	// get start with the startNode, choose the first node and do the same
	// to the first node
	visit(graph, startNode);
	graph->setMark(startNode, VISITED);
	int w;
	for(w=startNode;w!=EMPTY;w=graph->next(startNode, w))
		if(graph->getMark(w)==UNVISITED)
			DFS(graph, w);
}

void BFS(Graph* graph, Queue<int>* queue, int startNode) {
	// BFS don't use recurse. you just put every neighbor into queue
	visit(graph, startNode);
	graph.setMark(startNode, VISITED);
	queue->enqueue(startNode);

	while(queue->length()!=0) {
	    queue->dequeue(temp);

	    // get every neighbor node of startNode
	    for(int w=graph->first(temp);w!=EMPTY;w=graph->next(temp, w)){
	    	if (graph->getMark(w)==UNVISITED)
	    	{
	    		visit(graph, w);
	    		graph->setMark(startNode, VISITED);
	    		queue->enqueue(graph, w);
	    	}
	    }
	}
}
int int main(int argc, char const *argv[])
{
	Graph* graph = new Graph();

	cout<<"following is DFS:"<<endl;
	DFS(graph, 1);
	cout<<"following is BFS:"<<endl;
	BFS(graph, 1);
	return 0;
}