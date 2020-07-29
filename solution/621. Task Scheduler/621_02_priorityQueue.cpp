class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res = 0, partLen = n + 1;
        unordered_map<char, int> m;
        priority_queue<int> q;
        
        for (int t : tasks) ++m[t];
        for (auto a : m) q.push(a.second);
        
        while(!q.empty()) {
            vector<int> part;
            for (int i = 0; i < partLen; ++i) {
                if (!q.empty()) {
                    part.push_back(q.top()); q.pop();
                }
            }
            for (int p : part) if (--p > 0) q.push(p);
            
            res += q.empty() ? part.size() : partLen;
        }
        return res;
    }
};
