class Solution {
public:
    int height(TreeNode* root) {
        if(root == NULL) return 0;

        int left = height(root -> left);
        int right = height(root -> right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);

        int option3 = height(root->left) + height(root->right);

        return max(option3, max(option1, option2));
    }
};
