class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()), r = 1e9, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (checkOK(weights, days, m))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
    
private:
    bool checkOK(vector<int>& weights, int days, int mx) {
        int w = 0;
        for (int x : weights) {
            if (w + x > mx) {
                if (--days <= 0) return false;
                w = 0;
            }
            w += x;
        }
        return true;
    }
};

//  ____________________
// |   |   |   |   |    |
//   1   6   8   9   10
//   2   7
//   3
//   4
//   5
