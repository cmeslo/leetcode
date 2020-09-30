class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for (int i = 1; i < 10; ++i)
            q.push(i);
        
        vector<int> ans;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (high < cur) break;
            
            if (low <= cur)
                ans.push_back(cur);
            
            int last = cur % 10;
            if (last < 9)
                q.push(cur * 10 + (last + 1));
        }
        
        return ans;
    }
};
