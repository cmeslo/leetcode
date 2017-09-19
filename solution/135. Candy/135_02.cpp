class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0;
        int size = ratings.size();
        vector<int> candys(size, 1);
        
        for (int i = 0; i < size - 1; ++i) {
            if (ratings[i] < ratings[i + 1]) candys[i + 1] = candys[i] + 1;
        }
        for (int i = size - 1; i > 0; --i) {
            if (ratings[i - 1] > ratings[i]) candys[i - 1] = max(candys[i - 1], candys[i] + 1);
        }
        
        for (int c : candys) sum += c;
        return sum;
    }
};
