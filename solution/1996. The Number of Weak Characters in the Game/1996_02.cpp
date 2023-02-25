class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& P) {
        int n = P.size();
        sort(P.begin(), P.end(), [](auto& a, auto& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        int res = 0;
        stack<int> st;
        for (auto& p : P) {
            while (!st.empty() && st.top() < p[1]) {
                ++res;
                st.pop();
            }
            st.push(p[1]);
        }
        return res;
    }
};


// [1,5],[4,3],[4,2],[10,4]
