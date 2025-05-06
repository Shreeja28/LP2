#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Graph class
class Graph {
private:
    int V;  // Number of vertices
    vector<vector<int>> adjList;  // Adjacency list

public:
    // Constructor to initialize the graph with V vertices
    Graph(int V) {
        this->V = V;
        adjList.resize(V);  // Resize the adjacency list to hold V vertices
    }

    // Method to add an edge between two vertices (undirected)
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Recursive DFS function
    void DFS(int v, vector<bool>& visited) {
        // Mark the current node as visited
        visited[v] = true;
        cout << v << " ";  // Print the current node

        // Visit all the adjacent vertices recursively
        for (int adj : adjList[v]) {
            if (!visited[adj]) {
                DFS(adj, visited);
            }
        }
    }

    // Method to perform DFS traversal starting from a given vertex
    void DFS_traversal(int start) {
        vector<bool> visited(V, false);  // Initialize the visited array
        cout << "DFS Traversal starting from vertex " << start << ": ";
        DFS(start, visited);
        cout << endl;
    }

    void recursiveBFSHelper(vector<bool>& visited, queue<int>& q) {
        // If the queue is empty, return
        if (q.empty()) return;

        // Process the first node in the queue
        int node = q.front();
        q.pop();
        cout << node << " ";  // Print the current node

        // Visit all adjacent vertices and enqueue them if not visited
        for (int adj : adjList[node]) {
            if (!visited[adj]) {
                visited[adj] = true;
                q.push(adj);
            }
        }

        // Recurse and process the next level
        recursiveBFSHelper(visited, q);
    }
    void BFS(int start) {
        vector<bool> visited(V, false);  // Initialize visited array
        queue<int> q;  // Queue for BFS
        visited[start] = true;
        q.push(start);

        cout << "Recursive BFS Traversal starting from vertex " << start << ": ";
        // Call the helper function to simulate BFS
        recursiveBFSHelper(visited, q);
        cout << endl;
    }

};

// Main function to demonstrate graph traversal
int main() {
    // Create a graph with 5 vertices (0 to 6)
    Graph g(5);

    // Add edges to the graph (undirected)
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    



    // Perform DFS traversal starting from vertex 0
    g.DFS_traversal(0);

    // Perform BFS traversal starting from vertex 0
    g.BFS(0);

    return 0;
}