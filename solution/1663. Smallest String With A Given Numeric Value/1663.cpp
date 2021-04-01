class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        
        k -= n;
        while (k > 0) {
            int tmp = min(25, k);
            ans[--n] += tmp;
            k -= tmp;
        }
        return ans;
    }
};
