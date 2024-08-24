class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        for (int x : s2) {
            if (s1.count(x))
                res.push_back(x);
        }
        return res;
    }
};
