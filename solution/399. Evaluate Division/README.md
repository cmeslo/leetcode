# 399. Evaluate Division

## Solution 1: DFS

```cpp
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> g;
        
        for (int i = 0; i < equations.size(); ++i) {
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            const double k = values[i];
            g[A][B] = k;
            g[B][A] = 1.0 / k;
        }
        
        vector<double> ans;
        for (auto& query : queries) {
            const string& A = query[0];
            const string& B = query[1];
            if (!g.count(A) || !g.count(B)) {
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            ans.push_back(dfs(A, B, g, visited));
        }
        return ans;
    }
    
    double dfs(const string& A, const string& B, unordered_map<string, unordered_map<string, double>>& g, unordered_set<string>& visited) {
        if (A == B) return 1.0;
        if (g[A].find(B) != g[A].end()) return g[A][B];
        
        visited.insert(A);
        for (auto& neighbour : g[A]) {
            const string& C = neighbour.first;
            if (visited.find(C) != visited.end()) continue;
            double d = dfs(C, B, g, visited);
            if (d > 0) return g[A][C] * d;
        }
        
        return -1.0;
    }
};
```

or

```cpp
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> g;
        
        for (int i = 0; i < equations.size(); ++i) {
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            const double k = values[i];
            g[A][B] = k;
            g[B][A] = 1.0 / k;
            g[A][A] = g[B][B] = 1.0;
        }
        
        vector<double> ans;
        for (auto& query : queries) {
            const string& A = query[0];
            const string& B = query[1];
            unordered_set<string> visited;
            ans.push_back(dfs(A, B, g, visited));
        }
        return ans;
    }
    
    double dfs(const string& A, const string& B, unordered_map<string, unordered_map<string, double>>& g, unordered_set<string>& visited) {
        if (g[A].find(B) != g[A].end()) return g[A][B];
        
        visited.insert(A);
        for (auto& next : g[A]) {
            const string& C = next.first;
            if (visited.find(C) != visited.end()) continue;
            double d = dfs(C, B, g, visited);
            if (d > 0) return g[A][C] * d;
        }
        
        return -1.0;
    }
};
```

or

```cpp
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0], b = equations[i][1];
            double val = values[i];
            adj[a].push_back({b, val});
            adj[b].push_back({a, 1.0 / val});
        }
        
        vector<double> res;
        for (auto& q : queries) {
            seen.clear();
            double x = 1.0;
            res.push_back(dfs(q[0], q[1], x));
        }
        return res;
    }

private:
    unordered_map<string, vector<pair<string, double>>> adj;
    unordered_set<string> seen;
    
    double dfs(const string& node, const string& target, double x) {
        if (!adj.count(node) || !adj.count(target)) return -1.0;
        if (node == target) return 1.0;
        
        for (auto& [next, val] : adj[node]) {
            if (seen.count(next)) continue;
            if (next == target) return x * val;
            seen.insert(next);
            double tmp = dfs(next, target, x * val);
            if (tmp != -1.0)
                return tmp;
        }
        
        return -1.0;
    }
};
```

## Solution 2: Floyd's algorithm

```cpp
// Runtime: 0 ms, Your runtime beats 100.00 % of cpp submissions.
// Memory Usage: 8.2 MB, Your memory usage beats 75.83 % of cpp submissions.

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, int> m;
    int i = 0;
    for (auto& e : equations) {
        if (!m.count(e[0]))
            m[e[0]] = i++;
        if (!m.count(e[1]))
            m[e[1]] = i++;
    }

    int n = m.size();
    const double INF = 1000.0;
    vector<vector<double>> dist(n, vector<double>(n, INF));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 1.0;
    }

    for (int i = 0; i < equations.size(); ++i) {
        int a = m[equations[i][0]], b = m[equations[i][1]];
        dist[a][b] = values[i];
        dist[b][a] = 1.0 / values[i];
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] == INF || dist[k][j] == INF) continue;
                dist[i][j] = dist[i][k] * dist[k][j];
            }
        }
    }

    vector<double> ans;
    for (auto& q : queries) {
        if (!m.count(q[0]) || !m.count(q[1])) {
            ans.push_back(-1.0);
            continue;
        }
        int a = m[q[0]], b = m[q[1]];
        ans.push_back(dist[a][b] == INF ? -1.0 : dist[a][b]);
    }
    return ans;
}
```
