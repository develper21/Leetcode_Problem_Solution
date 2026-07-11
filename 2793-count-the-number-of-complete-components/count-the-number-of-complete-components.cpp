class Solution {
public:
    void BFS(vector<vector<int>>& adj, int u, vector<bool>& visited, int& completeComponents) {
        queue<int> q;
        visited[u] = true;
        q.push(u);

        int vertices = 0;
        int degreeSum = 0;
        
        while(!q.empty()) {
            int u = q.front(); q.pop();
            vertices++;
            degreeSum += adj[u].size();

            for (int &v: adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        if (vertices*(vertices - 1) == degreeSum)
            completeComponents++;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &ele : edges) {
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }

        vector<bool> visited(n, false);
        int completeComponents = 0;
        for (int i = 0; i < n; i++) {
            if (!visited [i])
                BFS(adj, i, visited, completeComponents);
        }
        return completeComponents;
    }
};