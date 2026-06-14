class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int num : nums)
        {
            mp[num]++;
        }

        int n = nums.size();

        vector<vector<int>> buckets(n + 1);

        for (auto& [num, freq] : mp)
        {
            buckets[freq].push_back(num);
        }

        vector<int> res;
        int i = n;
        int cnt = 0;
        while (i)
        {
            for (int num : buckets[i])
            {
                res.push_back(num);
                cnt++;
            }
            if (cnt == k) break;
            i--;
        }

        return res;

    }
};
