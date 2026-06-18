#include<cstring>

class Solution {
public:
    int dp[46];
    int solve(int n, int index) {
        if(index >= n) return index == n;
        if(dp[index] != -1) return dp[index];

        int ans1 = solve(n, index+1);
        int ans2 = solve(n, index+2);

        return dp[index] = ans1 + ans2;
    }

    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 0);
    }
};
