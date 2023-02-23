class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& P) {
        int n = P.size();
        sort(P.begin(), P.end(), [](auto& a, auto& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        int res = 0;
        int mx = INT_MIN;
        for (auto& p : P) {
            if (mx > p[1])
                ++res;
            mx = max(mx, p[1]);
        }
        return res;
    }
};



// [10,4],[4,3],[1,5]

// [10,4],[4,3],[4,2],[1,5]

// [10,4],[4,2],[4,3],[1,5]
