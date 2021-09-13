class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        
        auto cmp = [&](int i, int j) {
            return stations[i][1] < stations[j][1];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int ans = 0;
        int cur = 0, fuel = startFuel;
        int i = 0;
        while (cur + fuel < target) {
            while (i < n && cur + fuel >= stations[i][0])
                pq.push(i++);
            if (pq.empty()) break;
            int index = pq.top(); pq.pop();
            fuel = fuel - (stations[index][0] - cur) + stations[index][1];
            cur = stations[index][0];
            ++ans;
        }
        return cur + fuel >= target ? ans : -1;
    }
};
