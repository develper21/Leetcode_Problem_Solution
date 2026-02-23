class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
        //Find a potential Candidates
        for (int num : nums) {
            if (num == num1) {
                count1++;
            } else if (num == num2) {
                count2++;
            } else if (count1 == 0) {
                num1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                num2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Verify candidates
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == num1) count1++;
            if (num == num2) count2++;
        }

        vector<int> result;
        if (count1 > n / 3) result.push_back(num1);
        if (num1 != num2 && count2 > n / 3) result.push_back(num2);

        return result;
    }
};