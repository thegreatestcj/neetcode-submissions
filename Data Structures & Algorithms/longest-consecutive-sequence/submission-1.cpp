class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;
        for (int num : st)
        {
            if (!st.count(num - 1))
            {
                int length = 0;
                while (st.count(num + length)) length++;
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
