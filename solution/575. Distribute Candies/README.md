# 575. Distribute Candies

```cpp
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> types;
        for (int type : candyType)
            types.insert(type);
        return min(types.size(), candyType.size() / 2);
    }
};
```
