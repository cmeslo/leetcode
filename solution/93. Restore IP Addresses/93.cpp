class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        dfs(s, 0);
        return res;
    }
    
private:
    vector<string> res;
    vector<string> cur;
    int n;
    
    void dfs(string& s, int i) {
        if (i == s.size()) {
            if (cur.size() == 4) {
                string ip = "";
                for (string& num : cur)
                    ip.append(num + '.');
                ip.pop_back();
                res.push_back(ip);
            }
            return;
        }
        for (int j = i; j < n && j - i + 1 <= 3; ++j) {
            string sub = s.substr(i, j - i + 1);
            if (cur.size() < 4 && checkOK(sub)) {
                cur.push_back(sub);
                dfs(s, j + 1);
                cur.pop_back();
            }
        }
    }
    
    bool checkOK(string& num) {
        if (num.size() > 1 && num[0] == '0') return false;
        if (stoi(num) > 255) return false;
        return true;
    }
};
