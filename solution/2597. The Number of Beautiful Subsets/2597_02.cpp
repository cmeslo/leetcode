class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int x : nums) ++count[x];
        
        unordered_map<int, vector<pair<int, int>>> m;
        for (auto [x, cnt] : count)
            m[x % k].push_back({x, cnt});
        
        int res = 1;
        for (auto [_, arr] : m) {
            sort(arr.begin(), arr.end());
            
            int pre = 0;
            int no_take = 1, take = 0;
            for (auto [x, cnt] : arr) {
                int pre_take = take;
                if (x - pre == k) {
                    take = no_take * (pow(2, cnt) - 1);
                    no_take = pre_take + no_take;
                } else {
                    take = (take + no_take) * (pow(2, cnt) - 1);
                    no_take = pre_take + no_take;
                }
                pre = x;
            }
            res *= take + no_take;
        }
        return res - 1;
    }
};
