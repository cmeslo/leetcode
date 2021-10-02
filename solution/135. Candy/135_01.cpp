class Solution {
public:
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
};
