class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (m + n) - accumulate(rolls.begin(), rolls.end(), 0);
        if (n > sum) return {};
        if (n * 6 < sum) return {};
        
        vector<int> res(n, 1);
        sum -= n;
        for (int i = 0; i < n && sum; ++i) {
            int mn = min(sum, 5);
            res[i] += mn;
            sum -= mn;
        }
        return res;
    }
};

// (1 5 6 x x x x) / (n + m) = mean

// (1 5 6 x x x x) / 7 = 3

// 12 + x x x x = 21

// x x x x = 9

// if (n > 9) return []

// if (n * 6 < 9) return []
