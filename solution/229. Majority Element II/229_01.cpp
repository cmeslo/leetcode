class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        unordered_map<int, int> m;
        for (int x : nums) {
            if (++m[x] > n/3) {
                m[x] = -n;
                res.push_back(x);
            }
        }
        return res;
    }
};
