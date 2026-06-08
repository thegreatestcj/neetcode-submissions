class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char,int> mps;
        unordered_map<char,int> mpt;
        for (char i : s)
        {
            mps[i]++;
        }
        for (char j : t)
        {
            mpt[j]++;
        }
        return mps == mpt;

    }
};
