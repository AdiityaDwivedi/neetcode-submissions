class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;

        bool left = isSameTree(p -> left, q -> left);
        bool right = isSameTree(p -> right, q -> right);

        return (p->val == q->val) && left && right;
    }
};
