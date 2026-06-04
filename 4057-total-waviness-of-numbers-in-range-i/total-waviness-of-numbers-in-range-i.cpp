class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int x = num1; x <= num2; x++) {
            ans += waviness(x);
        }
        return ans;
    }
private:
    int waviness(int x) {
        vector<int> digits;
        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }

        int m = digits.size();
        if (m < 3) return 0;

        int count = 0;
        for (int i = 1; i < m - 1; i++) {
            if ((digits[i] > digits[i - 1] && digits[i] > digits[i + 1]) ||
                (digits[i] < digits[i - 1] && digits[i] < digits[i + 1])) {
                    count++;
            }
        }
        return count;
    }
};