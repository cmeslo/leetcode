class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& M) {
        using pli = pair<long, int>; // {end_time, room_number}
        sort(M.begin(), M.end());
        
        map<int, int> freq;
        int mxFreq = 0;
        
        set<int> freeRoom;
        for (int i = 0; i < n; ++i)
            freeRoom.insert(i);

        priority_queue<pli, vector<pli>, greater<>> pq;
        for (auto& m : M) {
            while (!pq.empty() && pq.top().first <= m[0]) {
                auto [endTime, room] = pq.top(); pq.pop();
                freeRoom.insert(room);
            }
            if (pq.size() < n) {
                auto it = freeRoom.begin();
                int room = *it;
                pq.push({m[1], room});
                freeRoom.erase(it);
                mxFreq = max(mxFreq, ++freq[room]);
            } else {
                auto [endTime, room] = pq.top(); pq.pop();
                pq.push({endTime + (m[1] - m[0]), room});
                mxFreq = max(mxFreq, ++freq[room]);
            }
        }
        
        for (auto& [room, cnt] : freq) {
            if (cnt == mxFreq)
                return room;
        }
        return 0;
    }
};
