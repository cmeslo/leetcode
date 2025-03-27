class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        const int n = profit.size();
        
        vector<pair<int, int>> A(n);
        for (int i = 0; i < n; ++i)
            A[i] = {difficulty[i], profit[i]};
        
        sort(A.begin(), A.end());
        
        sort(worker.begin(), worker.end());
        
        int res = 0, i = 0;
        priority_queue<int> pq;
        for (int w : worker) {
            while (i < n && A[i].first <= w)
                pq.push(A[i++].second);
            if (!pq.empty())
                res += pq.top();
        }
        return res;
    }
};
