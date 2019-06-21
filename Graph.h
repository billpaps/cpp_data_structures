#include <vector>
#include <string>

using namespace std;

/*
    Κλαση Γραφος : Χρησιμοποιω ενα struct Node οπου αναπαριστα εναν κομβο στον γραφο. Επομενης η κλαση γραφος ειναι
    ενα συνολο vector<Node>. Το struct Node περιεχει τις μεταβλητες nodeValue : Τιμή , source : ονομα του κομβου ,
    vector<int> destination : εχει τα sources με τα οποια εχει συνδεση ο κομβος
*/

class Graph
{
protected:
    int nodeCount; // Πληθος κόμβων
    int edgeCount; // Πληθος Ακμών
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
