class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int pre = 0, res = 0;
        for (auto& row : bank) {
            int cnt = count(row.begin(), row.end(), '1');
            res += cnt * pre;
            if (cnt != 0)
                pre = cnt;
        }
        return res;
    }
};
