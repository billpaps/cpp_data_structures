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
    graph.clear();
}

int Graph::getEdgeCount() { return edgeCount; } // επιστρεφει τις ακμες

int Graph::getVertexCount() { return nodeCount; } // επιστρεφει τους κομβους

/*
    Στην παρακατω συνάρτηση εχοντας τις τιμες value1, value2 ελεγχω αν υπαρχουν ηδη μες στον γραφω με την βοηθεια των
    source1, source2. Αρα εχω τις εξεις περιπτωσεις
    1) Αν δεν υπαρχουν τοτε απλως δημιουργω δυο νεα στοιχεια Node και τα εισαγω στους vector
    2) Αν υπαρχει ο ενας ο κομβος αλλα οχι ο αλλος τοτε δημιουργω ενα στοιχειο Node και τοποθετω και στο destination των δυο κομβων την σχεση συνδεση τους
    3) Αν υπαρχουν και τα δυο τοτε απλως εισαγω στο destination και των δυο την σχέση σύνδεση τους
*/
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

/*
    Στην παρακατω συναρτηση δεχομαι δυο τιμες node1, node2. Ελεγχω αν υπαρχουν στο γραφημα
    Αν δεν υπαρχουν τοτε επιστρεφω -1 ενω αν ειναι ιδιος κομβος τοτε προφανως 0
    Σε καθε αλλη περιπτωση εκτελω τον αλγοριθμο BFS και καθε φορα που επεκτεινω το πλατος βαζω την τιμη
    -1 που λογικα δεν θα υπαρχει στην ουρα αναζητησης και αυξανανω το μονοπατι κατα 1. Με αυτον τον τροπο βρισκω
    την βελτιστη διαδρομη απο εναν κομβο σε αλλον σε ενα γραφημα χωρις βάροι.
*/
int Graph::shortestPathBFS(int node1,int node2){
    int cost=0;
    queue<int> agenda;
    vector<int> children;
    int source1=-1, source2=-1;
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
    if(source1==source2) // περιπτωση οπου θελουμε να παμε απο κομβο Α στον κομβο Α
        return 0;
    if(source1==-1 || source2==-1)
        return -1;//περιπτωση οπου δεν υπαρχουν ενας(η και οι δυο) απο τους κομβους
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


/*
    Συναρτηση insertEdge
    Εχοντας τα value1, value2 ελεγχω αν υπαρχουν στο γραφημα. Εφοσον δεν υπαρχει ειτε η 1 τιμη ειτε και οι 2
    χρησιμοποιω την συναρτηση insertNode για να εισαγω 1 η 2 κομβους. Στην περιπτωση που υπαρχουν ηδη και τα δυο
    απλως ελεγχω αν υπαρχει ηδη η συνδεση. Αν υπαρχει τοτε δεν κανω τιποτα αλλιως βαζω στο destination του καθε Node
    την τιμη του αλλου κομβου
*/
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
            graph[source2].destination.push_back(source1);
            edgeCount++;
        }
    }
}


/*
    Στην παρακατω συναρτηση εφοσον ελεγξω αν υπαρχουν τα value1, value2 στο γραφημα τοτε ελεγχω αν υπαρχει η ακμη.
    Προφανως αν δεν υπαρχει τοτε δεν κανω τιποτα. Αλλιως με την βοηθεια του erase βγαζω στο vector<int> destination
    τον καταλληλο κομβο
*/
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
    if(source1==-1 || source2==-1){
    }
    else{
        bool edgeExists=false;
        for(unsigned int i=0;i<graph[source1].destination.size();i++)
            if(source2==graph[source1].destination[i])
            {
                edgeExists=true;
                break;
            }
        if(edgeExists){
            int destination1=0, destination2=0;
            for(unsigned int i=0;i<graph[source1].destination.size();i++)
                if(value2==graph[source1].destination[i]+1)
                {
                    destination1=i;
                    break;
                }
            for(unsigned int i=0;i<graph[source2].destination.size();i++)
                if(value1==graph[source2].destination[i]+1)
                {
                    destination2=i;
                    break;
                }
            graph[source1].destination.erase(graph[source1].destination.begin()+destination1);
            graph[source2].destination.erase(graph[source2].destination.begin()+destination2);
            edgeCount--;
        }
    }
}


