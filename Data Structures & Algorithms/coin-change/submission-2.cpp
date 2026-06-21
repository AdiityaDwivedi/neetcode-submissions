#include<cstring>
class Solution {
public:
    int dp[10010];
    int solve(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int ans = INT_MAX;
        if(dp[amount] != -1) return dp[amount];

        for(int coin : coins) {
            if(amount - coin >= 0) {
                int res = solve(coins, amount - coin);
                if(res != INT_MAX)
                    ans = min(ans, 1 + res);
            }
        }

        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};