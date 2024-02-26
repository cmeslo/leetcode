class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int A = 0, B = 0;
        for (int i = 0; i < n; ++i) {
            int j = i;
            if (colors[i] == 'A') {
                while (j < n && colors[j] != 'B')
                    ++j;
                A += max(0, j - i - 2);
            } else {
                while (j < n && colors[j] != 'A')
                    ++j;
                B += max(0, j - i - 2);
            }
            i = j - 1;
        }
        return A > B;
    }
};
