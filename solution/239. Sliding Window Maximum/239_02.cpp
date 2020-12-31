class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> indexs;
        
        for (int i = 0; i < nums.size(); ++i) {
            while (!indexs.empty() && nums[indexs.back()] <= nums[i])
                indexs.pop_back();
            indexs.push_back(i);
            
            if (i < k - 1) continue;
            
            ans.push_back(nums[indexs.front()]);
            
            if (i - k + 1 == indexs.front())
                indexs.pop_front();
        }
        
        return ans;
    }
};
