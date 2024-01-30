class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        const vector<string> m = {
            "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> ans;
        ans.push_back("");
        for (char& d : digits) {
            vector<string> tmp;
            for (char c : m[d - '0']) {
                for (string& pre : ans) {
                    tmp.push_back(pre + c);
                }
            }
            swap(ans, tmp);
        }
        
        return ans;
    }
};
