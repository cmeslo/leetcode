class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        dfs(arr, 0, 0, 0, ans);
        return ans;
    }
    
private:
    void dfs(vector<string>& arr, int start, int curMask, int len, int& ans) {
        ans = max(ans, len);
        for (int i = start; i < arr.size(); ++i) {
            int mask = concat(curMask, arr[i]);
            if (mask != -1)
                dfs(arr, i + 1, mask, len + arr[i].length(), ans);
        }
    }
    
    int concat(int mask, const string& str) {
        for (const char& c : str) {
            int pos = 1 << (c - 'a');
            if ((mask & pos) != 0) return -1;
            mask |= pos;
        }
        return mask;
    }
};
