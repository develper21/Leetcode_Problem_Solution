class Solution {
public:
    int maximumProduct(vector<int>& A) {
        ranges::sort(A);
        int n = A.size();
        
        return max(
            A.back() * A[n - 2] * A[n - 3],
            A.back() * A.front() * A[1]
        );
    }
};