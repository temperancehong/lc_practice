//
// Created by 26236 on 2023/6/20.
// usage of graph theory and DFS
//
#include <bits/stdc++.h>
using namespace std;

// Class for an undirected graph
class Graph {
public:
    int V;
    // Pointer to an array
    // containing adjacency vectors
    vector<int>* adj;

public:
    // Constructor
    Graph(int V);
    // To add an edge to graph
    void addEdge(int v, int w);
};

Graph::Graph(int V) {
    this->V = V;
    this->adj = new vector<int>[V]; // V vectors of adjacent vertices
}

void Graph::addEdge(int v, int w)
{
    // Add w to v’s vector.
    this->adj[v].push_back(w);
    // Add v to w’s vector.
    this->adj[w].push_back(v);
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
        printf("All streets added\n");
        queue<int> q;
        queue<int> empty;

        // starts BFS and marking
        int all_visited = 0; // if all visited, should be one, if not all visited, should be 0
        while (!all_visited){
            // there are still nodes unvisited : unconnected graphs
            swap(q, empty); // empty the queue
            int start_vertex;
            vector<int>::iterator it_visited;

            // getting the first unvisited node
            for (it_visited = visited.begin(); it_visited < visited.end(); it_visited++){
                if (*it_visited == 0){
                    start_vertex = *it_visited;
                    break;
                }
            }
            q.push(start_vertex);
            visited[start_vertex] = 1;
            while (!q.empty()){
                int curr_vertex = q.front(); // get first
                q.pop(); // delete first
                if (labels[curr_vertex] == 0){// unmarked
                    labels[curr_vertex] = 1; // meaning it's possible to put a station here
                    for (int k = 0; k < g.adj[curr_vertex].size(); k++){// take all its neighbors and mark them
                        if (visited[g.adj[curr_vertex][k]] == 0){ // mark it as visited
                            visited[g.adj[curr_vertex][k]] = 1;
                            q.push(g.adj[curr_vertex][k]); // push this node into queue
                        }
                        if (labels[g.adj[curr_vertex][k]] == 0){ //if it's not labeled
                            // this neighbor is not marked
                            labels[g.adj[curr_vertex][k]] = -1; // mark it inaccessible
                        }
                    }
                }
                else if (labels[curr_vertex] == -1){
                    for (int k = 0; k < g.adj[curr_vertex].size(); k++){
                        if (visited[g.adj[curr_vertex][k]] == 0){
                            visited[g.adj[curr_vertex][k]] = 1;
                            q.push(g.adj[curr_vertex][k]);
                        }
                        if (labels[g.adj[curr_vertex][k]] == 0){
                            labels[g.adj[curr_vertex][k]] = -1; // mark accessible
                        }
                    }
                }
            }
            all_visited = is_all_visited(visited);
        }
        int impossible = 0;
        for (int j = 0; j < n; j++){
            // check if there is any sides with two +
            if (labels[j] == 1){
                // if this is a station
                for (int l = 0; l < (g.adj[j]).size(); l++){
                    int curr_neighbor = g.adj[j][l];
                    if (labels[curr_neighbor] == 1){
                        printf("Impossible");
                        impossible = 1;
                        break;
                    }
                }
            }
        }
        int stations = 0;
        for (int j = 0; j < n; j++){
            if (labels[j] == 1){
                stations++;
            }
        }
        printf("%d",stations);


    }
}