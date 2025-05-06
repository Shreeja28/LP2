#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
public:
    unordered_map<int, vector<int>> adjList;

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // undirected
    }

private:
    bool isSafe(int node, int colorToAssign, const vector<int>& colors) {
        for (int neighbor : adjList[node]) {
            if (colors[neighbor] == colorToAssign)
                return false;
        }
        return true;
    }

    // Get the node with the most constraints (degree), for better bounding
    int selectNextNode(const vector<int>& colors, int n) {
        int maxDegree = -1, selectedNode = -1;
        for (int i = 0; i < n; ++i) {
            if (colors[i] == 0) {
                int degree = adjList[i].size();
                if (degree > maxDegree) {
                    maxDegree = degree;
                    selectedNode = i;
                }
            }
        }
        return selectedNode;
    }

    bool solve(int m, int n, vector<int>& colors, int coloredCount) {
        if (coloredCount == n) return true;

        int node = selectNextNode(colors, n); // BnB optimization

        for (int color = 1; color <= m; ++color) {
            if (isSafe(node, color, colors)) {
                colors[node] = color;

                if (solve(m, n, colors, coloredCount + 1)) return true;

                colors[node] = 0; // backtrack
            }
        }

        return false;
    }

public:
    bool colorGraph(int m, int n) {
        vector<int> colors(n, 0); // 0 = no color assigned

        if (solve(m, n, colors, 0)) {
            cout << "Graph can be colored with " << m << " colors.\n";
            for (int i = 0; i < n; ++i) {
                cout << "Node " << i << " ---> Color " << colors[i] << endl;
            }
            return true;
        } else {
            cout << "Graph cannot be colored with " << m << " colors.\n";
            return false;
        }
    }
};

int main() {
    Graph g;
    int n = 4;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(0, 2); // Complete graph (K4)

    int m = 3; // Try changing to 4 for success

    g.colorGraph(m, n);

    return 0;
}
