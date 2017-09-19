class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0;
        int size = ratings.size();
        vector<int> candies(size, 1);
        
        for (int i = 0; i < size - 1; ++i) {
            if (ratings[i] < ratings[i + 1]) candies[i + 1] = candies[i] + 1;
        }
        for (int i = size - 1; i > 0; --i) {
            if (ratings[i - 1] > ratings[i]) candies[i - 1] = max(candies[i - 1], candies[i] + 1);
        }
        
        for (int c : candies) sum += c;
        return sum;
    }
};
