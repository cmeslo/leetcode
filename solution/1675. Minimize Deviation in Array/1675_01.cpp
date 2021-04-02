class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for (int x : nums)
            s.insert(x % 2 ? x * 2 : x);
        
        int ans = *rbegin(s) - *begin(s);
        while (*rbegin(s) % 2 == 0) {
            s.insert(*rbegin(s) / 2);
            s.erase(*rbegin(s));
            ans = min(ans, *rbegin(s) - *begin(s));
        }
        return ans;
    }
};
