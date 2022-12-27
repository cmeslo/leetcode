class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        vector<int> A;
        for (int x : nums) {
            if (A.empty() || A.back() <= x) {
                A.push_back(x);
            } else {
                auto it = upper_bound(A.begin(), A.end(), x);
                *it = x;
            }
        }
        return A.size() >= nums.size() - 1;
    }
};
