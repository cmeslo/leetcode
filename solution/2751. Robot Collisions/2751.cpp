class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& P, vector<int>& H, string D) {
        const int n = P.size();
        
        vector<pair<int, int>> R(n);
        for (int i = 0; i < n; ++i)
            R[i] = {P[i], i};
        sort(R.begin(), R.end());
        
        stack<int> st;
        for (auto& [_, i] : R) {
            while (!st.empty() && D[st.top()] == 'R' && D[i] == 'L' && H[i]) {
                if (H[st.top()] == H[i]) {
                    H[i] = 0;
                    H[st.top()] = 0; st.pop();
                } else if (H[st.top()] < H[i]) {
                    H[i] -= 1;
                    H[st.top()] = 0; st.pop();
                } else if (H[st.top()] > H[i]) {
                    H[i] = 0;
                    H[st.top()] -= 1;
                }
            }
            if (H[i]) st.push(i);
        }
        
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (H[i] != 0)
                res.push_back(H[i]);
        }
        return res;
    }
};
