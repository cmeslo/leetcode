class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        int targetSize = n - k;
        
        string res;
        for (char& c : num) {
            while (!res.empty() && res.back() > c && k) {
                res.pop_back();
                k--;
            }
            if (!res.empty() || c != '0')
                res.push_back(c);
        }

        while (res.size() && k--) res.pop_back();
        return res.empty() ? "0" : res;
    }
};


// 1432219 -> xxxx

// 143
// 14
// 122
// 121
// 1219

// x..xx.x

// 1 1 2
