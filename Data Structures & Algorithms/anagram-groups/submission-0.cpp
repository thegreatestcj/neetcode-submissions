class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        unordered_map<string,vector<string>> cmbs;
        for (int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            map<char,int> cmb;
            for (char ch : str)
            {
                cmb[ch]++;
            }
            string cm;
            for (const auto& [c, cnt] : cmb)
            {
                cm = cm + c + to_string(cnt);
            }
            
            cmbs[cm].push_back(str);
        }

        for (const auto& pair : cmbs)
        {
            groups.push_back(pair.second);
        }

        return groups;

    }
};
