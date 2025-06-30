class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        const int n = nums.size();
        
        vector<pair<int, int>> A(n);
        for (int i = 0; i < n; ++i) {
            int hash = 0;
            string x = to_string(nums[i]);
            for (char& c : x)
                hash = hash * 10 + mapping[c - '0'];
            A[i] = {hash, i};
        }
        
        sort(A.begin(), A.end());
        
        vector<int> res(n);
        for (int i = 0; i < n; ++i)
            res[i] = nums[A[i].second];
        return res;
    }
};
