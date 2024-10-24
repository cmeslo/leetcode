class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        const int n = tickets.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            q.push({i, tickets[i]});
        }
        
        int res = 0;
        while (!q.empty()) {
            auto [i, cnt] = q.front(); q.pop();
            if (i == k && cnt == 1) return res + 1;
            if (cnt > 1)
                q.push({i, cnt - 1});
            ++res;
        }
        return res;
    }
};
