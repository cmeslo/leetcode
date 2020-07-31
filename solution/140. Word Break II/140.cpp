class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        return wordBreak(s, dict);
    }
    
private:
    unordered_map<string, vector<string>> mem;
    
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if (mem.count(s)) return mem[s];
        
        
        vector<string> ans;
        if (dict.count(s)) ans.push_back(s);

        for (int i = 1; i < s.length(); i++) {
            const string& right = s.substr(i);
            if (!dict.count(right)) continue;
            
            const string& left = s.substr(0, i);
            vector<string> left_ans = append(wordBreak(left, dict), right);
            ans.insert(ans.end(), left_ans.begin(), left_ans.end());
        }
        
        mem[s] = ans;
        return mem[s];
    }
    
    vector<string> append(const vector<string>& prefixes, const string& right) {
        vector<string> res;
        for (const string& prefix : prefixes) {
            res.push_back(prefix + " " + right);
        }
        return res;
    }
};
