class Solution {
public:
    int findMinDifference(vector<string>& T) {
        const int n = T.size();
        sort(T.begin(), T.end());
        
        int res = calc(T[0], T.back());
        res = min(res, 1440 - res); // 1440 = 24 * 60
        
        for (int i = 1; i < n; ++i) {
            int diff = calc(T[i - 1], T[i]);
            res = min(res, diff);
            res = min(res, 1440 - diff);
        }
        return res;
    }
    
private:
    int calc(string& a, string& b) {
        int h1 = stoi(a.substr(0, 2));
        int m1 = stoi(a.substr(3, 2));
        int h2 = stoi(b.substr(0, 2));
        int m2 = stoi(b.substr(3, 2));
        return (h2 - h1) * 60 + (m2 - m1);
    }
};
