class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g = vector<vector<int>>(numCourses);
        vector<int> v = vector<int>(numCourses, 0); // 0 = unknow, 1 = visiting, 2 = visited
        
        for (const auto& pre : prerequisites)
            g[pre[1]].push_back(pre[0]);
        
        vector<int> ans;
        for (int i = 0; i < numCourses; i++) {
            if (dfs(i, ans, g, v)) return {};
        }
        
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
    
private:
    bool dfs(int node, vector<int>& ans, vector<vector<int>>& g, vector<int>& v) {
        if (v[node] == 1) return true; // cycle
        if (v[node] == 2) return false;
        
        v[node] = 1;
        for (int neighbour : g[node]) {
            if (dfs(neighbour, ans, g, v)) return true;
        }
        v[node] = 2;
        ans.push_back(node);
        
        return false;
    }
};
