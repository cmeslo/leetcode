class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9 + 7;
        
        vector<long> dp00(n+1), dp01(n+1), dp02(n+1), dp10(n+1), dp11(n+1), dp12(n+1);
        dp00[0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp00[i] = (dp00[i-1] + dp01[i-1] + dp02[i-1]) % MOD;
            dp01[i] = dp00[i-1];
            dp02[i] = dp01[i-1];
            dp10[i] = (dp00[i-1] + dp01[i-1] + dp02[i-1] + dp10[i-1] + dp11[i-1] + dp12[i-1]) % MOD;
            dp11[i] = dp10[i-1];
            dp12[i] = dp11[i-1];
        }
        
        return (dp00[n] + dp01[n] + dp02[n] + dp10[n] + dp11[n] + dp12[n]) % MOD;
    }
};

// dp00[i] := A 沒有出現過, ending with 0 L
// dp01[i] := A 沒有出現過, ending with 1 L
// dp02[i] := A 沒有出現過, ending with 2 L
// dp10[i] := A 出現過, ending with 0 L
// dp11[i] := A 出現過, ending with 1 L
// dp12[i] := A 出現過, ending with 2 L


// X X X L
