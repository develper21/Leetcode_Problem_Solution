class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int val = 1;
        
        while (top <= bottom && left <= right) {
            
            for (int i = left; i <= right; i++)
                mat[top][i] = val++;
            top++;
            
     
            for (int i = top; i <= bottom; i++)
                mat[i][right] = val++;
            right--;
            
           
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    mat[bottom][i] = val++;
                bottom--;
            }
            
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    mat[i][left] = val++;
                left++;
            }
        }
        
        return mat;
    }
};