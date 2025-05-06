#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
private:
    int V;
    vector<vector<int> > adjList;
public:
    Graph(int V){
        this->V = V;
        adjList.resize(V);
    }
    void addEdge(int u,int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void dfs(int u,vector<bool> &visited){
        visited[u] = true;
        cout << u << " ";

        for(int adj : adjList[u]){
            if(!visited[adj]){
                dfs(adj,visited);
            }
        }
    }
    void dfs_traversal(int start){
        vector<bool> visited(V,false);
        cout << "DFS Traversal starting from vertex : " << start << " : ";
        dfs(start,visited);
        cout << endl;
    }
    void bfs(queue<int> &q,vector<bool> &visited){
        if(q.empty()) return;

        int u = q.front();
        q.pop();
        cout << u << " ";

        for(int adj : adjList[u]){
            if(!visited[adj]){
                visited[adj] = true;
                q.push(adj);
            }
        }

        bfs(q,visited);
    }

    void bfs_traversal(int start){
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "BFS Traversal starting from vertex : " << start << " : ";
        bfs(q, visited);
        cout << endl;
    }
};

int main(){
    int V;
    cout << "Enter the number of vertices : " << endl;
    cin >> V;

    if(V <= 0){
        cout << "The number of vertices must be greater than zero " << endl;
        exit(0);
    }
    Graph g(V);

    cout << "Enter edge one by one, enter -1,-1 to exit : " << endl;
    while (true)
    {
        int u, v;
        cin >> u >> v;

        if(u == -1 && v == -1) break;

        if ((u >= 0 && u < V) & (v >= 0 && v < V))
        {
            g.addEdge(u,v);
        }
        else{
            cout << "Enter a valid edge. Edge ( " << u << " , " << v << " ) skipped. " << endl;
        }
    }
    
    int ch,ch1,start;
    do
    {
        cout << "Enter your choice : " << endl;
        cout << "1-DFS Traversal\n2-BFS Traversal\n3-Exit\n";
        cin >> ch1;

        cout << "Enter starting point to start traversal : " << endl;
        cin >> start;

        if(ch1 == 1) g.dfs_traversal(start);
        else if(ch1 == 2) g.bfs_traversal(start);
        else
        {
            cout << "Thank you !! " << endl;
            exit(0);
        }

        cout << "Enter 1 to continue, Else 0 " << endl;
        cin >> ch;
    } while (ch == 1);
    
    return 0;
}