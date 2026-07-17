class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        long long int mx = *max_element(nums.begin(), nums.end());

        vector<int> mp(mx + 1, 0);
        for (auto it : nums) {
            mp[it]++;
        }

        vector<long long> cnt(mx + 1, 0);

        for (int i = mx; i >= 1; i--) {
            long long curr = 0;

            for (int k = i; k <= mx; k += i) {
                curr += mp[k];
            }

            cnt[i] = curr * (curr - 1) / 2;

            for (int k = 2 * i; k <= mx; k += i) {
                cnt[i] -= cnt[k];
            }
        }

        for (int i = 1; i <= mx; i++) {
            cnt[i] += cnt[i - 1];
        }

        vector<int> sol;

        for (auto it : queries) {
            sol.push_back(lower_bound(cnt.begin(), cnt.end(), it + 1) - cnt.begin());
        }

        return sol;
    }
};