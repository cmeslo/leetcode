class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int l = 1, r = 1e7 + 1, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            double time = calc(dist, mid);
            if (time <= hour)
                r = mid;
            else
                l = mid + 1;
        }
        return l == 1e7 + 1 ? -1 : l;
    }
    
private:
    double calc(vector<int>& dist, int speed) {
        double time = 0;
        int n = dist.size();
        for (int i = 0; i < n - 1; ++i) {
            time += (dist[i] + speed - 1) / speed;
        }
        time += (double) dist[n - 1] / speed;
        return time;
    }
};
