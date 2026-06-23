class Solution {
public:
    unordered_map<string, int> dp;
    
    int solve(vector<int>& nums, int i, int lastVal) {
        if(i == nums.size()) return 0;
        
        string key = to_string(i) + "," + to_string(lastVal);
        if(dp.find(key) != dp.end()) return dp[key];
        
        // exclude
        int exclude = solve(nums, i + 1, lastVal);
        
        // include (only if nums[i] > lastVal)
        int include = 0;
        if(nums[i] > lastVal) {
            include = 1 + solve(nums, i + 1, nums[i]);
        }
        
        return dp[key] = max(include, exclude);
    }

    int lengthOfLIS(vector<int>& nums) {
        return solve(nums, 0, INT_MIN);
    }
};