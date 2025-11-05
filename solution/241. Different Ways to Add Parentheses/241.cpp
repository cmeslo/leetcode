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
            if ('0' <= E[i] && E[i] <= '9') continue;
            auto L = dfs(E, start, i - 1);
            auto R = dfs(E, i + 1, end);
            if (E[i] == '+') {
                for (auto& l : L)
                    for (auto& r : R)
                        res.push_back(l + r);
            } else if (E[i] == '-') {
                for (auto& l : L)
                    for (auto& r : R)
                        res.push_back(l - r);
            } else if (E[i] == '*') {
                for (auto& l : L)
                    for (auto& r : R)
                        res.push_back(l * r);
            }
        }
        if (res.empty())
            res.push_back(stoi(E.substr(start, end - start + 1)));
        return res;
    }
};
