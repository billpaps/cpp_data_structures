#include "Graph.h"
#include <queue>
#include <string>
#include <iostream>

using namespace std;

Graph::Graph()
{
    edgeCount=0;
    nodeCount=0;
}

Graph::~Graph()
{

}

int Graph::getEdgeCount() { return edgeCount; }

int Graph::getVertexCount() { return nodeCount; }

void Graph::insertNode(int value1, int value2){
    //Ελεγχος για το αν υπαρχουν ηδη τα nodes η οχι
    int source1=-1, source2=-1;
    for(int i=0; i<nodeCount ;i++)
        if(value1==graph[i].nodeValue){
            source1=i;
            break;
        }
    for(int i=0; i<nodeCount ;i++)
        if(value2==graph[i].nodeValue){
            source2=i;
            break;
        }
    //Προσθηκη των κορυφων στο γραφημα και δημιουργια των αντιστοιχων σχεσεων
    if(source1==-1 && source2==-1){
        Node tempNode1, tempNode2;
        source1=nodeCount;
        source2=nodeCount+1;
        tempNode1.destination.push_back(source2);
        tempNode1.source=source1;
        tempNode1.nodeValue=value1;
        graph.push_back(tempNode1);

        tempNode2.destination.push_back(source1);
        tempNode2.source=source2;
        tempNode2.nodeValue=value2;
        graph.push_back(tempNode2);

        nodeCount += 2;
    }else if( source1==-1){
        Node tempNode1;
        source1=nodeCount;
        tempNode1.destination.push_back(source2);
        tempNode1.nodeValue=value1;
        tempNode1.source=source1;
        graph.push_back(tempNode1);
        graph.at(source2).destination.push_back(source1);
        nodeCount++;
    }else if(source2==-1){
        Node tempNode2;
        source2=nodeCount;
        tempNode2.destination.push_back(source1);
        tempNode2.nodeValue=value2;
        tempNode2.source=source2;
        graph.push_back(tempNode2);
        graph.at(source1).destination.push_back(source2);
        nodeCount++;
    }else{
        graph.at(source1).destination.push_back(source2);
        graph.at(source2).destination.push_back(source1);
    }
    edgeCount += 1;
}

int Graph::shortestPathBFS(int node1,int node2){
    int cost=0;
    queue<int> agenda;
    vector<int> children;
    int source1, source2;
    bool *explored = new bool[nodeCount];
    for (int i = 0 ; i<=nodeCount ; ++i)
        explored[i] = false;
    for(unsigned int i=0;i<graph.size();i++)
        if(node1==graph[i].nodeValue){
            source1=i;
            break;
        }
    for(unsigned int i=0;i<graph.size();i++)
        if(node2==graph[i].nodeValue){
            source2=i;
            break;
        }
    agenda.push(source1);
    if(source1==source2)
        return 0;
    cost++;
    while(!agenda.empty())
    {
        if(agenda.front()==-1)
        {
            cost++;
            agenda.pop();
        }
        int currentVertex = agenda.front();
        if(currentVertex==source2)
            return cost;
        agenda.pop();
        explored[currentVertex]=true;
        children = graph[currentVertex].destination;
        for(unsigned int i=0; i<children.size() ; i++)
            if(!explored[children[i]]){
                agenda.push(children[i]);
                explored[children[i]]=true;
            }
        agenda.push(-1);
    }
    delete []explored;
    return cost;
}

void Graph::insertEdge(int value1, int value2){
    int source1=-1, source2=-1;
    for(unsigned int i=0;i<graph.size();i++)
        if(value1==graph[i].nodeValue){
            source1=i;
            break;
        }
    for(unsigned int i=0;i<graph.size();i++)
        if(value2==graph[i].nodeValue){
            source2=i;
            break;
        }
    if(source1==-1 || source2==-1)//περιπτωση οπου δεν υπαρχει η τιμη value1 η value2 στον γραφο
        insertNode(value1,value2);
    else{
        bool alreadyExists=false;
        for(unsigned int i=0;i<graph[source1].destination.size();i++)
            if(source2==graph[source1].destination[i])
                alreadyExists=true;
        if(!alreadyExists){
            graph[source1].destination.push_back(source2);
            graph[source1].destination.push_back(source2);
        }
    }
}

void Graph::deleteEdge(int value1,int value2){
    int source1=-1, source2=-1;
    for(unsigned int i=0;i<graph.size();i++)
        if(value1==graph[i].nodeValue){
            source1=i;
            break;
        }
    for(unsigned int i=0;i<graph.size();i++)
        if(value2==graph[i].nodeValue){
            source2=i;
            break;
        }
    if(source1==-1 || source2==-1){ //do nothing
    }
    else{
        int destination1=0, destination2=0;
        for(unsigned int i=0;i<graph[source1].destination.size();i++)
            if(value2==graph[source1].destination[i])
            {
                destination1=i;
                break;
            }
        for(unsigned int i=0;i<graph[source2].destination.size();i++)
            if(value1==graph[source2].destination[i])
            {
                destination2=i;
                break;
            }
        graph[source1].destination.erase(graph[source1].destination.begin()+destination1);
        graph[source2].destination.erase(graph[source2].destination.begin()+destination2);
    }
}
