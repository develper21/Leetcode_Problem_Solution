class Solution {
public:
    vector<int> fairCandySwap(vector<int>& alice, vector<int>& bob) {
        vector<int> ans(2,0);
        int asum = 0 , bsum = 0;
        for(auto x : alice)
        asum += x;
        for(auto x : bob)
        bsum += x;

        sort(alice.begin(),alice.end());
        sort(bob.begin(),bob.end());

        for(auto x : alice){
            int l = 0 , r = bob.size()-1 , mid;
            while(l<=r){
                mid = (l+r)/2;
                if(asum-x+bob[mid] == bsum-bob[mid]+x){
                    ans[0] = x;
                    ans[1] = bob[mid];
                    return ans;
                }else if(asum-x+bob[mid] > bsum-bob[mid]+x){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            } 
        }
        return ans;
    }
};