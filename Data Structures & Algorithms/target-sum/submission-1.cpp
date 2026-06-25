#include<cstring>
class Solution {
public:
    int dp[21][1001];
    int solve(vector<int>& nums, int idx, int current_sum, int target) {
        if (idx == nums.size()) {
            return current_sum == target ? 1 : 0;
        }
        if(dp[idx][current_sum] != -1) return dp[idx][current_sum];
        
        int plus = solve(nums, idx + 1, current_sum + nums[idx], target);
        
        int minus = solve(nums, idx + 1, current_sum - nums[idx], target);
        
        return dp[idx][current_sum] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0, target);
    }
    
};







