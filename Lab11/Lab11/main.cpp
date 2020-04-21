#include "Graph.h"
#include <iostream>

using namespace std;

int main() {

	Graph graph(10);

	bool shouldEnd = false;
	string line = "----------------------------";

	cout << "Graph has been created with a max vertex limit of 10, therefore pleas enter only index values between 0 and 9" << endl;
	cout << line << endl;

	while (!shouldEnd) {
		int option;
		cout << "Press 1 to add an edge: " << endl;
		cout << "Press 2 to remove an edge: " << endl;
		cout << "Press 3 to see whether edge is present: " << endl;
		cout << "Press 4 to find the out edges of a vertex: " << endl;
		cout << "Press 5 to find the in edges of a vertex: " << endl;
		cout << "Press 6 to perform depth First Search" << endl;
		cout << "Press 7 to perform breadth First Search" << endl;
		cout << "Press anything other number to quit: " << endl;
		cin >> option;
	
		if (option == 1) {
			int i, j;
			cout << "Enter i: " << endl;
			cin >> i;
			cout << "Enter j: " << endl;
			cin >> j;
			graph.addEdge(i, j);
			cout << line << endl;
		}
		else if (option == 2) {
			int i, j;
			cout << "Enter i: " << endl;
			cin >> i;
			cout << "Enter j: " << endl;
			cin >> j;
			graph.removeEdge(i, j);
			cout << line << endl;
		}
		else if (option == 3) {
			int i, j;
			cout << "Enter i: " << endl;
			cin >> i;
			cout << "Enter j: " << endl;
			cin >> j;
			cout << (graph.hasEdge(i, j)?"Edge is present":"Edge is not present") <<endl;
			cout << line << endl;
		}
		else if (option == 4) {
			int i;
			cout << "Enter i: " << endl;
			cin >> i;
			ODLinkedList<int> outEdges = graph.outEdges(i);
			cout << i << " |-> ";
			outEdges.display();
			cout << line << endl;
		}
		else if (option == 5) {
			int i;
			cout << "Enter i: " << endl;
			cin >> i;

			Queue<int> inEdges = graph.inEdges(i);
			int size = inEdges.length();

			cout << i << " <-| ";
			for (int c = 0; c < size; c++) {
				if (c != size) {
				cout << *(inEdges.pop()) << " || ";
				}
				else {
					cout << *(inEdges.pop());
				}
			}
			cout << endl;
			cout << line << endl;
		}

		else if (option == 6) {
			int start;
			cout << "Enter starting node: ";
			cin >> start;
			graph.perFormDFS(start);
			cout << endl;
			cout << line << endl;
		}
		else if (option == 7) {
			int start;
			cout << "Enter starting node: ";
			cin >> start;
			graph.perFormBFS(start);
			cout << endl;
			cout << line << endl;
		}

		else {
			cout << "exiting program...." << endl;
			shouldEnd = true;
		}
	
	}

}