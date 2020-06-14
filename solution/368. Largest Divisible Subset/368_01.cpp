class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        _memo = vector<int>(nums.size(), -1);
        
        vector<int> curr;
        backtrack(nums, curr, 0);
        return _res;
    }
    
private:
    vector<int> _res;
    vector<int> _memo; // memo for subset size
    
    void backtrack(const vector<int>& nums, vector<int>& curr, int index) {
        int len = curr.size();
        if (len > _res.size()) _res = curr;

        for (int i = index; i < nums.size(); i++) {
            int last = !curr.empty() ? curr.back() : 1;
            if ((len > _memo[i]) && (nums[i] % last == 0)) {
                _memo[i] = len;
                curr.push_back(nums[i]);
                backtrack(nums, curr, i+1);
                curr.pop_back();
            }
        }
    }
};
