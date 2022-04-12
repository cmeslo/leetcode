# 2187. Minimum Time to Complete Trips

## Solution: Binary search

### C++

由於 Constraints: ```1 <= time[i], totalTrips <= 10^7```

所以右邊界也可以直接用 ```1e14```

```cpp
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long l = 0, r = (long)*min_element(time.begin(), time.end()) * totalTrips; // 也可以用 r = 1e14
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
```

### Python

```py
def minimumTime(self, time, totalTrips):
    """
    :type time: List[int]
    :type totalTrips: int
    :rtype: int
    """
    def count(t):
        res = 0
        for x in time:
            res = res + (t // x)
        return res

    l, r = 0, 10**14
    while l < r:
        mid = (l + r) // 2
        trips = count(mid)
        if trips < totalTrips:
            l = mid + 1
        else:
            r = mid
    return l
```
