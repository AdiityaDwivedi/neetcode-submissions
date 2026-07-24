class Solution {
public:
    void solve(TreeNode* root, vector<int> &nums) {
        if(root == nullptr) return;

        solve(root -> left, nums);
        nums.push_back(root -> val);
        solve(root -> right, nums);

    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        solve(root, nums);

        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }

        for(int i = 0; i < k-1; i++) {
            pq.pop();
        }

        return pq.top();
    }
};
