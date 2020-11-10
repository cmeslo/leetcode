# 735. Asteroid Collision

關鍵是把情況列清楚

1. 以下情況直接入隊列：
```
......— .　隊列尾小行星的方向向左
....... ＋　新小行星的方向向右
```

2. 以下情況互相碰撞
```
......＋(大) —(小)　小的消失，不放入隊列
......＋(小) —(大)　小的消失，從隊列尾pop掉
```


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
