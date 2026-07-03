#include<cstring>
class Solution {
public:
    int dp[1010][1010];
    int solve(string s1, string s2, int i, int j) {
        if(i == s1.size()) return 0;
        if(j == s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;

        if(s1[i] == s2[j]) {
            ans = 1 + solve(s1, s2, i+1, j+1);
        } else {
            ans = max(solve(s1, s2, i+1, j), solve(s1, s2, i, j+1));
        }

        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return solve(text1, text2, 0, 0);
    }
};
