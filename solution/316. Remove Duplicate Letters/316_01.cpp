// Your runtime beats 100.00 % of cpp submissions.

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> inStack(26, false);
        
        for (const char& c : s)
            ++count[c - 'a'];
        
        stack<char> st;
        for (const char& c : s) {
            --count[c - 'a'];
            if (inStack[c - 'a']) continue;
            
            while (!st.empty() && st.top() > c && count[st.top() - 'a'] > 0) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(c);
            inStack[c - 'a'] = true;
        }
        
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        return string(ans.rbegin(), ans.rend());
    }
};
