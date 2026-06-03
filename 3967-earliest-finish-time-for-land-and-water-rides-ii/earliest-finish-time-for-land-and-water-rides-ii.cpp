class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        auto calc = [&](vector<int>& a1, vector<int>& t1,
                        vector<int>& a2, vector<int>& t2) -> long long {
            long long minEnd = LLONG_MAX;
            for (int i = 0; i < (int)a1.size(); ++i) {
                minEnd = min(minEnd, 1LL * a1[i] + t1[i]);
            }

            long long ans = LLONG_MAX;
            for (int i = 0; i < (int)a2.size(); ++i) {
                ans = min(ans, max(minEnd, 1LL * a2[i]) + t2[i]);
            }
            return ans;
        };

        long long x = calc(landStartTime, landDuration, waterStartTime, waterDuration);
        long long y = calc(waterStartTime, waterDuration, landStartTime, landDuration);
        return (int)min(x, y);
    }
};