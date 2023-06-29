class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> b;
        int i, j;
        for (i = 0, j = 0; j < fruits.size(); ++j) {
            ++b[fruits[j]];
            if (b.size() > 2) {
                if (--b[fruits[i]] == 0)
                    b.erase(fruits[i]);
                ++i;
            }
        }
        return j - i;
    }
};

// x x x | x x x | x x
