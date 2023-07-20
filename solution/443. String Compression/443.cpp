class Solution {
public:
    int compress(vector<char>& chars) {
        vector<pair<char, int>> A;
        A.push_back({chars[0], 0});
        for (char& c : chars) {
            if (A.back().first == c)
                A.back().second++;
            else
                A.push_back({c, 1});
        }
        int i = 0;
        for (int j = 0; j < A.size(); ++j) {
            chars[i++] = A[j].first;
            if (A[j].second == 1) continue;
            string num = to_string(A[j].second);
            for (char& c : num)
                chars[i++] = c;
        }
        return i;
    }
};
