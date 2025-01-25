class Solution {
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        dfs(s, 0);
        return res;
    }
    
private:
    int n;
    vector<vector<string>> res;
    vector<string> cur;
    
    void dfs(const string& s, int i) {
        if (i == n) {
            res.push_back(cur);
            return;
        }
        for (int j = i; j < n; ++j) {
            if (isPalindrome(s, i, j)) {
                cur.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
};


// a  a a   a b a
// x (x x) [x x x]
//    i j
   
// s[i:j] is palindrome + dfs(j + 1)
