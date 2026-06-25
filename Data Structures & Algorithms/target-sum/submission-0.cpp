class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, 0, target);
    }
    
private:
    int solve(vector<int>& nums, int idx, int current_sum, int target) {
        if (idx == nums.size()) {
            return current_sum == target ? 1 : 0;
        }
        
        int plus = solve(nums, idx + 1, current_sum + nums[idx], target);
        
        int minus = solve(nums, idx + 1, current_sum - nums[idx], target);
        
        return plus + minus;
    }
};