class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int start = 0;
        int longest = 0;
        unordered_map<char,int> mp;
        int max_freq = 0;

        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
            max_freq = max(max_freq, mp[s[i]]);

            if (i - start + 1 - max_freq > k)
            {
                mp[s[start]]--;
                start++;
            }

            longest = max(longest, i - start + 1);
        }
        return longest;
    }
};
