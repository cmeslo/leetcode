# 135. Candy

## 135_01.cpp

Straightforward, add candy with rating from low to high.
```
example:

1, 5, 3, 4, 7, 2

1, 1, 1, 1, 1, 1  
1, 1, 1, 1, 1 ,1 <== 2  
1, 1, 1, 1, 1 ,1 <== 3  
1, 1, 1, 2, 1 ,1 <== 4  
1, 2, 1, 2, 1 ,1 <== 5  
1, 2, 1, 2, 3 ,1 <== 7  
```

```cpp
int candy(vector<int>& ratings) {
    int n = ratings.size();

    vector<pair<int, int>> ratings_(n);
    for (int i = 0; i < n; ++i)
        ratings_[i] = {ratings[i], i};

    vector<int> ans(n);
    sort(begin(ratings_), end(ratings_));
    for (int i = 0; i < n; ++i) {
        auto [rating, index] = ratings_[i];
        ans[index] = max(ans[index], 1);
        if (index - 1 >= 0 && ratings[index - 1] > rating)
            ans[index - 1] = max(ans[index - 1], ans[index] + 1);
        if (index + 1 < n && ratings[index + 1] > rating)
            ans[index + 1] = max(ans[index + 1], ans[index] + 1);
    }

    return accumulate(begin(ans), end(ans), 0);
}
```

## 135_02.cpp

We travse 2 times, left-to-right and right-to-left.

example:

1, 5, 3, 4, 7, 2

1, 2, 1, 2, 3, 1 <== left-to-right  
1, 2, 1, 1, 2, 1 <== right-to-left  
1, 2, 1, 2, 3, 1 <== final
