class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        using ll = long long;
        int n = nums.size();
        vector<pair<int, int>> A(n);
        for (int i = 0; i < n; ++i) {
            A[i] = {nums[i], cost[i]};
        }
        sort(A.begin(), A.end());
        for (int i = 0; i < n; ++i) {
            nums[i] = A[i].first;
            cost[i] = A[i].second;
        }
        
        vector<ll> costSum(n);
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = costSum[i] = sum + cost[i];
        }
        vector<ll> leftCost(n), rightCost(n);
        for (int i = 1; i < n; ++i) {
            leftCost[i] = leftCost[i - 1] + (nums[i] - nums[i - 1]) * costSum[i - 1];
        }
        for (int i = n - 2; i >= 0; --i) {
            rightCost[i] = rightCost[i + 1] + (nums[i + 1] - nums[i]) * (costSum[n - 1] - costSum[i]);
        }
        ll ans = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, leftCost[i] + rightCost[i]);
        }
        return ans;
    }
};


// nums = [1 2  5 3]
//           i
// cost = [2 14 1 3]

// costSum[0:i] := 由 0 至 i 上升一格所需要用的 cost 總和

// leftCost[i] = leftCost[i - 1] + (nums[i] - nums[i - 1]) * costSum[0:i-1]
// rightCost[i] = rightCost[i + 1] + (nums[i + 1] - nums[i]) * costSum[i+1:n-1]

// min{leftCost[i] + rightCost[i]}
