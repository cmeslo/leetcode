class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.empty() || k < 0 || t < 0) return false;
        
        int min_val = *min_element(begin(nums), end(nums));
        map<long, int> buckets;
        long bucket_width = (long)t + 1; // in case of zero
        
        for (int i = 0; i < nums.size(); ++i) {
            long bucket_index = ((long)nums[i] - min_val) / bucket_width;
            
            auto it = buckets.find(bucket_index - 1);
            if (it != buckets.end() && abs((long)nums[i] - it->second) < bucket_width)
                return true;
            
            it = buckets.find(bucket_index);
            if (it != buckets.end())
                return true;
            
            it = buckets.find(bucket_index + 1);
            if (it != buckets.end() && abs((long)nums[i] - it->second) < bucket_width)
                return true;
            
            buckets.insert({bucket_index, nums[i]});
            if (i >= k) buckets.erase(((long)nums[i - k] - min_val) / bucket_width);
        }
        
        return false;
    }
};
