class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindrome
        if (x < 0) return false;

        // Number ending with 0(but not 0 itself) are not palindrome
        if (x % 10 == 0 && x != 0) return false;

        int reverseHalf = 0;
        while (x > reverseHalf) {
            reverseHalf = reverseHalf * 10 + x % 10;
            x /= 10;
        }

        // For evven digit: x == reverseHalf
        // For odd digit: x == reverseHalf/10

        return (x == reverseHalf || x == reverseHalf / 10);
    }
};