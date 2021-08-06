class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size();
        vector<string> ans;
        for (int i = 1; i < n - 2; ++i) {
            auto A = f(s.substr(1, i)), B = f(s.substr(i + 1, n - 2 - i));
            for (auto& a : A)
                for (auto& b : B)
                    ans.push_back("(" + a + ", " + b + ")");
        }
        return ans;
    }
    
private:
    vector<string> f(string s) {
        int n = s.size();
        if (n == 0) return {}; // ""
        if (n == 1) return {s}; // "0", "1"
        if (s[0] == '0' && s[n - 1] == '0') return {}; // "0xxxx0"
        if (s[0] == '0') return {"0." + s.substr(1)}; // "0xxxx1"
        if (s[n - 1] == '0') return {s}; // "1xxx0"
        
        vector<string> res = {s};
        for (int i = 1; i < n; ++i)
            res.push_back(s.substr(0, i) + '.' + s.substr(i));
        return res;
    }
};
