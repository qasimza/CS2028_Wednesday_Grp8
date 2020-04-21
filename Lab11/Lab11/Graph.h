#pragma once
#include "ODLinkedList.h"
#include "Queue.h"
#include <iostream>

using namespace std;

class Graph {
	int maxNumberOfVerts;
	ODLinkedList<int>* data;

public:
	Graph(int size) {
		maxNumberOfVerts = size;
		data = new ODLinkedList<int>[size];

		//Create empty lists at all spots
		for (int i = 0; i < maxNumberOfVerts; i++) {
			data[i] = ODLinkedList<int>();
		}
	}

	void addEdge(int i, int j) {
		if (i >= 0 && i < maxNumberOfVerts && j >= 0 && j < maxNumberOfVerts) {
			data[i].addItem(new int(j));
		}
		else {
			cout << "Index out of boudns" << endl;
		}
	}

	void removeEdge(int i, int j) {
		if (i >= 0 && i < maxNumberOfVerts && j >= 0 && j < maxNumberOfVerts) {
			data[i].getItem(new int(j));
		}
		else {
			cout << "Index out of boudns" << endl;
		}
	}

	bool hasEdge(int i, int j) {
		if (i >= 0 && i < maxNumberOfVerts && j >= 0 && j < maxNumberOfVerts) {
			return data[i].isInList(new int(j));
		}
		else {
			cout << "Index out of boudns" << endl;
		}
	}

	ODLinkedList<int> outEdges(int i) {
		if (i >= 0 && i < maxNumberOfVerts) {
			return data[i];
		}
		else {
			cout << "Index out of boudns" << endl;
		}
	}

	Queue<int> inEdges(int i) {
		if (i >= 0 && i < maxNumberOfVerts) {

			Queue<int> res(maxNumberOfVerts);

			for (int j = 0; j < maxNumberOfVerts;j++) {
				if (data[j].isInList(new int(i))) {
					res.push(new int(j));
				}
			}

			return res;
		}
		else {
			cout << "Index out of boudns" << endl;
		}
	}

	//Inspired by geeksforgeeks  https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
	void perFormDFS(int startNode) {

		if (startNode >= 0 && startNode < maxNumberOfVerts) {
			bool* visited = new bool[maxNumberOfVerts];
			for (int i = 0; i < maxNumberOfVerts; i++) {
				visited[i] = false;
			}
			recursiveDFS(startNode, visited);
		}
		else {
			cout << "Index out of boudns" << endl;
		}
	}

	//Inspired by geeksforgeeks  https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
	void recursiveDFS(int curr, bool* visisted) {
		visisted[curr] = true;
		cout << curr << " -> ";

		ODLinkedList<int> adjacent = outEdges(curr);
		int size = adjacent.size();
		adjacent.reset();
		for (int i = 0; i < size; i++) {
			int temp = *adjacent.seeNext();
			if (!visisted[temp]) {
				recursiveDFS(temp, visisted);
			}
		}

	}

	//Inspired by geeksforgeeks https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
	void perFormBFS(int startNode) {

		if (startNode >= 0 && startNode < maxNumberOfVerts) {

			bool* visited = new bool[maxNumberOfVerts];
			for (int i = 0; i < maxNumberOfVerts; i++) {
				visited[i] = false;
			}

			Queue<int> currNodes = Queue<int>(maxNumberOfVerts);
			currNodes.push(new int(startNode));
			visited[startNode] = true;

			while (currNodes.length() > 0) {

				int curr = *currNodes.pop();
				cout << curr << " ";
				ODLinkedList<int> adj = outEdges(curr);
				int adjSize = adj.size();

				for (int i = 0; i < adjSize; i++) {
					curr = *adj.seeNext();
					if (!visited[curr]) {
						visited[curr] = true;
						currNodes.push(new int(curr));
						//cout << "here: "<<curr << endl;
					}
				}


			}

			cout << endl;
			
		}
		else {
			cout << "Index out of boudns" << endl;
		}
	}

	~Graph() {
		delete[] data;
	}

};
