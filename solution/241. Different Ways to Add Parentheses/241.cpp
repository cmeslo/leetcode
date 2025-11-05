class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res = dfs(expression, 0, expression.size() - 1);
        return res;
    }
    
private:
    vector<int> dfs(const string& E, int start, int end) {
        int i = start, num = 0;
        vector<int> res;
        for (int i = start; i <= end; ++i) {
            if (isdigit(E[i])) continue;
            
            auto L = dfs(E, start, i - 1);
            auto R = dfs(E, i + 1, end);
            for (auto& l : L)
                for (auto& r : R)
                    res.push_back(calc(l, r, E[i]));
        }
        if (res.empty())
            res.push_back(stoi(E.substr(start, end - start + 1)));
        return res;
    }
    
    int calc(int a, int b, char op) {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        return 0;
    }
};
