class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int max_distance = 0;
        
        for (int l = 0; l < n; ++l) {
            if (seats[l]) continue;
            
            int r = l;
            while (r + 1 < n && seats[r + 1] == 0)
                ++r;
            
            int distance = (l != 0 && r != n - 1) ? (r - l + 2) / 2 : r - l + 1;
            max_distance = max(max_distance, distance);
        }
        
        return max_distance;
    }
};
