//
// Created by 26236 on 2023/6/20.
// usage of graph theory and DFS
//
#include <bits/stdc++.h>
using namespace std;

// Class for an undirected graph
class Graph {
    int V;
    // Pointer to an array
    // containing adjacency lists
    list<int>* adj;

public:
    // Constructor
    Graph(int V);
    // To add an edge to graph
    void addEdge(int v, int w);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V]; // V lists of adjacent vertices
}

void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
    // Add v to w’s list.
    adj[w].push_back(v);
}

int is_all_visited(vector<int> visited){
    // input the vector of visit
    int all_visited = 1;
    int n = visited.size(); // number of nodes in total
    for (int i = 0; i < n; i++){
        all_visited *= visited[i];
    }
    return all_visited;
    // return 1 if all visited, 0 if not
}


int main(){
    while (1){
        int n,m; // number of intersections & number of roads
        // waiting for next m lines of input of streets
        int retNM = scanf("%d %d", &n, &m);
        printf("%d points, %d streets\n",n,m);
        if (retNM != 2){
            break;
        }
        vector<int> visited; //once visited, mark 1
        for (int i = 0; i < n; i++){
            visited.push_back(0);
        }
        vector<int> labels; // +1 or -1
        for (int i = 0; i < n; i++){
            labels.push_back(0);
        }

        Graph g(n);
        int node1, node2;

        for (int j = 0; j < m; j++){
            scanf("%d %d", &node1, &node2);
            // add this edge into the graph
            // attention the nodes are 1-indexed
            node1 = node1-1;
            node2 = node2-1;
            g.addEdge(node1, node2);
        }//finished initializing the graph

        queue<int> q;
        queue<int> empty;

        // starts BFS and marking
        int all_visited = 0; // if all visited, should be one, if not all visited, should be 0
        while (!all_visited){
            // there are still nodes unvisited : unconnected graphs
            swap(q, empty); // empty the queue
            int start_vertex;
            vector<int>::iterator it_visited;
            for (it_visited = visited.begin(); it_visited < visited.end(); it_visited++){
                if (*it_visited == 0){
                    start_vertex = *it_visited;
                    break;
                }
            }

        }



    }
}