class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> A(nums1.begin(), nums1.end()), B(nums2.begin(), nums2.end());
        vector<int> ans1, ans2;
        for (int x : A)
            if (!B.count(x))
                ans1.push_back(x);
        for (int x : B)
            if (!A.count(x))
                ans2.push_back(x);
        return {ans1, ans2};
    }
};
