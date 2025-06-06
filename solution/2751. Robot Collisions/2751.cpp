class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& P, vector<int>& H, string D) {
        const int n = P.size();
        
        vector<int> idx(n);
        for (int i = 0; i < n; ++i)
            idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return P[a] < P[b];
        });
        
        stack<int> st;
        for (int i : idx) {
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
        for (int h : H) {
            if (h > 0)
                res.push_back(h);
        }
        return res;
    }
};
