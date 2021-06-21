# 936. Stamping The Sequence

## 解釋

逆向思維 (reverse processing)

例子：```stamp = "abc", target = "ababc"```

```
*******
abca***
...abca
.abca..
aabcaca
```
從上而下蓋印，嘗試從下以上恢復，每次迭代都要從左至右掃一次，
```
aabcaca <--找到abca，index = 1
a****ca <--找到a***，index = 0
*****ca <--找到****，忽略
*****ca <--找到**ca，index = 3
*******
```
答案就是```[3,0,1]```。

## Code

### version 1

```cpp
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        int n = target.size(), stars = 0;
        while (stars != n) {
            int i = chop(stamp, target);
            if (i == -1) return {};
            ans.push_back(i);
            for (int j = 0; j < stamp.size(); ++j) {
                if (target[i + j] == '*') continue;
                target[i + j] = '*';
                ++stars;
            }
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
    
private:
    int chop(string& stamp, string& target) {
        for (int i = 0; i + stamp.size() <= target.size(); ++i) {
            int matched = 0;
            int j;
            for (j = 0; j < stamp.size(); ++j) {
                if (target[i + j] == '*') continue;
                if (target[i + j] == stamp[j])
                    ++matched;
                else
                    break;
            }
            if (j == stamp.size() && matched) return i;
        }
        return -1;
    }
};
```

### version 2

增加seen作優化，忽略已處理的index。

```
#號代表seen

aabcaca <--找到abca，index = 1
a#***ca <--找到a***，index = 0
##***ca <--找到****，忽略
##*#*ca <--找到**ca，index = 3
##*#***
```



```cpp
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size();
        vector<int> ans;
        vector<int> seen(n);
        int total = 0;
        
        while (total < n) {
            bool found = false;
            for (int i = 0; i <= n - stamp.size(); ++i) {
                if (seen[i]) continue;
                int len = unStamp(stamp, target, i);
                if (len == 0) continue;
                seen[i] = 1;
                total += len;
                ans.push_back(i);
                found = true;
            }
            if (!found) return {};
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
    
private:
    int unStamp(const string& stamp, string& target, int s) {
        int len = stamp.size();
        for (int i = 0; i < stamp.size(); ++i) {
            if (target[s + i] == '*')
                --len;
            else if (target[s + i] != stamp[i])
                return 0;
        }
        if (len != 0)
            std::fill(begin(target) + s, begin(target) + s + stamp.size(), '*');
        return len;
    }
};
```

reference: https://zxi.mytechroad.com/blog/greedy/leetcode-936-stamping-the-sequence/
