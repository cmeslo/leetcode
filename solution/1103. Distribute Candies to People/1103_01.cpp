class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        const int& n = num_people;
        vector<int> ans(n);
        
        int turns = 0;
        int sum = n * (1 + n) / 2;
        while (candies - sum > 0) {
            candies -= sum;
            sum += n * n;
            ++turns;
        }
        
        if (turns > 0) {
            for (int i = 0; i < n; i++) {
                ans[i] = i + 1;
                ans[i] = turns * (ans[i] + ans[i] + (turns-1) * n) / 2;
            }
        }
        
        int next = 1 + n * turns;
        int i = 0;
        while (candies > 0) {
            ans[i++] += (candies >= next ? next : candies);
            candies -= next;
            ++next;
        }
        
        return ans;
    }
};
