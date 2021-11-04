class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> q;
        for (int x : nums) {
            auto it = lower_bound(begin(q), end(q), x);
            if (it == q.end())
                q.push_back(x);
            else
                *it = x;
        }
        return q.size();
    }
};
