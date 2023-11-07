class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0, r = n, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (letters[m] <= target)
                l = m + 1;
            else
                r = m;
        }
        return l == n ? letters[0] : letters[l];
    }
};
