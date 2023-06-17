class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        vector<int> dist1(n, INF), dist2(n, INF);
        dfs(node1, edges, dist1, 0);
        dfs(node2, edges, dist2, 0);
        
        int res = -1, mn = INF;
        for (int i = 0; i < n; ++i) {
            if (dist1[i] == INF || dist2[i] == INF) continue;
            int d = max(dist1[i], dist2[i]);
            if (d < mn) {
                mn = d;
                res = i;
            }
        }
        return res;
    }
    
private:
    int INF = 1e9;
    
    void dfs(int node, vector<int>& E, vector<int>& dist, int d) {
        while (node != -1 && dist[node] == INF) {
            dist[node] = d++;
            node = E[node];
        }
    }
};
