class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (string& s : patterns) {
            auto it = word.find(s);
            if (it != string::npos)
                ++ans;
        }
        return ans;
    }
};
