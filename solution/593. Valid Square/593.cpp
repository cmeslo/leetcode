class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> dist(6);
        vector<vector<int>> points = {p1, p2, p3, p4};
        
        for (int i = 0, cnt = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                int x1 = points[i][0], x2 = points[j][0];
                int y1 = points[i][1], y2 = points[j][1];
                dist[cnt++] = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
            }
        }
        sort(begin(dist), end(dist));
        
        return dist[0] == dist[3] && dist[3] < dist[4] && dist[4] == dist[5];
    }
};
