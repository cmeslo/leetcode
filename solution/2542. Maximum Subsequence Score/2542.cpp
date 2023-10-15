class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        using pii = pair<int, int>;
        int n = nums1.size();
        
        vector<pii> A(n);
        for (int i = 0; i < n; ++i)
            A[i] = {nums2[i], nums1[i]};
        
        sort(A.rbegin(), A.rend());
        
        long long res = 0, sum = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        for (auto& [mn, x] : A) {
            pq.push(x);
            sum += x;
            if (pq.size() == k) {
                res = max(res, sum * mn);
                sum -= pq.top(); pq.pop();
            }
        }
        return res;
    }
};

// 2 3 1 3
// 4 3 2 1
