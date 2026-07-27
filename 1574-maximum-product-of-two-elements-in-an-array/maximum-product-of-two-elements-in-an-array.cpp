#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return (nums[0]-1)*(nums.back()-1);

        int m0 = nums[0], m1 = nums[1];
        if(m0 < m1) swap(m0,m1);

        for(int i = 2; i < n; i++) {
            int x = nums[i];
            if( x > m0) {
                m1 = m0, m0 = x;
            } else if(x > m1) m1 = x;
        }
        return (m0 - 1)*(m1 - 1);
    }
};

auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();