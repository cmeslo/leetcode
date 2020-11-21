class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0, n = seats.size(), last = -1;
        
        for (int i = 0; i < seats.size(); ++i) {
            if (seats[i] == 1) {
                res = last == -1 ? i : max(res, (i - last) / 2);
                last = i;
            }
        }
        res = max(res, n - last - 1);
        return res;
    }
};
