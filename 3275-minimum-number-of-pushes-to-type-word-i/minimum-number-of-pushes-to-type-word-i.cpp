class Solution {
public:
    int minimumPushes(string word) {
        auto q = word.size() >> 3, r = word.size() & 7;
        return ((q << 2) + r) * (q + 1);
    }
};