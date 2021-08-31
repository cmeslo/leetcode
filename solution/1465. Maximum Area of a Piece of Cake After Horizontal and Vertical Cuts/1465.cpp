class Solution {
public:
    int maxArea(int h, int w, vector<int>& H, vector<int>& V) {
        sort(begin(H), end(H));
        sort(begin(V), end(V));
        
        int maxgap_w = max(H[0], h - H.back());
        for (int i = 1; i < H.size(); ++i)
            maxgap_w = max(maxgap_w, H[i] - H[i - 1]);
        
        int maxgap_h = max(V[0], w - V.back());
        for (int i = 1; i < V.size(); ++i)
            maxgap_h = max(maxgap_h, V[i] - V[i - 1]);
        
        return (long) maxgap_w * maxgap_h % 1000000007;
    }
};
