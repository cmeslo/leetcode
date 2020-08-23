class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int& n = num_people;
        vector<int> ans(n, 0);
        
        for (int i = 0; candies > 0; candies -= ++i)
            ans[i % n] += min(candies, i + 1);
        
        return ans;
    }
};
