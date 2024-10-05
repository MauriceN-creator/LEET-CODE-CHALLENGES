class Solution {
public:
    int helper(TreeNode* node, int &ans) {
        if (!node)
            return 0;
        int leftSum = max(0, helper(node->left, ans));
        int rightSum = max(0, helper(node->right, ans));
        ans = max(ans, node->val + leftSum + rightSum);
        return node->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};