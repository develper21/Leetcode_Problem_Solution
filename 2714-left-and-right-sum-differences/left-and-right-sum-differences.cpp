class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int leftSum = 0;
        int rightSum = totalSum;

        vector<int> answer;
        for (int i = 0; i < nums.size(); i++) {
            rightSum -= nums[i];
            answer.push_back(abs(leftSum - rightSum));
            leftSum += nums[i];
        }
        return answer;
    }
};