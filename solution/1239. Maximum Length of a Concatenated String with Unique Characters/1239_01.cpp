class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<pair<int, int>> A; // {code, len}
        for (string& x : arr) {
            int code = 0;
            for (char& c : x) {
                int pos = 1 << (c - 'a');
                if ((code & pos) != 0) { // 如果自己本身已經有重複，則不考慮
                    code = 0;
                    break;
                }
                code |= pos;
            }
            if (code) A.push_back({code, x.length()});
        }
        
        int ans = 0;
        dfs(A, 0, 0, 0, ans);
        return ans;
    }
    
private:
    void dfs(vector<pair<int, int>> A, int start, int cur, int len, int& ans) {
        ans = max(ans, len);
        for (int i = start; i < A.size(); ++i) {
            if ((cur & A[i].first) == 0)
                dfs(A, i + 1, cur | A[i].first, len + A[i].second, ans);
        }
    }
};
