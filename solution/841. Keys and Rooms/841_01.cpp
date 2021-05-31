class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n);
        
        int remain = n - 1;
        queue<int> q({0});
        ++visited[0];
        while (!q.empty()) {
            int i = q.front(); q.pop();
            for (int key : rooms[i]) {
                if (visited[key]++) continue;
                if (--remain == 0) return true;
                q.push(key);
            }
        }
        return remain == 0;
    }
};
