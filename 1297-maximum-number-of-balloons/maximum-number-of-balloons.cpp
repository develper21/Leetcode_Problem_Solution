class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string s = "balloon";
        unordered_map<char, double> mpp;

        mpp['b'] = 0;
        mpp['a'] = 0;
        mpp['l'] = 0;
        mpp['o'] = 0;
        mpp['n'] = 0;

        for (int i = 0; i< text.length(); i++) {
            char c = text[i];
            if (s.find(c) != string::npos) {
                if (c == 'o' || c =='l')
                    mpp[c] += 0.5;
                else
                    mpp[c]++;
            }
        }

        int mini = INT_MAX;
        for (auto itr : mpp) {
            mini = min(mini, (int)floor(itr.second));
        }
        return mini;
    }
};