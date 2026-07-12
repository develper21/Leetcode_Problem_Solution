class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        unordered_map<int, int> rank;
        int r = 1;

        for (int num : temp) {
            if (!rank.count(num)) {
                rank[num] = r++;
            }
        }

        for (int &num : arr) {
            num = rank[num];
        }
        return arr;
    }
};