class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> inResult(26, false);
        
        for (const char& c : s)
            ++count[c - 'a'];
        
        string ans = "";
        for (const char& c : s) {
            --count[c - 'a'];
            if (inResult[c - 'a']) continue;
            
            while (!ans.empty() && ans.back() > c && count[ans.back() - 'a'] > 0) {
                inResult[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(c);
            inResult[c - 'a'] = true;
        }
        
        return ans;
    }
};
