class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] > 0) break;
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > target)
                {
                    right--;
                } else if (nums[left] + nums[right] < target)
                {
                    left++;
                } else
                {
                    vector<int> triplet(3);
                    triplet[0] = nums[i];
                    triplet[1] = nums[left];
                    triplet[2] = nums[right];
                    res.push_back(triplet);
                    left++;
                    right--;
                    while ((left < right) && (nums[left] == nums[left-1])) left++;
                    while ((left < right) && (nums[right] == nums[right+1])) right--;
                }
            }
        }
        return res;
    }

};
