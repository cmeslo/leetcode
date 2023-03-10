class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        
        for (string& path : paths) {
            istringstream iss(path);
            string dir_path, info;
            iss >> dir_path;
            while (iss >> info) {
                int i = info.find('(');
                string filename = info.substr(0, i);
                string content = info.substr(i);
                m[content].push_back(dir_path + '/' + filename);
            }
        }
        
        vector<vector<string>> res;
        for (auto it : m) {
            vector<string> cur;
            if (it.second.size() > 1)
                res.push_back(it.second);
        }
        return res;
    }
};
