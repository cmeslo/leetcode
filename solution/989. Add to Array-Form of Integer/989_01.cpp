class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int i = num.size() - 1;
        int carry = 0;
        while (i >= 0 || k || carry) {
            int x = (i >= 0 ? num[i--] : 0) + k % 10 + carry;
            k /= 10;
            res.push_back(x % 10);
            carry = x / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
