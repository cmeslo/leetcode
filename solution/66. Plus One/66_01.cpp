class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if (n == 0)  return vector<int>{1};
        
        vector<int> res(n + 1, 0);
        res[n] = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i + 1] = digits[i] + res[i + 1];
            if (res[i + 1] >= 10) {
                res[i] = res[i + 1] / 10;
                res[i + 1] = res[i + 1] % 10;
            }
        }
        if (res.size() > 1 && res[0] == 0) res.erase(res.begin());
        return res;
    }
};
