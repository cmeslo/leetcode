class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        
        if (nums.empty()) return res;
        
        int n = 1;
        
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > n){
                res.push_back(n++);
            }
            if (nums[i] == n) n++;
        }
        
        while (n <= nums.size()) res.push_back(n++);
        
        return res;
    }
};
