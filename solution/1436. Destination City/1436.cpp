class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        for (auto& path : paths)
            s.insert(path[1]);
        for (auto& path : paths)
            s.erase(path[0]);
        return *s.begin();
    }
};
