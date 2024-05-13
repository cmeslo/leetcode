class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (int i = 0; i < n; ++i)
            tasks[i].push_back(i);
        
        sort(begin(tasks), end(tasks));
        
        using PII = pair<int, int>; // {processingTime, index}
        priority_queue<PII, vector<PII>, greater<>> q;
        
        vector<int> ans;
        long curTime = 0;
        int i = 0;
        while (i < n || !q.empty()) {
            if (q.empty())
                curTime = max(curTime, (long)tasks[i][0]);
            
            while (i < n && tasks[i][0] <= curTime) {
                q.emplace(tasks[i][1], tasks[i][2]);
                ++i;
            }
            auto [processingTime, index] = q.top(); q.pop();
            curTime += processingTime;
            ans.push_back(index);
        }
        
        return ans;
    }
};
