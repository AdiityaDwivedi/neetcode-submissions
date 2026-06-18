#include<cstring>

class Solution {
public:
    int dp[101];
    int solve(vector<int> &cost, int n) {
        if(n == 1 || n == 0) return 0;
        if(dp[n] != -1) return dp[n];

        int ans1 = cost[n-1] + solve(cost, n-1);
        int ans2 = cost[n-2] + solve(cost, n-2);

        return dp[n] = min(ans1, ans2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        int n = cost.size();
        return solve(cost, n);
    }
};
