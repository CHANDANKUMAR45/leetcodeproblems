class Solution {
public:
   void DFS(int node, int parent, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low, 
                         vector<bool>& visited, vector<vector<int>>& Bridges, int &count) {
    
    // Initialize discovery time and low value
    disc[node] = low[node] = count++;
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (neighbor == parent) {
            // If the neighbor is the parent, skip
            continue;
        }

        if (!visited[neighbor]) {
            // If neighbor is not visited, recursively DFS
            DFS(neighbor, node, adj, disc, low, visited, Bridges, count);
            
            // Check if the subtree rooted at neighbor has a connection back to one of the ancestors
            low[node] = min(low[node], low[neighbor]);

            // If the lowest vertex reachable from the subtree under neighbor is higher than discovery time of node
            if (low[neighbor] > disc[node]) {
                Bridges.push_back({node, neighbor});  // This edge is a bridge
            }
        } else {
            // Update low value of node for parent function calls
            low[node] = min(low[node], disc[neighbor]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    
    vector<vector<int>> adj(n);  // Adjacency list for the graph

    // Build the graph
    for (const auto& conn : connections) {
        int u = conn[0];
        int v = conn[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> Bridges;  // To store all the bridges
    vector<int> disc(n, -1);  // Discovery times of visited vertices
    vector<int> low(n, -1);   // Earliest visited vertex reachable
    vector<bool> visited(n, false);  // Visited array
    int count = 0;  // Time counter for DFS

    // Apply DFS to find all bridges
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, -1, adj, disc, low, visited, Bridges, count);
        }
    }

    return Bridges;
}
};

