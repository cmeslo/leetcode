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
