class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            s.insert(nums[i]);
            if (i >= k - 1) {
                if (i >= k) {
                    auto it = s.find(nums[i - k]);
                    s.erase(it);
                }
                res.push_back(*s.rbegin());
            }
        }
        return res;
    }
};
