class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long l = 0, r = (long)*min_element(time.begin(), time.end()) * totalTrips;
        while (l < r) {
            long mid = l + (r - l) / 2;
            long trips = count(time, mid);
            if (trips < totalTrips)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    
    long count(vector<int>& time, long t) {
        long trips = 0;
        for (int x : time) {
            trips += t / x;
        }
        return trips;
    }
};
