class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin(), candies.end()) - extraCandies;
        vector<bool> res;
        for (int x : candies)
            res.push_back(x >= mx);
        return res;
    }
};
