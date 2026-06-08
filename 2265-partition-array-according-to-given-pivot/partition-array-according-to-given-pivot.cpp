class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left, mid, right;

        for (int num : nums) {
            if(num < pivot) {
                left.push_back(num);
            } else if(num == pivot) {
                mid.push_back(num);
            } else {
                right.push_back(num);
            }
        }

        vector<int> ans;
        ans.reserve(nums.size());

        for (int x : left) ans.push_back(x);
        for (int x : mid) ans.push_back(x);
        for (int x : right) ans.push_back(x);

        return ans;
    }
};