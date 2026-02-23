class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        int mid = (n - 1) / 2;
        int end = n - 1;
        
        int idx = 0;

        while (idx < n) {
            nums[idx] = sorted[mid];
            mid--;
            idx += 2;
        }

        idx = 1;

        while (idx < n) {
            nums[idx] = sorted[end];
            end--;
            idx += 2;
        }
    }
};