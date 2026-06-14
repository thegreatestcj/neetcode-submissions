class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        int left = 0;
        int right = n - 1;
        
        vector<int> leftPrefix(n);
        vector<int> rightPrefix(n);
        vector<int> res(n);
        int leftProduct = 1;
        int rightProduct = 1;

        for (int i = 0; i < n; i++)
        {
            leftProduct *= nums[i];
            leftPrefix[i] = leftProduct;
            rightProduct *= nums[n-i-1];
            rightPrefix[n-i-1] = rightProduct;
        }

        for (int i = 0; i < n; i++)
        {
            int product = 1;
            if (i >= 1)
            {
                product *= leftPrefix[i-1];
            } 
            if (i < n - 1)
            {
                product *= rightPrefix[i+1];
            }
            res[i] = product;
        }

        return res;
    }
};
