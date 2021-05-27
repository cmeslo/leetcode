# 478. Generate Random Point in a Circle

## Solution 1 - 拒絕採樣 Rejection Sampling

```cpp
class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        r_ = radius;
        x_ = x_center;
        y_ = y_center;
    }
    
    vector<double> randPoint() {
        double x, y;
        do {
            double f1 = (double) rand() / RAND_MAX;
            x = f1 * (r_ + r_) - r_;
            double f2 = (double) rand() / RAND_MAX;
            y = f2 * (r_ + r_) - r_;
        } while (x * x + y * y > r_ * r_);
        
        return {x_ + x, y_ + y};
    }
    
private:
    double x_, y_;
    double r_;
};
```
