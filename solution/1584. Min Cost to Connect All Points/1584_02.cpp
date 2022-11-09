class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        int res = 0;
        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, false);
        minDist[0] = 0;
        
        for (int connected = 0; connected < n; ++connected) {
            // 1. 找到下一個要接入MST的節點
            int next = -1, nextDist = INT_MAX;
            for (int i = 0; i < n; ++i) {
                if (visited[i]) continue;
                if (minDist[i] < nextDist) {
                    next = i;
                    nextDist = minDist[next];
                }
            }
            visited[next] = true;
            res += nextDist;
            
            // 2. 接入 next 節點後，更新其他尚未接入節點的距離
            for (int i = 0; i < n; ++i) {
                if (visited[i]) continue;
                minDist[i] = min(minDist[i], abs(points[i][0] - points[next][0]) + abs(points[i][1] - points[next][1]));
            }
        }
        
        return res;
    }
};
