class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (string str : strs)
        {
            int s = str.size();
            encoded += to_string(s) + '#' + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int n = s.size();
        
        int i = 0;
        while (i < n)
        {
            int j = 0;
            while (s[i + j] != '#') j++;
            int len = stoi(s.substr(i, j));
            string str = s.substr(i + j + 1, len);
            decoded.push_back(str);
            i = i + j + len + 1;
        }

        return decoded;
    }
};
