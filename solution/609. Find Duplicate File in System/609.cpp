class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        
        for (string& path : paths) {
            istringstream ss(path);
            string directory_path, info;
            ss >> directory_path;
            while (ss >> info) {
                int i = info.find('(');
                string file_content = info.substr(i + 1, info.size() - i - 1);
                string file_name = info.substr(0, i);
                m[file_content].push_back(directory_path + '/' + file_name);
            }
        }
        
        vector<vector<string>> ans;
        for (auto& [content, files] : m)
            if (files.size() > 1)
                ans.push_back(files);
        return ans;
    }
};
