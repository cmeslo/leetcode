class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        this->n = colors.size();
        vector<int> inDegree(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            G[a].push_back(b);
            inDegree[b]++;
        }
        
        int res = 1;
        unordered_set<char> s(colors.begin(), colors.end());
        for (char color = 'a'; color <= 'z'; ++color) {
            if (!s.count(color)) continue;
            int cur = count(color, colors, inDegree);
            if (cur == -1) return -1;
            res = max(res, cur);
        }
        return res;
    }
    
    
private:
    vector<int> G[100001];
    int n;
    
    int count(char& color, string& colors, vector<int> inDegree) {
        vector<int> freq(n); // 這個 color，由起點到當前節點的最大出現次數
        queue<int> q;
        int walkCount = 0;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                ++walkCount;
                freq[i] = colors[i] == color;
                q.push(i);
            }
        }
        int res = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int next : G[node]) {
                freq[next] = max(freq[next], freq[node] + (colors[next] == color));
                res = max(res, freq[next]);
                if (--inDegree[next] == 0) {
                    ++walkCount;
                    q.push(next);
                }
            }
        }
        
        if (walkCount != n) return -1; // cycle
        return res;
    }
};
