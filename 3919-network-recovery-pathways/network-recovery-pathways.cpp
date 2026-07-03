class Solution {
public:
    long long INF = 4e18;
    bool canAchive(
        int node,
        int limit,
        long long budget,
        vector<vector<pair<int, int>>>& graph,
        vector<long long>& dp
    ) {
        return dfs(node, limit, graph, dp) <= budget;
    }

    long long dfs(
        int node,
        int limit,
        vector<vector<pair<int, int>>>& graph,
        vector<long long>& dp
    ) {
        int destination = graph.size() - 1;
        if (node == destination)
            return 0;

        if (dp[node] != -1)
            return dp[node];
        
        long long bestCost = INF;
        for (auto &[next, weight] : graph[node]) {
            if (weight < limit)
                continue;

            bestCost = min(
                bestCost,
                weight + dfs(next, limit, graph, dp)
            );
        }
        return dp[node] = bestCost;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> graph(n);
        int low = INT_MAX;
        int high = 0;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (!online[u] || !online[v])
                continue;
            graph[u].push_back({v, w});

            low = min(low, w);
            high = max(high, w);
        }

        auto possible = [&](int score) {
            vector<long long> dp(n, -1);
            return dfs(0, score, graph, dp) <= k;
        };

        if (!possible(low))
            return -1;
        int answer = low;

        while(low <= high) {
            int mid = low + (high - low)/2;
            if (possible(mid)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return answer;
    }
};