class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        
        int j = 0;
        for (int i = 0; i < s.size() && j < g.size(); ++i) {
            if (s[i] >= g[j]) j++;
        }
        return j;
    }
};
