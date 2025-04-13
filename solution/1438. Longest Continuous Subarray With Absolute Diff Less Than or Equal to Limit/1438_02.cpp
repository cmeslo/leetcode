class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = 0;
        deque<int> maxd, mind;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            while (!maxd.empty() && maxd.back() < nums[r]) maxd.pop_back();
            while (!mind.empty() && mind.back() > nums[r]) mind.pop_back();
            maxd.push_back(nums[r]);
            mind.push_back(nums[r]);
            while (maxd.front() - mind.front() > limit) {
                if (maxd.front() == nums[l]) maxd.pop_front();
                if (mind.front() == nums[l]) mind.pop_front();
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
