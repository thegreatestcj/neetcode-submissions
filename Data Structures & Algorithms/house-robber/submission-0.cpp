class Solution {
public:
    int rob(vector<int>& nums) {
        // prev2 = dp[i-2], prev1 = dp[i-1]
        int prev2 = 0, prev1 = 0;
        for (int num : nums) {
            // cur = max(skip this house, rob this house)
            int cur = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1; // dp[n-1]
    }
};
