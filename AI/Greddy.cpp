#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> P; // pair<weight, vertex>

class Graph {
    int V;
    vector<vector<P>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int primsMST(int start) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, start});
        vector<bool> inMst(V, false);
        int sum = 0;

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int wt = p.first;
            int node = p.second;

            if (inMst[node])
                continue;

            inMst[node] = true;
            sum += wt;

            for (auto &tmp : adj[node]) {
                int neighbor = tmp.first;
                int neighbor_wt = tmp.second;

                if (!inMst[neighbor]) {
                    pq.push({neighbor_wt, neighbor});
                }
            }
        }
        return sum;
    }
};

class Job {
public:
    char id;
    int deadline;
    int profit;

    Job(char id, int deadline, int profit) {
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
};

// Used only inside Job Scheduling
bool compareJobs(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(vector<Job>& jobs) {
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), compareJobs); // Use built-in sort

    vector<bool> slot(n, false);
    vector<char> jobSequence;
    int totalProfit = 0, jobCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                jobSequence.push_back(jobs[i].id);
                totalProfit += jobs[i].profit;
                jobCount++;
                break;
            }
        }
    }

    cout << "Total jobs done: " << jobCount << endl;
    cout << "Total profit: " << totalProfit << endl;
    cout << "Job sequence: ";
    for (char c : jobSequence) {
        cout << c << " ";
    }
    cout << endl;
}

// Standalone Selection Sort for integers
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(arr[i], arr[min_idx]);
    }
}

int main() {
    int choice;
    cout << "===== MENU =====\n";
    cout << "1. Find MST using Prim's Algorithm\n";
    cout << "2. Perform Greedy Job Scheduling\n";
    cout << "3. Perform Selection Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int V, E;
        cout << "Enter number of vertices and edges: ";
        cin >> V >> E;

        Graph g(V);
        cout << "Enter " << E << " edges (u v weight):\n";
        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
        }

        int start;
        cout << "Enter starting node for Prim's Algorithm (0 to " << V - 1 << "): ";
        cin >> start;

        if (start < 0 || start >= V) {
            cout << "Invalid starting node.\n";
            return 1;
        }

        int mstWeight = g.primsMST(start);
        cout << "Total weight of MST: " << mstWeight << endl;
    }
    else if (choice == 2) {
        int n;
        cout << "Enter the number of jobs: ";
        cin >> n;

        vector<Job> jobs;
        cout << "Enter job details (ID Deadline Profit):\n";
        for (int i = 0; i < n; i++) {
            char id;
            int deadline, profit;
            cin >> id >> deadline >> profit;
            jobs.push_back(Job(id, deadline, profit));
        }

        jobScheduling(jobs);
    }
    else if (choice == 3) {
        int n;
        cout << "Enter number of elements for selection sort: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter " << n << " elements:\n";
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        selectionSort(arr);

        cout << "Sorted array: ";
        for (int x : arr)
            cout << x << " ";
        cout << endl;
    }
    else {
        cout << "Invalid choice.\n";
    }

    return 0;
}

// Enter your choice: 1
// Enter number of vertices and edges: 4 5
// Enter 5 edges (u v weight):
// 0 1 10
// 0 2 6
// 0 3 5
// 1 3 15
// 2 3 4
// Enter starting node for Prim's Algorithm (0 to 3): 0

// Enter your choice: 2
// Enter the number of jobs: 4
// Enter job details (ID Deadline Profit):
// a 2 100
// b 1 19
// c 2 27
// d 1 25

// Enter your choice: 3
// Enter number of elements for selection sort: 5
// Enter 5 elements:
// 64 25 12 22 11



