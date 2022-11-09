class Solution {
private:
    int father[1001];
    
    int FindFather(int i) {
        if (father[i] != i)
            father[i] = FindFather(father[i]);
        return father[i];
    }
    
    void Union(int i, int j) {
        i = FindFather(i);
        j = FindFather(j);
        if (i < j)
            father[j] = i;
        else
            father[i] = j;
    }
    
public:
    // kruskal's algorithm
    int minCostConnectPoints(vector<vector<int>>& points) {
        using a3 = array<int, 3>;
        int n = points.size();
        if (n == 1) return 0;
        
        for (int i = 0; i < n; ++i)
            father[i] = i;
        
        vector<a3> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }
        
        priority_queue<a3, vector<a3>, greater<>> pq(edges.begin(), edges.end());
        int res = 0;
        int count = 0;
        while (!pq.empty()) {
            auto e = pq.top(); pq.pop();
            int d = e[0], i = e[1], j = e[2];
            if (FindFather(i) != FindFather(j)) {
                Union(i, j);
                res += d;
                if (++count == n - 1) return res;
            }
        }
        return -1;
    }
};
