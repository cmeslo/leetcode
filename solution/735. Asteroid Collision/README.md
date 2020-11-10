# 735. Asteroid Collision

```cpp
vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> res;

    for (int i = 0; i < asteroids.size(); ++i) {
        if (res.empty() || res.back() < 0 || asteroids[i] > 0) {
            res.push_back(asteroids[i]);
        } else if (res.back() <= -asteroids[i]) {
            if (res.back() < -asteroids[i]) --i;
            res.pop_back();
        }
    }

    return res;
}
```
or

```cpp
vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> res;

    for (int a : asteroids) {
        while (!res.empty() && res.back() > 0 && res.back() < -a) {
            res.pop_back();
        }

        if (res.empty() || res.back() < 0 || a > 0) {
            res.push_back(a);
        } else if (res.back() == -a) {
            res.pop_back();
        }
    }

    return res;
}
```
