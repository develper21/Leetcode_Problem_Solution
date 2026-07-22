class SparseTable {
private:
    vector<vector<int>> st;

public:
    SparseTable(const vector<int>& data) {
        st.push_back(data);
        int i = 1, N = st[0].size();
        while (2 * i <= N + 1) {
            const auto& pre = st.back();
            vector<int> cur;
            for (int j = 0; j < N - 2 * i + 1; j++) {
                cur.push_back(max(pre[j], pre[j + i]));
            }
            st.push_back(cur);
            i <<= 1;
        }
    }

    int query(int begin, int end) {
        if (begin > end) {
            return 0;
        }
        int len = end - begin + 1;
        int lg = 0;
        while ((1 << (lg + 1)) <= len) {
            lg++;
        }
        return max(st[lg][begin], st[lg][end - (1 << lg) + 1]);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s,
                                            vector<vector<int>>& queries) {
        int n = s.length();
        int cnt1 = count(s.begin(), s.end(), '1');

        vector<int> zeroBlocks;
        vector<int> blockLeft;
        vector<int> blockRight;

        int i = 0;
        while (i < n) {
            int st = i;
            while (i < n && s[i] == s[st]) {
                i += 1;
            }
            if (s[st] == '0') {
                zeroBlocks.push_back(i - st);
                blockLeft.push_back(st);
                blockRight.push_back(i - 1);
            }
        }

        int m = zeroBlocks.size();
        if (m < 2) {  // continuous 0 blocks less than 2 segments, return the
                      // answer directly
            return vector<int>(queries.size(), cnt1);
        }
        vector<int> tmpSum(m - 1);
        for (int i = 0; i < m - 1; i++) {
            tmpSum[i] = zeroBlocks[i] + zeroBlocks[i + 1];
        }
        SparseTable st(tmpSum);
        vector<int> ans;

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int i = lower_bound(blockRight.begin(), blockRight.end(), l) -
                    blockRight.begin();
            int j = upper_bound(blockLeft.begin(), blockLeft.end(), r) -
                    blockLeft.begin() - 1;

            // at most 1 continuous block of 0s within the substring
            if (i > m - 1 || j < 0 || i >= j) {
                ans.push_back(cnt1);
                continue;
            }

            int firstLen = blockRight[i] - max(blockLeft[i], l) +
                           1;  // actual length of the first consecutive block
                               // of 0s in the substring
            int lastLen = min(blockRight[j], r) - blockLeft[j] +
                          1;  // actual length of the last consecutive block of
                              // 0s in the substring
            // exactly 2 consecutive 0 blocks within the substring
            if (i + 1 == j) {
                int bestGain = firstLen + lastLen;
                ans.push_back(cnt1 + bestGain);
                continue;
            }

            int val1 = firstLen + zeroBlocks[i + 1];
            int val2 = zeroBlocks[j - 1] + lastLen;
            int val3 = st.query(i + 1, j - 2);
            int bestGain = max({val1, val2, val3});
            ans.push_back(cnt1 + bestGain);
        }

        return ans;
    }
};