class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x1 = -1, x2 = -1, cnt1 = 0, cnt2 = 0;
        for (int x : nums) {
            if (x == x1) ++cnt1;
            else if (x == x2) ++cnt2;
            else if (cnt1 == 0) x1 = x, cnt1 = 1;
            else if (cnt2 == 0) x2 = x, cnt2 = 1;
            else --cnt1, --cnt2;
        }

        cnt1 = cnt2 = 0;
        for (int x : nums) {
            if (x == x1) ++cnt1;
            else if (x == x2) ++cnt2;
        }

        vector<int> res;
        if (cnt1 > nums.size() / 3) res.push_back(x1);
        if (cnt2 > nums.size() / 3) res.push_back(x2);
        return res;
    }
};
