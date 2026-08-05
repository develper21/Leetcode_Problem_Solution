class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for(auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            adj [u].push_back(v);
        }

        vector<bool> suspicious(n, false);
        suspicious[k] = true;

        queue<int> q;
        q.push(k);

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int v : adj[u]) {
                if(!suspicious[v]) {
                    suspicious[v] = true;
                    q.push(v);
                }
            }
        }

        for(auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if(!suspicious[u] && suspicious[v]) {
                vector<int> allMethods(n);

                iota(
                    allMethods.begin(),
                    allMethods.end(),
                    0
                );
                return allMethods;
            }
        }

        vector<int> result;

        for(int i = 0; i < n; i++) {
            if(!suspicious[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};