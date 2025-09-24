class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long total = accumulate(chalk.begin(), chalk.end(), 0L);
        k %= total;
        
        for (int i = 0; i < chalk.size(); ++i) {
            k -= chalk[i];
            if (k < 0)
                return i;
        }
        
        return -1;
    }
};
