class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int left = 0, right = position.back() - position[0], mid;
        while (left < right) {
            mid = right - (right - left) / 2;
            if (checkOK(position, m, mid))
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
    
    bool checkOK(vector<int>& P, int m, int d) {
        if (m-- == 1) return true;
        int pre = P[0];
        for (int i = 1; i < P.size(); ++i) {
            if (P[i] - pre >= d) {
                if (--m == 0)
                    return true;
                pre = P[i];
            }
        }
        return false;
    }
};
