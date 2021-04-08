class Solution {
public:
    string simplifyPath(string path) {
        istringstream ss(path);
        string tmp;
        
        vector<string> q;
        while (getline(ss, tmp, '/')) {
            if (tmp == "" || tmp == ".") continue;
            if (tmp == "..") {
                if (!q.empty()) q.pop_back();
            } else {
                q.push_back(tmp);
            }
        }
        
        string ans;
        for (string name : q)
            ans += "/" + name;
        return ans.empty() ? "/" : ans;
    }
};
