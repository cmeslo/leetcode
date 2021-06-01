class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        stack<int> dfs({0});
        vector<int> visited(n);
        ++visited[0];
        
        int remain = n - 1;
        while (!dfs.empty()) {
            int i = dfs.top(); dfs.pop();
            for (int key : rooms[i]) {
                if (visited[key]++) continue;
                dfs.push(key);
                if (--remain == 0) return true;
            }
        }
        
        return remain == 0;
    }
};