/*
    Στην παρακατω συναρτηση καταρχας θετω ολους τους κομβους ως notVisited. Επειτα με το DFS διαπαιρνω ολους τους κομβους
    Οταν πλεον εχω διαπερασει ολους τους κομβους, ελεγχω παλι ολο το γραφημα αν εχω επισκεφτει ολους τους κομβους. Αν οχι τοτε
    τοποθετω στην ουρα τον πρωτο κομβο που βρισκω οτι δεν εχω επισκεφθει και εκτελω παλι BFS. Ολο αυτο συνεχσιζει μεχρις
    οσοτου εχω επισκεφθει ολους τους κομβους. Τελος καθε φορα που βρισκω οτι δεν εχω επισκεφθει εναν κομβο εφοσον τελειωσει η
    μια επαναληψη του DFS αυξανα το πληθος των ανεξάρτητων κομβων κατα 1
*/
int Graph::findConnectedComponents()
{
    int connectedComponents=0;
    queue<int> agenda;
    vector<int> children;
    bool allNodesVisited=false;
    bool *explored = new bool[nodeCount];
    for (int i = 0 ; i<=nodeCount ; ++i)
        explored[i] = false;
    agenda.push(graph[0].source);
    while(!allNodesVisited)
    {
        while(!agenda.empty())
        {
            int currentVertex = agenda.front();
            agenda.pop();
            explored[currentVertex]=true;
            children = graph[currentVertex].destination;
            for(unsigned int i=0; i<children.size() ; i++)
                if(!explored[children[i]]){
                    agenda.push(children[i]);
                    explored[children[i]]=true;
                }
        }
        allNodesVisited=true;
        connectedComponents++;
        for(int i=0;i<nodeCount;i++)
            if(!explored[i]){
                allNodesVisited=false;
                agenda.push(graph[i].source);
                break;
            }
    }
    return connectedComponents;
}


/*
    Ελεγχω ποσο ανεξαρτητα συνολα υπαρχουν, αν ειναι 0 η 1 επιστρεφω 0 η node-1 αντιστοιχα
    Σε αλλη περιπτωση απλως διαπερνω το γραφο με μια παραλλαγη του BFS και υπολογιζω το μονοπατι
    σε καθε υποσυνολο του γραφου και τα συγκρινω μεταξύ τους
*/
int Graph::spanningTree(){
    int allComponents = findConnectedComponents();
    int minPath=0;
    if(allComponents==0)
        return 0;
    if(allComponents==1)
        return nodeCount-1;

    queue<int> agenda;
    vector<int> children;
    bool *explored = new bool[nodeCount];
    for (int i = 0 ; i<=nodeCount ; ++i)
        explored[i] = false;
    agenda.push(graph[0].source);
    while(!agenda.empty())
    {
        int currentVertex = agenda.front();
        agenda.pop();
        minPath++;
        explored[currentVertex]=true;
        children = graph[currentVertex].destination;
        for(unsigned int i=0; i<children.size() ; i++)
            if(!explored[children[i]]){
                agenda.push(children[i]);
                explored[children[i]]=true;
            }
    }
    while(allComponents!=1){
        for(int i=0;i<nodeCount;i++)
            if(!explored[i]){
                agenda.push(graph[i].source);
                break;
            }
        int tempMinPath=-1;
        while(!agenda.empty())
        {
            int currentVertex = agenda.front();
            agenda.pop();
            tempMinPath++;
            explored[currentVertex]=true;
            children = graph[currentVertex].destination;
            for(unsigned int i=0; i<children.size() ; i++)
                if(!explored[children[i]]){
                    agenda.push(children[i]);
                    explored[children[i]]=true;
                }
        }
        if(tempMinPath<minPath)
            minPath = tempMinPath;
        allComponents--;

    }
    return minPath;
}
