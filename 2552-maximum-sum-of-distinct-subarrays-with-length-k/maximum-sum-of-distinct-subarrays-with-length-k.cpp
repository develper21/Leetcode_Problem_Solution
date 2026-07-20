class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        long long sum = 0;
        long long ans = 0;

        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            mp[nums[i]]++;

            if(i >= k) {
                sum -= nums[i-k];
                mp[nums[i-k]]--;

                if(mp[nums[i-k]] == 0)
                    mp.erase(nums[i-k]);
            }

            if(i >= k-1 && mp.size() == k) {
                ans = max(ans,sum);
            }
        }

        return ans;
    }
};