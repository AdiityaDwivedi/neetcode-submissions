#include<cstring>

class Solution {
    static const int N = 10010;
    int dp[N];
public:
    int func(int amount, vector<int> &coins) {
        //base case
        if(amount == 0) return 0;
        int ans = INT_MAX;
        if(dp[amount] != -1) return dp[amount];

        for(int coin : coins) {
            if(amount - coin >= 0) {
                int res = func(amount - coin, coins);
                if (res != INT_MAX) {
                    ans = min(ans + 0LL, res + 1LL);
                }
            }
        }
        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = func(amount, coins);
        return ans == INT_MAX ? -1 : ans;
    }
};