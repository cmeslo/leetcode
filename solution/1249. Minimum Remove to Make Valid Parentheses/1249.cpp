class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> left;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                left.push(i);
            else if (s[i] == ')') {
                if (!left.empty())
                    left.pop();
                else
                    s[i] = '*'; // 無法匹配的右括號，標記為 *
            }
        }

        while (!left.empty()) {
            s[left.top()] = '*'; // 無法匹配的左括號，標記為 *
            left.pop();
        }

        string ans;
        for (char& c : s)
            if (c != '*')
                ans += c;

        return ans;
    }
};
