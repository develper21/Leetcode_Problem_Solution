class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> inStack(26, false);
        for (char c : s)
            freq[c - 'a']++;

        string st;
        
        for (char c : s) {
            freq[c - 'a']--;

            if (inStack[c - 'a'])
                continue;

            while(!st.empty() && st.back() > c && freq[st.back() - 'a'] > 0) {
                inStack[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            inStack[c - 'a'] = true;
        }

        return st;
    }
};