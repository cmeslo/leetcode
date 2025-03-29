class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        const int n = profit.size();
        
        vector<pair<int, int>> A(n);
        for (int i = 0; i < n; ++i)
            A[i] = {difficulty[i], profit[i]};
        
        sort(A.begin(), A.end());
        
        sort(worker.begin(), worker.end());
        
        int res = 0, i = 0, mx = 0;
        priority_queue<int> pq;
        for (int w : worker) {
            while (i < n && A[i].first <= w)
                mx = max(mx, A[i++].second);
            res += mx;
        }
        return res;
    }
};
