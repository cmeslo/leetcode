class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<>> pq;
        for (int i = 0; i < n; ++i)
            pq.push({nums[i], i});
        
        long res = 0;
        for (int k = 1; k <= right; ++k) {
            auto [val, i] = pq.top(); pq.pop();
            if (k >= left)
                res += val;
            if (i + 1 < n) {
                pq.push({val + nums[i + 1], i + 1}); // 同一個 linked list 的下一個數字
            }
        }
        return res % MOD;
    }
};

// 1,2,3
    
// 1: 1, 3, 6
// 2: 2, 5
// 3: 3
