#include <vector>
#include <string>

using namespace std;

class Graph
{
protected:
    int nodeCount;
    int edgeCount;
    struct Node {
        int nodeValue;
        int source;
        vector<int> destination;
    };
    vector<Node> graph;

public:
    Graph();
    ~Graph();
    int getEdgeCount();
    int getVertexCount();
    void insertNode(int value1, int value2);
    int shortestPathBFS(int node1, int node2);
    void insertEdge(int value1, int value2);
    void deleteEdge(int value1, int value2);
    int findConnectedComponents();
    void spanningTree();

private:

};
