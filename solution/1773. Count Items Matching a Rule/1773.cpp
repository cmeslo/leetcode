class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        for (auto& item : items) {
            if (ruleKey == "type")
                ans += item[0] == ruleValue ? 1 : 0;
            else if (ruleKey == "color")
                ans += item[1] == ruleValue ? 1 : 0;
            else if (ruleKey == "name")
                ans += item[2] == ruleValue ? 1 : 0;
        }
        return ans;
    }
};
