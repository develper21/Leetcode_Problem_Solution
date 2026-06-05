class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }

private:
    vector<int> digits;
    long long cntMemo[20][2][11][11];
    long long sumMemo[20][2][11][11];
    bool vis [20][2][11][11];

    pair<long long, long long> dfs(int pos, bool tight, bool started, int prev2, int prev1) {
        if (pos == (int)digits.size()) {
            return {1LL, 0LL};
        }

        if (!tight && vis[pos][started][prev2][prev1]) {
            return {cntMemo[pos][started][prev2][prev1], sumMemo[pos][started][prev2][prev1]};
        }

        int limit = tight ? digits[pos] : 9;
        long long totalCnt = 0;
        long long totalSum = 0;

        for (int d = 0; d <= limit; ++d) {
            bool nextTight = tight && (d == limit);
            bool nextStarted = started || (d != 0);

            pair<long long, long long> child;
            long long add = 0;

            if (!nextStarted) {
                child = dfs(pos + 1, nextTight, false, 10, 10);
            } else if (!started) {
                child = dfs(pos + 1, nextTight, true, 10, d);
            } else if (prev2 == 10) {
                child = dfs(pos + 1, nextTight, true, prev1, d);
            } else {
                add = ((prev1 > prev2 && prev1 > d) || (prev1 < prev2 && prev1 < d)) ? 1 : 0;
                child = dfs(pos + 1, nextTight, true, prev1, d);
            }

            totalCnt += child.first;
            totalSum += child.second + child.first * add;
        }

        if (!tight) {
            vis[pos][started][prev2][prev1] = true;
            cntMemo[pos][started][prev2][prev1] = totalCnt;
            sumMemo[pos][started][prev2][prev1] = totalSum;
        }

        return {totalCnt, totalSum};
    }

    long long solve(long long x) {
        if (x < 0) return 0;

        digits.clear();
        string s = to_string(x);
        for(char c : s) digits.push_back(c - '0');

        memset(vis, 0 , sizeof(vis));
        return dfs(0, true, false, 10, 10).second;
    }
};