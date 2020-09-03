class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        
        for (int i = 1; i <= n; ++i) {
            string tmp = "";
            if (i % 3 == 0) tmp.append("Fizz");
            if (i % 5 == 0) tmp.append("Buzz");
            if (!tmp.length()) tmp.append(to_string(i));
            ans[i-1] = tmp;
        }
        
        return ans;
    }
};
