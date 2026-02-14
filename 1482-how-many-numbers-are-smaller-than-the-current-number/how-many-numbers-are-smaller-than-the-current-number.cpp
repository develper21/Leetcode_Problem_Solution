class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int allNums[101] = {0};
        vector<int> res(nums.size(), 0);

        for(int v : nums) {
            allNums[v]++;
        }

        for(int v = 1; v < 101; ++v){
            allNums[v] += allNums[v - 1];
        }

        for(size_t i = 0; i < nums.size(); ++i){
            int v = nums[i];
            if(v == 0){
                res[i] = 0;
            } else {
                res[i] = allNums[v - 1];
            }
        }
        return res;        
    }
};