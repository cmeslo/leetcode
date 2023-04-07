class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> f(26);
        for (char& c : sentence) {
            f[c - 'a']++;
        }
        for (int x : f) {
            if (x == 0)
                return false;
        }
        return true;
    }
};
