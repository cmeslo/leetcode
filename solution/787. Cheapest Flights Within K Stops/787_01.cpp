class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

        int LIMIT = 100;
        graph = vector<unordered_set<int>>(LIMIT);
        cost = vector<vector<int>>(LIMIT, vector<int>(LIMIT, -1));
        min_price = INT_MAX;
        
        for (const vector<int>& f : flights) {
            graph[f[0]].insert(f[1]);
            cost[f[0]][f[1]] = f[2];
        }
        
        unordered_set<int> visited({src});
        
        dfs(src, dst, 0, K+1, visited);
        return min_price == INT_MAX ? -1: min_price;
    }
    
private:
    vector<unordered_set<int>> graph;
    vector<vector<int>> cost;
    int min_price;
    
    void dfs(int node, int dst, int curr_cost, int K, unordered_set<int>& visited) {
        if (K < 0) return;
        if (node == dst) {
            min_price = curr_cost;
            return;
        }
        
        for (int child : graph[node]) {
            int new_cost = curr_cost + cost[node][child];
            
            if (visited.count(child) || new_cost > min_price) continue;
            visited.insert(child);
            dfs(child, dst, new_cost, K-1, visited);
            visited.erase(child);
        }
    }
};
