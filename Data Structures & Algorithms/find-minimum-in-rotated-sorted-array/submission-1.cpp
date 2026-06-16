class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        // if (right == 0) return 1;
        int mid = 0;

        // nums[res-1] is the largest num

        while (left < right)
        {
            mid = (left + right) / 2;
            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            } else if (nums[mid] <= nums[right])
            {
                right = mid;
            }
        }


        return nums[left];
    }
};
