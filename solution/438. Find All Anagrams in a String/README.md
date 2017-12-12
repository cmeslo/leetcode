# 438. Find All Anagrams in a String

## TLE method:
```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> indices;
        if (s.empty() || p.size() > s.size()) return indices;
        
        std::sort(p.begin(), p.end());
        for (int i = 0; i <= s.size() - p.size(); ++i) {
            string sub = s.substr(i, p.size());
            std::sort(sub.begin(), sub.end());
            if (sub == p)  indices.push_back(i);
        }
        return indices;
    }
};
```

## 438_01.cpp
Use array to count letters of string p, and then check every p.size().


## 438_02.cpp
```cpp
for (int i = p.size(); i < s.size(); ++i) {
    --m1[s[i - p.size()] - 'a'];
    ++m1[s[i] - 'a'];
    if (m1 == m2) res.push_back(i - p.size() + 1);
}
```
Make m1 a fixed window of string s, move char by char.

## 438_03.cpp
Sliding window with left and right pointer
```cpp
int left = 0, right = 0, cnt = p.size();
while (right < s.size()) {
    //if m[right] > 0 after subtract, it means we got one char (cnt--). And right pointer move forward.
    if (m[s[right++] - 'a']-- > 0) cnt--;
    //if cnt == 0, got all char in p
    if (cnt == 0) res.push_back(left);
    //if m[left] >= 0 after subtract, means s[left] is one of the char in p (abandon it, we make cnt++). And left pointer move forward
    if (right - left == p.size() && m[s[left++] - 'a']++ >= 0) cnt++;
}
```
