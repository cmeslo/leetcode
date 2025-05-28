class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for (string& log : logs) {
            if (log == "./") continue;
            res += log == "../" ? -1 : 1;
            res = max(res, 0);
        }
        return res;
    }
};
