class Solution {
public:
    double myPow(double x, int n) {
        if(n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1  : 0;
        if(n == INT_MIN) return (x == 1 || x == -1)  ? 1 : 0;
        double num = 1;
        if(n >= 0){
            while(n > 0){
                num *= x;
                n--;
            } 
            } else {
                n = -n;
                while(n > 0){
                    num *= x;
                    n--;
                }
            num = 1.0/num;
        } 
        return num;
    }
};