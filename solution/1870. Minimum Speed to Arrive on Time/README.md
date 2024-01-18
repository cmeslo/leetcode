# 1870. Minimum Speed to Arrive on Time

## Solution: Binary search

### 寫法一：驗證時用加法

```cpp
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
```

### 寫法二：驗證時用減法, 要注意 ```1e-9```

```cpp
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        const int INF = 1e7 + 1;
        int l = 1, r = INF, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (checkOK(dist, hour, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l == INF ? -1 : l;
    }
    
    bool checkOK(vector<int>& dist, double hour, int speed) {
        for (int i = 0; i < dist.size() - 1; ++i) {
            hour -= (dist[i] + speed - 1) / speed;
            if (hour < 0)
                return false;
        }
        hour -= 1.0 * dist.back() / speed;
        return hour + 1e-9 >= 0;
    }
};
```
