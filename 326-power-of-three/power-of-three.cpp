class Solution {
public:
    bool isPowerOfThree(int n) {
        double target = 1;
        while(1){
            if(target > n) return false;
            else if(target == n) return true;
            target = target * 3;
        }
    }
};