class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        int n = target.size(), stars = 0;
        while (stars != n) {
            int i = chop(stamp, target);
            if (i == -1) return {};
            ans.push_back(i);
            for (int j = 0; j < stamp.size(); ++j) {
                if (target[i + j] == '*') continue;
                target[i + j] = '*';
                ++stars;
            }
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
    
private:
    int chop(string& stamp, string& target) {
        for (int i = 0; i + stamp.size() <= target.size(); ++i) {
            int matched = 0;
            int j;
            for (j = 0; j < stamp.size(); ++j) {
                if (target[i + j] == '*') continue;
                if (target[i + j] == stamp[j])
                    ++matched;
                else
                    break;
            }
            if (j == stamp.size() && matched) return i;
        }
        return -1;
    }
};
