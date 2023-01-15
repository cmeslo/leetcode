class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int len = (intLength + 1) / 2 - 1;
        long long base = pow(10, len);
        vector<long long> ans;
        for (int x : queries) {
            ans.push_back(get(intLength, base, x));
        }
        return ans;
    }
    
    long long get(int n, long long base, int x) {
        base += x - 1;
        string left = to_string(base);
        string right = left.substr(0, n % 2 ? left.size() - 1: left.size());
        reverse(right.begin(), right.end());
        string ans = left + right;
        return ans.size() > n ? -1 : stoll(ans);
    }
};
