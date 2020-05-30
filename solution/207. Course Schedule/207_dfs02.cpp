class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // construct tree
        _g = vector<vector<int>>(numCourses);
        _visited = vector<int>(numCourses, 0);
        for (const auto& pre : prerequisites) {
            _g[pre[1]].push_back(pre[0]);
        }
        
        // dfs
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) return false;
        }
        return true;
    }
    
private:
    vector<vector<int>> _g;
    vector<int> _visited; // 0: unknow, 1: visiting, 2: visited
    
    bool dfs(int node) {
        if (_visited[node] == 1) return false;
        if (_visited[node] == 2) return true;
        
        _visited[node] = 1;
        for (int next : _g[node]) {
            if (!dfs(next)) return false;
        }
        _visited[node] = 2;
        
        return true;
    }
};
