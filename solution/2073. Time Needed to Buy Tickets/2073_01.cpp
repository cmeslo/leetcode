class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        for (int i = 0; i < tickets.size(); ++i)
            q.push(i);
        
        int res = 0;
        while (tickets[k]) {
            int i = q.front(); q.pop();
            if (--tickets[i])
                q.push(i);
            ++res;
        }
        return res;
    }
};
