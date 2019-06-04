#include "MinHeap.h"
#include "MaxHeap.h"
#include "AvlTree.h"
#include "Graph.h"
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <fstream>
#include <sstream>

using namespace std;

MinHeap Build_min(string filename);
MaxHeap Build_max(string filename);
AvlTree Build_avltree(string filename);
Graph build_Graph(string filename);

int main()
{
	MinHeap Min_h;
	MaxHeap Max_h;
	AvlTree Avl_tree;
	Graph Graph_Structure;


	ofstream writeToFile;
	ifstream readFromFile;
	int value1, value2;
	string txtToWrite = "";
	string txtFromFile = "";
	string line, command, type, filename;

	readFromFile.open("C:\\Users\\Alex\\AppData\\Roaming\\SPB_Data\\cpp_data_structures\\Commands.txt", ios_base::in);

	if (readFromFile.is_open()) 	// file is open
	{

		while (getline(readFromFile, line))	// οσο διαβαζει σειρες να συνεχιζει
		{
			istringstream iss(line);
			iss >> command >> type;		// η εντολη πχ BUILD, GETSIZE, και μετά ο τύπος πχ MINHEAP MAXHEAP κλπ.
			cout << command << " " << type <<endl;

			if (command == "BUILD")
			{
				iss >> filename;

				if (type == "MINHEAP")
				{
					Min_h = Build_min(filename);
				}
				else if (type == "MAXHEAP")
				{
					Max_h = Build_max(filename);
				}
				else if (type == "AVLTREE")
				{
					Avl_tree = Build_avltree(filename);
				}
				else if (type == "GRAPH")
				{
                    Graph_Structure = build_Graph(filename);
				}
				else // HASHTABLE
				{

				}
			}
			else if (command == "GETSIZE")
			{
				if (type == "MINHEAP")
				{
					cout << Min_h.get_size();
				}
				else if (type == "MAXHEAP")
				{
					cout << Max_h.get_size();
				}
				else if (type == "AVLTREE")
				{
					cout << Avl_tree.get_size();
				}
				else if (type == "GRAPH")
				{
                    cout <<"Nodes Count: " << Graph_Structure.getVertexCount() << " Edges Count: " << Graph_Structure.getEdgeCount() << endl;
				}
				else // HASHTABLE
				{

				}

			}

			else if (command == "FINDMIN")
			{
				cout << Min_h.getMin();
			}

			else if (command == "FINDMAX")
			{
				cout << Max_h.getMax();
			}

			else if (command == "SEARCH")
			{

			}

			else if (command == "COMPUTESHORTESTPATH")
			{
                iss >> value1 >> value2 ;
                int cost = Graph_Structure.shortestPathBFS(value1, value2);
                cout << cost << endl;
            }
			else if (command == "FINDCONNECTEDCOMPOMENTS")
			{

			}

			else if (command == "INSERT")
			{
			    iss >> value1 >> value2 ;
                Graph_Structure.insertEdge(value1, value2);
			}

			else if (command == "DELETEMIN")
			{

			}

			else if (command == "DELETEMAX")
			{

			}

			else if (command == "DELETE")
			{

			}

			else if (command == "DELETE") // AVLTREE OR GRAPH
			{
				if (type == "AVLTREE")
				{

				}
				else if (type == "GRAPH")
				{
				    iss >> value1 >> value2 ;
                    Graph_Structure.deleteEdge(value1,value2);
				}
			}
		}
	}

}


//----------------FUNCTIONS-------------


/* -------- MINHEAP ----------
 Συναρτηση που ανοιγει το αρχεια minheap.txt μεσω της μεταβλητης string filename
 και διαβαζει τις τιμες που προκειται να εχει ο σωρος ελαχιστων
*/
MinHeap Build_min(string filename)
{
	ifstream readValues;
	string string_values;
	int value;
	readValues.open(filename, ios_base::in);
	MinHeap min_h;
	if (readValues.is_open())
	{

		while (getline(readValues, string_values))
		{
			value = stoi(string_values);
			min_h.insertKey(value);
		}
	}
	return min_h;
}


/* ------- MAXHEAP ----------
 Συναρτηση που ανοιγει το αρχεια minheap.txt μεσω της μεταβλητης string filename
 και διαβαζει τις τιμες που προκειται να εχει ο σωρος μεγιστων
*/
MaxHeap Build_max(string filename)
{
	ifstream readValues;
	string string_values;
	int value;
	readValues.open(filename, ios_base::in);
	MaxHeap max_h;
	if (readValues.is_open())
	{
		while (getline(readValues, string_values))
		{
			value = stoi(string_values);
			max_h.insertKey(value);
		}
	}
	return max_h;
}

//---------AVLTREE------------//
AvlTree Build_avltree(string filename)
{
	AvlTree tree;
	ifstream readValues;
	string string_values;
	int value;
	readValues.open(filename, ios_base::in);
	if (readValues.is_open())
	{
		while (getline(readValues, string_values))
		{
			value = stoi(string_values);
			tree.new_node(value);
		}
	}
	return tree;
}

/*
    Συναρτηση για την δημιουργια του γραφου
*/
Graph build_Graph(string filename)
{
    Graph tempGraph;
    ifstream readFromFile;
    string leftAndRightNodes;
    int leftValue, rightValue;
    readFromFile.open(filename, ios_base::in);
    if(readFromFile.is_open())
        while(getline(readFromFile,leftAndRightNodes))
        {
			istringstream iss(leftAndRightNodes);
			iss >> leftValue >> rightValue;\
			tempGraph.insertNode(leftValue, rightValue);
        }
    return tempGraph;
}



