class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end(), cmp);
        std::sort(s.begin(), s.end(), cmp);
        
        int j = 0;
        for (int i = 0; i < g.size(); ++i) {
            if (j >= s.size()) break;
            if (s[j] >= g[i]) {
                j++;
            }
        }
        return j;
    }
    
    static bool cmp(const int& a, const int& b) {
        return a > b;
    }
};
