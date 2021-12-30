class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<int>> m;
        
        for (int i = 0; i < strs.size(); ++i) {
            string key = strs[i];
            sort(key.begin(), key.end());
            m[key].push_back(i);
        }
        
        for (auto& kv : m) {
            ans.push_back({});
            for (int i : kv.second)
                ans.back().push_back(strs[i]);
        }
        return ans;
    }
};
