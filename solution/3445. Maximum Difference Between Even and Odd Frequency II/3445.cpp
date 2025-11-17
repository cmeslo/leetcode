class Solution {
public:
    int maxDifference(string s, int k) {
        const int inf = INT_MAX / 2;
        int res = -inf;
        for (int x = 0; x < 5; ++x) {
            for (int y = 0; y < 5; ++y) {
                if (x == y) continue;

                int cur_s[5] = {}, pre_s[5] = {};
                int min_s[2][2] = {{inf, inf}, {inf, inf}};
                int l = 0;
                for (int i = 0; i < s.size(); ++i) {
                    cur_s[s[i] - '0']++;
                    int r = i + 1;
                    while (r - l >= k && cur_s[x] > pre_s[x] && cur_s[y] > pre_s[y]) {
                        int& p = min_s[pre_s[x] & 1][pre_s[y] & 1];
                        p = min(p, pre_s[x] - pre_s[y]);
                        pre_s[s[l] - '0']++;
                        l++;
                    }
                    res = max(res, cur_s[x] - cur_s[y] - min_s[cur_s[x] & 1 ^ 1][cur_s[y] & 1]);
                }
            }
        }
        return res;
    }
};

// x: odd, y: even

// . . . l [. . . r] . .

// (sum[r][x] - sum[l][x]) - (sum[r][y] - sum[l][y])
// (sum[r][x] - sum[r][y]) - (sum[l][x] - sum[l][y])
//                                0           0
//                                0           1
//                                1           0
//                                1           1
//                                p           q

// 1. r - l >= k
// 2. sum[r][x] >= sum[l][x]
// 3. sum[r][y] >= sum[l][y]

// sum[r][x] 與 sum[l][x] 的奇偶性要不同
// sum[r][y] 與 sum[l][y] 的奇偶性要相同

// minS[p][q] = minS[sum[r][x] & 1 ^ 1][sum[r][y] & 1]

// (sum[r][x] - sum[r][y]) - minS[p][q]
