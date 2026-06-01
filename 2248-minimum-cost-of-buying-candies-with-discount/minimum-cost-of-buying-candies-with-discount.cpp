class Solution {
public:
    int minimumCost(vector<int>& cost) {
        // METHOD: Greedy + Sorting
        // APPROACH: Set array in descending order, every three candies in a group, first& second payable and  last candie was free because third candie didn't on index third position.
        sort(cost.rbegin(), cost.rend());

        // Store a finaly value.
        int total = 0;
        for(int i = 0; i < cost.size(); i++) {
            // Every third candie are free so use i + 1 because of index 0-based on.
            if( (i + 1) % 3 != 0 ){
                // Add a paid candie cost in total.
                total += cost[i];
            }
        }

        return total;
    }
};