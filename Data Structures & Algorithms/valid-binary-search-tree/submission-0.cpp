class Solution {
public:
    bool solve(TreeNode* root, int min, int max) {
        if(root == NULL) return true;

        if(root -> val > min && root -> val < max) {
            bool left = solve(root -> left, min, root -> val);

            bool right = solve(root -> right, root -> val, max);

            return left && right;
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, INT_MIN, INT_MAX);
    }
};
