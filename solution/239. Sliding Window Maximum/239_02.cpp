class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q; // {index1, index2, ...}

        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            
            q.push_back(i);

            if (i >= k - 1) {
                res.push_back(nums[q.front()]);
                if (q.front() == i - k + 1)
                    q.pop_front();
            }
        }

        return res;
    }
};
