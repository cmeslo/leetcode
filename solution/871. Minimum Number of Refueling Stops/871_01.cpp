class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int ans = 0, cur = startFuel, i = 0;
        
        while (cur < target) {
            while (i < stations.size() && cur >= stations[i][0])
                pq.push(stations[i++][1]);
            if (pq.empty()) return -1;
            cur += pq.top(), pq.pop();
            ++ans;
        }
        
        return ans;
    }
};
