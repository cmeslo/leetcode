class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> arr(nums.begin(), nums.end());
        sort(arr.rbegin(), arr.rend());
        multiset<int> s;
        for (int i = 0; i < k; ++i)
            s.insert(arr[i]);
        
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = s.find(nums[i]);
            if (it != s.end()) {
                res.push_back(nums[i]);
                s.erase(it);
            }
        }
        return res;
    }
};
