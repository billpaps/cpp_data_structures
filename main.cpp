#include "MinHeap.h"
#include "MaxHeap.h"
#include "AvlTree.h"
#include "Graph.h"
#include "HashTable.h"
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

MinHeap Build_min(string filename);
MaxHeap Build_max(string filename);
AvlTree Build_avltree(string filename);
Graph build_Graph(string filename);
HashTable build_Hash(string filename);

int main()
{
	MinHeap Min_h;
	MaxHeap Max_h;
	AvlTree Avl_tree;
	Graph Graph_Structure;
    HashTable Hash_Structure;

	ofstream writeToFile;
	ifstream readFromFile;
	int value1, value2;
	string txtToWrite = "";
	string txtFromFile = "";
	string line, command, type, filename;
	clock_t time_req;
	double time_used;

	readFromFile.open("C:\\Users\\Alex\\AppData\\Roaming\\SPB_Data\\cpp_data_structures\\Commands.txt", ios_base::in);
    writeToFile.open("C:\\Users\\Alex\\AppData\\Roaming\\SPB_Data\\cpp_data_structures\\output.txt",ios::out);

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
				    time_req = clock();
					Min_h = Build_min(filename);
					time_used = (double)((clock()-time_req)/CLOCKS_PER_SEC);
					writeToFile << "MINHEAP BUILT SUCCESSFULLY - TIME USED: " << time_used << endl;
				}
				else if (type == "MAXHEAP")
				{
				    time_req = clock();
					Max_h = Build_max(filename);
					time_used = (double)((clock()-time_req)/CLOCKS_PER_SEC);
					writeToFile << "MAXHEAP BUILT SUCCESSFULLY - TIME USED: " << time_used << endl;
				}
				else if (type == "AVLTREE")
				{
				    time_req = clock();
					Avl_tree = Build_avltree(filename);
					time_used = (double)((clock()-time_req)/CLOCKS_PER_SEC);
					writeToFile << "AVLTREE BUILT SUCCESSFULLY - TIME USED: " << time_used << endl;
				}
				else if (type == "GRAPH")
				{
				    time_req = clock();
                    Graph_Structure = build_Graph(filename);
                    time_used = (double)((clock()-time_req)/CLOCKS_PER_SEC);
                    writeToFile << "GRAPH BUILT SUCCESSFULLY - TIME USED: " << time_used << endl;
				}
				else // HASHTABLE
				{
				    time_req = clock();
                    Hash_Structure = build_Hash(filename);
                    time_used = (double)((clock()-time_req)/CLOCKS_PER_SEC);
                    writeToFile << "HASHTABLE BUILT SUCCESSFULLY - TIME USED: " << time_used << endl;
				}
			}
			else if (command == "GETSIZE")
			{
				if (type == "MINHEAP")
				{
				    time_req = clock();
					value1 =  Min_h.get_size();
					time_used = (double)((clock()-time_req)/CLOCKS_PER_SEC);
					writeToFile << "MINHEAP SIZE: " << value1 << " - TIME USED: " << time_used << endl;
				}
				else if (type == "MAXHEAP")
				{
				    time_req = clock();
					value1 = Max_h.get_size();
					time_used = (double)((clock()-time_req)/CLOCKS_PER_SEC);
					writeToFile << "MAXHEAP SIZE: " << value1 << " - TIME USED: " << time_used << endl;
				}
				else if (type == "AVLTREE")
				{
				    time_req = clock();
					value1 = Avl_tree.get_size();
					time_used = (double)((clock()-time_req)/CLOCKS_PER_SEC);
					writeToFile << "AVLTREE SIZE: " << value1 << " - TIME USED: " << time_used << endl;
				}
				else if (type == "GRAPH")
				{
				    time_req = clock();
                    value1 = Graph_Structure.getVertexCount();
                    value2 = Graph_Structure.getEdgeCount();
                    time_used = (double)((clock()-time_req)/CLOCKS_PER_SEC);
                    writeToFile << "GRAPH VERTEX COUNT: " << value1 << " | GRAPH EDGE COUNT : "<< value2 << " - TIME USED" << time_used << endl;
				}
				else // HASHTABLE
				{
				    time_req = clock();
                    value1 = Hash_Structure.getHashEntriesCount();
                    time_used = (double)((clock()-time_req)/CLOCKS_PER_SEC);
                    writeToFile << "MINHEAP SIZE: " << value1 << " - TIME USED: " << time_used << endl;
				}

			}
			else if (command == "FINDMIN")
			{
			    time_req = clock();
				value1 = Min_h.getMin();
				time_used = (double)((clock()-time_req)/CLOCKS_PER_SEC);
				writeToFile << "MINHEAP FINDMIN COMMAND: " << value1 << " - TIME USED: " << time_used << endl;
			}

			else if (command == "FINDMAX")
			{
			    time_req = clock();
				value1 = Max_h.getMax();
				time_used = (double)((clock()-time_req)/CLOCKS_PER_SEC);
				writeToFile << "MAXHEAP FINDMAX COMMAND: " << value1 << " - TIME USED: " << time_used << endl;
			}

			else if (command == "SEARCH")
			{
                if(type=="AVLTREE"){

                }else{//HASHTABLE
                    time_req = clock();
                    iss >> value1;
                    type = Hash_Structure.searchHashTable(value1);
                    time_used = (double)((clock()-time_req)/CLOCKS_PER_SEC);
                    writeToFile << "HASHTABLE SEARCH COMMAND: " << type << " - TIME USED: " << time_used << endl;
                }
			}
			else if (command == "COMPUTESHORTESTPATH")
			{
			    time_req = clock();
                iss >> value1 >> value2 ;
                int cost = Graph_Structure.shortestPathBFS(value1, value2);
                time_used = (double)((clock()-time_req)/CLOCKS_PER_SEC);
                writeToFile << "GRAPH SHORTEST PATH BETWEEN "<< value1 << " and " << value2 << ": " << cost << " - TIME USED: " << time_used << endl;
            }
			else if (command == "FINDCONNECTEDCOMPONENTS")
			{
			    time_req = clock();
                int connectedComponents = Graph_Structure.findConnectedComponents();
                time_used = (double)((clock()-time_req)/CLOCKS_PER_SEC);
                writeToFile << "GRAPH CONNECTED COMPONENTS : " << connectedComponents << " - TIME USED: " << time_used << endl;
			}
			else if ( command == "COMPUTESPANNINGTREE")
            {

            }
			else if (command == "INSERT")
			{
			    if(type=="GRAPH"){
                    time_req = clock();
                    iss >> value1 >> value2 ;
                    Graph_Structure.insertEdge(value1, value2);
                    time_used = (double)((clock()-time_req)/CLOCKS_PER_SEC);
                    writeToFile << "GRAPH INSERT COMMAND - TIME USED: " << time_used << endl;
			    }else if(type=="MINHEAP"){

			    }else if(type=="MAXHEAP"){

			    }else if(type=="AVLTREE"){

			    }else{//HASHTABLE
			        time_req = clock();
			        iss >> value1;
                    Hash_Structure.addEntry(value1);
                    time_used = (double)((clock()-time_req)/CLOCKS_PER_SEC);
                    writeToFile << "GRAPH INSERT COMMAND - TIME USED: " << time_used << endl;
			    }
            }
			else if (command == "DELETEMIN")
			{

			}
			else if (command == "DELETEMAX")
			{

			}
			else if (command == "DELETE") // AVLTREE OR GRAPH
			{
				if (type == "AVLTREE")
				{

				}
				else if (type == "GRAPH")
				{
				    time_req = clock();
				    iss >> value1 >> value2 ;
                    Graph_Structure.deleteEdge(value1,value2);
                    time_used = (double)((clock()-time_req)/CLOCKS_PER_SEC);
                    writeToFile << "GRAPH DELETE COMMAND - TIME USED: " << time_used << endl;
				}
			}
		}
	}
	readFromFile.close();
	writeToFile.close();
    return 0;
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

HashTable build_Hash(string filename)
{
    ifstream readFromFile;
	string stringEntry;
	HashTable tempHash(101);
	readFromFile.open(filename, ios_base::in);
	if (readFromFile.is_open())
		while (getline(readFromFile, stringEntry))
			tempHash.addEntry(stoi(stringEntry));
    return tempHash;
}



