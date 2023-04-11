class Solution {
public:
    string countAndSay(int n) {
        queue<char> q;
        q.push('1');
        while (--n) {
            char pre = q.front(); q.pop();
            int len = 1;
            int size = q.size();
            while (size--) {
                char c = q.front(); q.pop();
                if (pre == c) {
                    ++len;
                } else {
                    for (char t : to_string(len))  q.push(t);
                    q.push(pre);
                    pre = c;
                    len = 1;
                }
            }
            for (char t : to_string(len)) q.push(t);
            q.push(pre);
        }
        
        string res = "";
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
