class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        vector<int> f(101);
        for (int x : nums) {
            res += f[x];
            f[x]++;
        }
        return res;
    }
};
