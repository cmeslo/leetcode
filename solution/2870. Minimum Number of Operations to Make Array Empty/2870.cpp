class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int x : nums)
            m[x]++;

        int res = 0;
        for (auto& [_, cnt] : m) {
            if (cnt == 1) return -1;
            // res += cnt / 3 + (cnt % 3 == 1 || cnt % 3 == 2);
            res += cnt / 3 + (cnt % 3 > 0);
        }
        return res;
    }
};

// 0              => 0
// 1              => -1
// 2 -> 2         => 1
// 3 -> 3         => 1
// 4 -> 2 2       => 2
// 5 -> 3 2       => 2
// 6 -> 3 3       => 2
// 7 -> 3 2 2     => 3
// 8 -> 3 3 2     => 3
// 9 -> 3 3 3     => 3
// 10-> 3 3 2 2   => 4
// 11-> 3 3 3 2   => 4
// 12-> 3 3 3 3   => 4
// 13-> 3 3 3 2 2 => 5
// 14-> 3 3 3 3 2 => 5
