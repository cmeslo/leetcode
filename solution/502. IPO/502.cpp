class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> A(n);
        for (int i = 0; i < n; ++i) {
            A[i] = {capital[i], profits[i]};
        }
        sort(A.begin(), A.end());
        
        priority_queue<int> pq;
        int i = 0;
        while (k--) {
            while (i < n && w >= A[i].first) {
                pq.push(A[i].second);
                i++;
            }
            if (pq.empty()) break;
            w += pq.top(); pq.pop();
        }
        return w;
    }
};
