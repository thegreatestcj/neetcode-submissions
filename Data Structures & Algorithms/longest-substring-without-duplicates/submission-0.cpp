class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        int i = 0;
        int n = s.size();
        unordered_set<char> st;
        int start = 0;
        
        while (i < n)
        {
            while (i < n && st.count(s[i]))
            {
                st.erase(s[start]);
                start++;
            }

            if (!st.count(s[i]))
            {
                st.insert(s[i]);
                longest = max(longest, i - start + 1);
                i++;
            } 

        }

        return longest;
    }
};
